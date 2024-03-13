<?php
define("GALLERY_DIRECTORY_PATH", "/path/to/gallery2/");
require_once(GALLERY_DIRECTORY_PATH . "embed.php");
require_once(GALLERY_DIRECTORY_PATH . "modules/core/classes/GalleryCoreApi.class");
require_once(GALLERY_DIRECTORY_PATH . "modules/core/classes/GalleryEmbed.class");

class Gallery2
{
	function Gallery2()
	{
	}

	function operatorList()
	{
		return array("gallery2");
	}

	/*!
	\return true to tell the template engine that the parameter list exists per operator type,
	this is needed for operator classes that have multiple operators.
	*/
	function namedParameterPerOperator()
	{
		return array('gallery2' => "");
	}

	/*!
	See eZTemplateOperator::namedParameterList
	*/
	function namedParameterList()
	{
		return array(
			"gallery2" => array(
					"albumID" => array(
						"type" => "string",
						"required" => true,
						"default" => "")
					)
            		);
	}

	function modify(&$tpl, &$operatorName, &$operatorParameters, &$rootNamespace, &$currentNamespace, &$operatorValue, &$namedParameters)
	{
		$albumID = $namedParameters["albumID"];

		switch ($operatorName) {
		case "gallery2":
			$operatorValue = $this->fetchAlbumItems($albumID);
			break;
		}
	}

	function fetchAlbumItems($albumID)
	{
		$albumItems = array();

		// Initialize the Gallery embed API with the "guest" user
		$error = GalleryEmbed::init(array("baseUri" => "/gallery2/", "activeUserId" => "", "g2Uri" => "/gallery2/"));
		if ($error) {
			return "ERROR:  Could not initialize Gallery<br />" . $ret->getAsHtml();
		}

		// Fire up the Gallery API and check to make sure it hasn't sent
    		// headers already
		$g2data = GalleryEmbed::handleRequest();
		if ($g2data["isDone"]) {
			return "ERROR:  Gallery2 is reporting the request has already been processed.\n";
		}

		list($error, $rootAlbum) = GalleryCoreApi::loadEntitiesById($albumID);
		if ($error) {
			return "ERROR:  Could not fetch album information\n" . $error;
		}

    		// Load all album items
    		list($error, $childDataItemIDs) = GalleryCoreApi::fetchChildDataItemIds($rootAlbum);
    		if ($error) {
	   		return "ERROR:  Could not fetch album child item IDs\n" . $error;
    		}

    		// Load the children objects
		list($error, $children) = GalleryCoreApi::loadEntitiesById($childDataItemIDs);
    		if ($error) {
	   		return "ERROR:  Could not fetch album items\n" . $error;
    		}

    		// Load the children derivatives
    		list($error, $derivatives) = GalleryCoreApi::fetchDerivativesByItemIds($childDataItemIDs);
    		if ($error) {
			return "ERROR:  Could not fetch derivatives\n" . $error;
    		}

		// Now, we iterate over the children For each child, we check its
		// derivatives to find the thumbnail and a scaled version.  If no
		// scaled version exists, use the original.
		foreach ($children as $child) {
			$childID = $child->getID();
			$serialNumber = $child->getSerialNumber();
			$pathComponent = $child->getPathComponent();
			$title = $child->getTitle();

			// Iterate over the derivatives for the child
			foreach ($derivatives[$childID] as $derivative) {
				// Thumbnail
				if (preg_match("/thumbnail/", $derivative->getDerivativeOperations()) == 1) {
					$thumbID = $derivative->getId();
					$thumbSerial = $derivative->getSerialNumber();
					$thumbWidth = $derivative->getWidth();
					$thumbHeight = $derivative->getHeight();
				} else if (preg_match("/scale/", $derivative->getDerivativeOperations()) == 1) {
					$serialNumber = $derivative->getSerialNumber();
					$childID = $derivative->getId();
				}
			}

			$html = <<<EOL
<a href="/gallery2/d/$childID-$serialNumber/$pathComponent" rel="lightbox[galleryEmbed]" title="$title"><img src="/gallery2/d/$thumbID-$thumbSerial/$pathComponent" width="$thumbWidth" height="$thumbHeight" alt="$title" /></a>
EOL;

			$albumItems[] = $html;
    		}


    		return $albumItems;
	}
}
?>

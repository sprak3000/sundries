<?php
$id = 50;

$galleryPath = "../gallery2/";
require_once($galleryPath . 'embed.php');
require_once($galleryPath . 'modules/core/classes/GalleryCoreApi.class');
require_once($galleryPath . 'modules/core/classes/GalleryEmbed.class');

// Initialize the Gallery embed API with the "guest" user
$error = GalleryEmbed::init(array("baseUri" => "/gallery2/", "activeUserId" => "", "g2Uri" => "/gallery2/"));
if ($error) {
	exit("Could not initialize Gallery\n" . $ret->getAsHtml() . "</pre>");
}

// Fire up the Gallery API and check to make sure it hasn't sent
// headers already
$g2data = GalleryEmbed::handleRequest();
if ($g2data['isDone']) {
	exit("Done?\n</pre>");
}

list($error, $rootAlbum) = GalleryCoreApi::loadEntitiesById($id);
if ($error) {
	print("Could not fetch album information\n");
	print_r($error);
	exit("</pre>");
}

// Load all album items
list($error, $childDataItemIDs) = GalleryCoreApi::fetchChildDataItemIds($rootAlbum);
if ($error) {
	print("Could not fetch album child item IDs\n");
	print_r($error);
	exit("</pre>");
}

list($error, $children) = GalleryCoreApi::loadEntitiesById($childDataItemIDs);
if ($error) {
	print("Could not fetch album items\n");
	print_r($error);
	exit("</pre>");
}

// URL to view page seems to be /v/<album path, e.g., toys/lupinthethird/ps2bonus>/<title>.html
// Photo URL seems to be /d/<item id>-<item serial #>/<path component>
?>
<?php
foreach ($children as $child) {
	list($error, $imageBlock) = GalleryEmbed::getImageBlock(array("blocks" => "specificItem", "itemId" => $child->getId(), "show" => "title|fullSize"));
	if ($error) {
		print("Error getting image block<pre>");
		print_r($error);
		print("</pre>");
	}
	print($imageBlock);
}
?>

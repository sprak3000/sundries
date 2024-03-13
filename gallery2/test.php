<pre>

<?php
$galleryPath = "../gallery2/";
require_once($galleryPath . 'embed.php');
require_once($galleryPath . 'modules/core/classes/GalleryCoreApi.class');
require_once($galleryPath . 'modules/core/classes/GalleryEmbed.class');

// Initialize the Gallery embed API with the "guest" user
$error = GalleryEmbed::init(array("activeUserId" => ""));
if ($error) {
	exit("Could not initialize Gallery\n" . $ret->getAsHtml() . "</pre>");
}

// Fire up the Gallery API and check to make sure it hasn't sent
// headers already
$g2data = GalleryEmbed::handleRequest();
if ($g2data['isDone']) {
	exit("Done?\n</pre>");
}

// Fetch the entire Gallery album tree structure
list($error, $tree) = GalleryCoreApi::fetchAlbumTree();
if ($error) {
	print("Error fetching Gallery tree structure\n");
	print_r($error);
	exit("</pre>");
}

// Something amiss if our Gallery album tree is empty
if (empty($tree)) {
	exit("Gallery tree structure empty");
}

print("\n=======================\n");
print_r($tree);
print("\n=======================\n");

// Get the root album information
list($error, $rootAlbumID) = GalleryCoreApi::getPluginParameter('module', 'core', 'id.rootAlbum');
if ($error) {
	print("Could not fetch root album ID\n");
	print_r($error);
	exit("</pre>");
}

print("\n====== root Album ID " . $rootAlbumID . " ======\n");

list($error, $rootAlbum) = GalleryCoreApi::loadEntitiesById($rootAlbumID);
if ($error) {
	print("Could not fetch root album information\n");
	print_r($error);
	exit("</pre>");
}

print_r($rootAlbum);

// Load all album items
list($error, $items) = GalleryCoreApi::loadEntitiesById(GalleryUtilities::arrayKeysRecursive($tree));
if ($error) {
	print("Could not fetch all album items\n");
	print_r($error);
	exit("</pre>");
}

foreach ($items as $item) {
	print("\n=======================\n");
	print_r($item);

	// Fetch child data IDs, only photos
//	list($error, $childDataItemIDs) = GalleryCoreApi::fetchChildDataItemIds($item);
//	if ($error) {
//		print("Could not fetch child data item IDs\n");
//		print_r($error);
//		exit("</pre>");
//	}

//	foreach ($childDataItemIDs as $childDataItemID) {
//		print("\n-----------------\n");
//		list($error, $child) = GalleryCoreApi::loadEntitiesById($childDataItemID);
//		if ($error) {
//			print("Could not fetch child data\n");
//			print_r($error);
//			exit("</pre>");
//		}
//		print_r($child);
//		print_r(GalleryCoreApi::fetchDerivativesByItemIds(array($child->getId())));
//		print("\n-----------------\n");
//	}

	print("\n=======================\n");
}

// Photo URL seems to be /d/<item id>-<item serial #>/<filename>
?>

</pre>

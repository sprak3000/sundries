{def $albumItems=gallery2($album_id)}
{if $albumItems|is_array()}
<div class="object-left class-gallery">
	{foreach $albumItems as $albumItem}
	<div class="content-view-galleryline">{$albumItem}</div>
	{/foreach}
</div>
    {if $no_js|null()}
<script type="text/javascript" src="/extension/ezwebin/design/ezwebin/javascript/jquery-1.2.1.min.js"></script>
<script type="text/javascript" src="/extension/ezwebin/design/ezwebin/javascript/jquery.lightbox-0.3.js"></script>
        {literal}
<script type="text/javascript">$(function() { $('a[@rel*=lightbox]').lightBox(); });</script>
        {/literal}
    {/if}
{/if}

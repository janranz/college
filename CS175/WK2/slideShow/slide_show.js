var $ = function (id) { 
	return document.getElementById(id); 
}
window.onload = function () {
    var slidesNode = $("slides");    
    var captionNode = $("caption");
    var imageNode = $("slide");
        
    var slides = slidesNode.getElementsByTagName("img");
    var image, imageCounter = 0;
    $("next").onclick = function()
    {
        imageCounter = (imageCounter + 1) % slides.length;
        console.log("Index: ",imageCounter);
        image = slides[imageCounter];
        imageNode.src = image.src;
        captionNode.firstChild.nodeValue = image.alt;
    };
    $("previous").onclick = function()
    {
        imageCounter = (imageCounter - 1 + slides.length) % slides.length;
        console.log("Index: ",imageCounter);
        image = slides[imageCounter];
        imageNode.src = image.src;
        captionNode.firstChild.nodeValue = image.alt;
    };
}

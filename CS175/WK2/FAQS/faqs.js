"use strict";
var $ = function (id) { return document.getElementById(id); };

// the event handler for the click event of each h2 element
var toggle = function () {
    var aTag = this;                    // clicked h2 tag     
    var div = aTag.parentNode.nextElementSibling;  // h2 tag's sibling div tag
    var pops = aTag.parentNode;
    // toggle plus and minus image in h2 elements by adding or removing a class
    if (pops.hasAttribute("class")) { 
        pops.removeAttribute("class");	
    } else { 
        pops.setAttribute("class", "minus"); 
    }

    // toggle div visibility by adding or removing a class
    if (div.hasAttribute("class")) { 
        div.removeAttribute("class");
    } else { 
        div.setAttribute("class", "open"); 
    } 
};

window.onload = function () {
    // get the h2 tags
    var faqs = $("faqs");
    var aTagElements = faqs.getElementsByTagName("a");
    
    // attach event handler for each h2 tag	    
    for (var i = 0; i < aTagElements.length; i++ ) {
    	aTagElements[i].onclick = toggle;
    }
    // set focus on first h2 tag's <a> tag
    aTagElements[0].focus();       
};

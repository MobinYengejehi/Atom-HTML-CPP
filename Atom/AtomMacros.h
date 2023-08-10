/*****************************************************************************
 *
 *  PROJECT:     Atom HTML Graphics Library for `C & CPP`
 *               (https://github.com/MobinYengejehi/Atom-HTML-CPP)
 *  LICENSE:     See LICENSE in the top level directory
 *  FILE:        AtomMacros.h
 *
 *  AUTHOR:      MobinYengejehi
 *  GITHUB:      https://github.com/MobinYengejehi
 *
 *****************************************************************************/

#pragma once

#ifndef ATOM_MACROS
#define ATOM_MACROS

#include "AtomElementOptions.h"

#define Element AtomElement("", false, true, false) = 
#define SvgElement AtomElement("", "http://www.w3.org/2000/svg", false, true, false) = 

#define Namespace AtomElementOptionNamespace() = 
#define Node AtomElementOptionNodeName() = 

#define Id AtomElementOptionId() = 
#define Class AtomElementOptionClassName() = 

#define Attribute AtomElementOptionAttribute() = std::vector<std::string>
#define Property AtomElementOptionProperty() = std::vector<std::string>

#define TextContent AtomElementOptionTextContent() = 

#define Event AtomElementOptionEvent() = 

#define Lockable AtomElementOptionLockable(true)
#define KeepAlive AtomElementOptionKeepAlive(true)
#define SetLockable AtomElementOptionLockable() = 
#define SetKeepAlive AtomElementOptionKeepAlive() = 

#define ElementReference AtomElementOptionReference() = 

#define InnerContent AtomElementOptionInnerHTML() = 

#define BreakLine Element { Node "br" }

#define Style AtomElementStylePropertyList() = 

#define Src AtomElementOptionAttribute("src", false) = 
#define Href AtomElementOptionAttribute("href", false) = 
#define Type AtomElementOptionAttribute("type", false) = 
#define Alt AtomElementOptionAttribute("alt", false) = 
#define Name AtomElementOptionAttribute("name", false) = 
#define Target AtomElementOptionAttribute("target", false) = 
#define PlaceHolder AtomElementOptionAttribute("placeholder", false) = 
#define AutoComplete AtomElementOptionAttribute("autocomplete", false) = 
#define AutoCapitalize AtomElementOptionAttribute("autocapitalize", false) = 
#define Align AtomElementOptionAttribute("align", false) = 
#define Value AtomElementOptionAttribute("value", false) = 

#define SvgViewBox AtomElementOptionAttribute("viewBox", false) = 
#define SvgWidth AtomElementOptionAttribute("width", false) = 
#define SvgHeight AtomElementOptionAttribute("height", false) = 
#define SvgFill AtomElementOptionAttribute("fill", false) = 
#define SvgStroke AtomElementOptionAttribute("stroke", false) = 
#define SvgXmlNs AtomElementOptionAttribute("xmlns", false) = 
#define SvgD AtomElementOptionAttribute("d", false) = 

// Events
#define OnAbort AtomElementOptionEvent("abort") = 
#define OnAnimationCancel AtomElementOptionEvent("animationcancel") = 
#define OnAnimationEnd AtomElementOptionEvent("animationend") = 
#define OnAnimationIteration AtomElementOptionEvent("animationiteration") = 
#define OnAnimationStart AtomElementOptionEvent("animationstart") = 
#define OnAuxClick AtomElementOptionEvent("auxclick") = 
#define OnBeforeInput AtomElementOptionEvent("beforeinput") = 
#define OnBlur AtomElementOptionEvent("blur") = 
#define OnCancel AtomElementOptionEvent("cancel") = 
#define OnCanPlay AtomElementOptionEvent("canplay") = 
#define OnCanPlayThrough AtomElementOptionEvent("canplaythrough") = 
#define OnChange AtomElementOptionEvent("change") = 
#define OnClick AtomElementOptionEvent("click") = 
#define OnClose AtomElementOptionEvent("close") = 
#define OnContextMenu AtomElementOptionEvent("contextmenu") = 
#define OnCopy AtomElementOptionEvent("copy") = 
#define OnCueChange AtomElementOptionEvent("cuechange") = 
#define OnCut AtomElementOptionEvent("cut") = 
#define OnDblClick AtomElementOptionEvent("dblclick") = 
#define OnDrag AtomElementOptionEvent("drag") = 
#define OnDragEnd AtomElementOptionEvent("dragend") = 
#define OnDragEnter AtomElementOptionEvent("dragenter") = 
#define OnDragLeave AtomElementOptionEvent("dragleave") = 
#define OnDragOver AtomElementOptionEvent("dragover") = 
#define OnDragStart AtomElementOptionEvent("dragstart") = 
#define OnDrop AtomElementOptionEvent("drop") = 
#define OnDurationChange AtomElementOptionEvent("durationchange") = 
#define OnEmptied AtomElementOptionEvent("emptied") = 
#define OnEnded AtomElementOptionEvent("ended") = 
#define OnError AtomElementOptionEvent("error") = 
#define OnFocus AtomElementOptionEvent("focus") = 
#define OnFormData AtomElementOptionEvent("formdata") = 
#define OnFullscreenChange AtomElementOptionEvent("fullscreenchange") = 
#define OnFullscreenError AtomElementOptionEvent("fullscreenerror") = 
#define OnGotPointerCapture AtomElementOptionEvent("gotpointercapture") = 
#define OnInput AtomElementOptionEvent("input") = 
#define OnInvalid AtomElementOptionEvent("invalid") = 
#define OnKeyDown AtomElementOptionEvent("keydown") = 
#define OnKeyUp AtomElementOptionEvent("keyup") = 
#define OnLoad AtomElementOptionEvent("load") = 
#define OnLoadedData AtomElementOptionEvent("loadeddata") = 
#define OnLoadStart AtomElementOptionEvent("loadstart") = 
#define OnLoadedMetaData AtomElementOptionEvent("loadedmetadata") = 
#define OnLostPointerCapture AtomElementOptionEvent("lostpointercapture") = 
#define OnMouseDown AtomElementOptionEvent("mousedown") = 
#define OnMouseEnter AtomElementOptionEvent("mouseenter") = 
#define OnMouseLeave AtomElementOptionEvent("mouseleave") = 
#define OnMouseMove AtomElementOptionEvent("mousemove") = 
#define OnMouseOut AtomElementOptionEvent("mouseout") = 
#define OnMouseUp AtomElementOptionEvent("mouseup") = 
#define OnPaste AtomElementOptionEvent("paste") = 
#define OnPause AtomElementOptionEvent("pause") = 
#define OnPlay AtomElementOptionEvent("play") = 
#define OnPlaying AtomElementOptionEvent("playing") = 
#define OnPointerCancel AtomElementOptionEvent("pointercancel") = 
#define OnPointerDown AtomElementOptionEvent("pointerdown") = 
#define OnPointerEnter AtomElementOptionEvent("pointerenter") = 
#define OnPointerLeave AtomElementOptionEvent("pointerleave") = 
#define OnPointerMove AtomElementOptionEvent("pointermove") = 
#define OnPointerOut AtomElementOptionEvent("pointerout") = 
#define OnPointerOver AtomElementOptionEvent("pointerover") = 
#define OnPointerUp AtomElementOptionEvent("pointerup") = 
#define OnProgress AtomElementOptionEvent("progress") = 
#define OnRateChange AtomElementOptionEvent("ratechange") = 
#define OnReset AtomElementOptionEvent("reset") = 
#define OnResize AtomElementOptionEvent("resize") = 
#define OnScroll AtomElementOptionEvent("scroll") = 
#define OnSecurityPolicyViolation AtomElementOptionEvent("securitypolicyviolation") = 
#define OnSeeked AtomElementOptionEvent("seeked") = 
#define OnSeeking AtomElementOptionEvent("seeking") = 
#define OnSelect AtomElementOptionEvent("select") = 
#define OnSelectionChange AtomElementOptionEvent("selectionchange") = 
#define OnSelectStart AtomElementOptionEvent("selectstart") = 
#define OnSlotChange AtomElementOptionEvent("slotchange") = 
#define OnStalled AtomElementOptionEvent("stalled") = 
#define OnSubmit AtomElementOptionEvent("submit") = 
#define OnSuspend AtomElementOptionEvent("suspend") = 
#define OnTimeUpdate AtomElementOptionEvent("timeupdate") = 
#define OnToggle AtomElementOptionEvent("toggle") = 
#define OnTouchCancel AtomElementOptionEvent("touchcancel") = 
#define OnTouchEnd AtomElementOptionEvent("touchend") = 
#define OnTouchMove AtomElementOptionEvent("touchmove") = 
#define OnTouchStart AtomElementOptionEvent("touchstart") = 
#define OnTransitionCancel AtomElementOptionEvent("transitioncancel") = 
#define OnTransitionEnd AtomElementOptionEvent("transitionend") = 
#define OnTransitionRun AtomElementOptionEvent("transitionrun") = 
#define OnVolumeChange AtomElementOptionEvent("volumechange") = 
#define OnWaiting AtomElementOptionEvent("waiting") = 
#define OnWheel AtomElementOptionEvent("wheel") = 
#define OnMessage AtomElementOptionEvent("message") = 
// Events

#endif
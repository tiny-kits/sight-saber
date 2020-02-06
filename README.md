# SightSabre - An Infrared Haptic Ranging Support Wand 
### Range haptically with a no-touch infrared light sabre
<a href="https://raw.githubusercontent.com/oyamist/om-ranger/master/assets/sight-saber.jpg"><img src="https://raw.githubusercontent.com/oyamist/om-ranger/master/assets/sight-saber.jpg" width=800px/></a>

Support canes used by the blind have a major drawback in that
they can whack people from behind unintentionally.  This is clearly
awkward for both the blind and the sighted.

The SightSabre uses an infrared TOF (Time-of-flight) laser 
to detect near objects.
Tactile feedback on the range of detected objects is provided by
a Linear Resonant Actuator (LRA) haptic device.

[See video](https://youtu.be/uYHzJQGOatI)

The SightSabre uses [TinyCircuits](https://tinycircuits.com) hardware
and is implemented with the [OMilli multi-threading library](https://github.com/oyamist/om-ranger/tree/master/src/omilli)
for microcontrollers.

<a href="https://raw.githubusercontent.com/oyamist/om-ranger/master/assets/sight-saber-parts.jpg"><img src="https://raw.githubusercontent.com/oyamist/om-ranger/master/assets/sight-saber-parts.jpg" width=800px/></a>

* [TinyZero MCU with 3-axis accelerometer](https://tinycircuits.com/products/tinyzero-processor)
* [TinyCircuits TOF distance sensor Wireling](https://tinycircuits.com/products/tof-distance-sensor-wireling-vl53l0x)
* [TinyCircuits LRA Driver Wireling](https://tinycircuits.com/products/lra-wireling-drv2605)
* [TinyCircuits RGB LED Wireling](https://tinycircuits.com/products/serial-rgb-led-wireling)
* [TinyCircuits 500mAh LIPO Battery](https://tinycircuits.com/products/lithium-ion-polymer-battery-3-7v-500mah)
* [TinyCircuits Wireling Cables: 2x50mm and 1x100mm](https://tinycircuits.com/products/5-pin-extension-cable)
* [TinyCircuits Micro USB Cable](https://tinycircuits.com/products/micro-usb-cable-3-feet)
* 3D-printed parts [top](https://github.com/oyamist/om-ranger/blob/master/3dp/cubify/case-top.stl) [bottom](https://github.com/oyamist/om-ranger/blob/master/3dp/cubify/case-bot.stl) [front](https://github.com/oyamist/om-ranger/blob/master/3dp/cubify/case-front.stl) [switch](https://github.com/oyamist/om-ranger/blob/master/3dp/cubify/switch.stl)
* Zip-ties (2 small and 1 large)
* a screw

### Important!

* Do not aim the wand at faces or eyes. The Class 1 laser is rated as eye-safe 
  under normal operating conditions, but close visual inspection with naked eye
  or microscope may prove hazardous.
* Do not expose to water. The wand is not water resistant.
* Do not drop. The wand has fragile electronic components.
* Not for outdoor use. It's too bright for the wand.
* Ranging sensitivity varies by material sensed. Weakly reflective surfaces
  such as glass may not be detectable at shallow angles.
  Non-reflective surfaces such as 
  [Vantablack](https://en.wikipedia.org/wiki/Vantablack) will not be 
  detected.
* Thin objects may not be detectable. E.g., chair seats are 
  much more detectable than chair legs. 
* In forward-sweep mode, the wand cannot detect descending steps.
* In floor-sweep mode, the wand cannot detect forward obstacles.
* To mute the wand, cover the tip. Or just put it in your pocket.

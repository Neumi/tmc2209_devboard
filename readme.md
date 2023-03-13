# TMC2209 Development Board for Arduino Uno
A development board to test the Trinamic TMC2209 stepper motor controller on an Arduino Uno.

This board should cover all options and IOs that Trinamic provides for its TMC2209.

Facts:
 - All TMC2209 pins are connected to digital pins of the Arduino. 
 - XT30 power connector
 - voltage source selector Arduino VIN OR XT30
 - TVS diodes on 5v and 28V lane of the TMC2209
 - different wiring schemes for the JST motor connector (WHAT A MESS IT ALWAYS WAS TO GET THE RIGHT PHASES!)
 - different current setting selectable with solder bridges (or custom resistor also possible)
 - reset button for Arudino + power LED



KICAD and production files for JLCPCB are also included. Code will follow. 
Production cost incl assembly is around 50€ for 5pcs. THT components not included.

Feedback is very welcome!

<img alt="PCB assembly perspectives" src="/images/perspectives.png">
<img alt="PCB 3d view" src="/images/3d_view.png">
<img alt="top view" src="/images/top_view.png">
<img alt="top view" src="/images/order_layout.png">
<img alt="PCB layout" src="/images/layout.png">



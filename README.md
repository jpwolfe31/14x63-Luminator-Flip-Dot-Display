# 14x63 Luminator Flip Dot Display
Luminator Flip Dot Display 14x21 (3)

Flip Dot Display Build Information

These Luminator Flip Dot displays were acquired on eBay in 2023.  As shown in the uploaded photo, the upper display was the first acquisition and consists of two side by side five character boards with each character having a 7 by 5 dot matrix.  The lower display was acquired a few months later and consists of three 14 by 21 dot matrices.  Both were used on transit busses.

There are two github repositories as the units are controlled quite differently.  The first is for the lower display and is called 14x63 Luminator Flip Dot Display.  The second is for the upper display and is called 10 Character 7x5 Luminator Flip Dot Display.  This later repository is not quite finished and only has the software, schematics and pcb board designs.

While having different arrangements of dots, the displays use the same flip dot mechanisms and magnetic drivers.  The upper display has the row drivers located on the board.  The lower display has no row or column drivers on the board.  

On the three 14x21 display boards, the electronics used to control the display are located on the back of the display boards.  All of the PC boards are the same and each is attached using the four 14 pin connectors already on the bottom of each display board.  The first board has the Nano-ESP32 that controls the entire display.  This first board also has both row and column drivers.  These row drivers are also used by the other two boards.  The second and third boards just have the column drivers for their respective board.  The build information and the schematic has further details.

The display is controlled by a Blynk iPhone app.  

The software includes tetris and game of life applications.  Both work great on aflip dot.  Unfortunately, Blynk just announced that it is not supporting new makers on its app, but I believe this program could be modified to work with the Aurduino Cloud IOT and its messenger and button widgets.

See folders above for code, schematics, build information and printed circuit boards. Feel free to email me at jpwolfe31@yahoo.com if you have any questions.

Video at:  https://www.youtube.com/watch?v=LgkpwIBXWuQ

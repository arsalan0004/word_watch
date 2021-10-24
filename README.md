#The Word Watch

![Picture of a computer rentering of the word watch](https://github.com/arsalan0004/word_watch/blob/master/photos/final_jpeg.jpg)

Overview
The Word watch is a sleek wristwatch that spells out the time for you – and a bit more.

**Lightning mode** Designed for networking. hold the main button down for five seconds to activate lightning mode. While in this mode,
 the watch waits a random amount of time (1-5 minutes) before Lighting up a cascade of letters in such a way that it looks like lightning raced
 Across your wrist. Simple, but eye-catching. This little trick is the ultimate icebreaker.

**Extreme power efficiency** every level of the word watch’s design was built with power efficiency in mind.
 The green LEDs were picked not only for their elegant look, but also because they are extremely energy efficient.
 The use of onboard chips was minimized, and the CPU sleeps when not in use. As a result, the expected life
 expectancy of the single CR2032 that powers this watch is about 2 years. For more on energy-saving techniques
 used in this design, please scroll down to the engineering considerations section.

**Ease of use** to change the time, simply press and hold the main button for two seconds.
 The current time will flash on-and-off when you have entered time-change mode.
 Now you can simply click the main button to increment the time.
 Once you are satisfied with the time setting, hold the main button down for two seconds to return to the default mode.
 You can now tap the button at anytime to show the time.

#Engineering Considerations
-Screen Development

![render of close up of the glass screen](https://github.com/arsalan0004/word_watch/blob/master/photos/glass.png)

**Waterproofing the screen** The screen is laser cut from a 3mm thin piece of plywood. Since it has holes in it that lead straight to the circuit board,
 it needs to be waterproofed. To accomplish this, an epoxy resin is used. This resin needs to have an extremely low viscosity(similar to water) 
otherwise it will not pour nicely into the letter holes in the screen.
 Furthermore, all epoxies need to be degassed to produce crystal clear results upon hardening.
 Degassing cannot be done with heat for this design because it will cause the wood to degas- releasing gasses into the epoxy,
 which bubble up and obscure the light coming through the letter holes. Therefore, degassing must be done in a pressure chamber 
(positive or negative pressure above 30 PSI works perfectly) 
  
**neodymium magnets** twelve tiny (2mm h x 1 mm d ) cylindrical magnets were used to hold the screen onto the rest of the watch body.
 This was because the addition of screws (which adds a theme of ruggedness and complexity) would have ruined the design of the watch,
 which is meant to appear elegant and minimalistic.  Furthermore, tiny screw holes are impossible to model with FLA 3D printing.
 These screen magnets pair with a matching set of magnets built into the body of the watch

**Blinds** Blinds were produced to enclose every single LED on the circuit board, ensuring that light would not leak from an LED into an adjacent letter.
 The Blinds are the square compartments of a 3mm square mesh that was 3D printed and sandwiched between the circuit board and the screen.
 The height of the mesh is slightly greater than the maximum height of the LEDs and lays flush on the bottom side of the screen,
 ensuring that the light from an LED cannot reach it’s neighboring LED’s letter. 

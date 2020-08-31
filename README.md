# Smooth Lighting Calculations
Basically it's harder than you think.

* Manually change the lighting.
  * Enter into mixing mode (With btn press), this is where you can manually mix colours with 3 potentiometers (RGB).
* Automatic mode
  * This is where the arduino will generate an initiial 2 numbers, then incrase/decrease to the second number. Once the second number is reached another "goal" will be set and the program will increase/decrease to it depending on if the number is larger or smaller than it.
  
This therefore creates a smooth fade into each colours. Although bias would need to be added so each colour would be equal. Humans are weird as we see red and green far better than others, this is a result of the wavelength overlap (and in our eyes) between the two colours. 

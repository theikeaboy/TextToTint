Serial-Controlled RGB LED Interface
=================================

This project lets you control an RGB LED in real time by typing simple color commands into the Arduino Serial Monitor. The code processes your text input, maps it to specific RGB values using PWM, and includes a smooth, looping rainbow transition effect.

Core Features
------------
* Simple Text Commands: Parses incoming serial text, automatically handling accidental spaces and capital letters.
* Predefined Colors: Supports quick switching to red, green, blue, purple, orange, pink, white, and yellow, as well as an "off" command.
* Responsive Rainbow Cycle: Fades smoothly through the entire color spectrum. The loop constantly listens for new inputs, so you can interrupt the rainbow effect instantly just by typing a new color.
* Common Anode Compatibility: The code natively accounts for common anode hardware configurations by inverting the PWM values (255 - value).

Hardware Setup
--------------
Connect your RGB LED to the Arduino board using the pin layout below. 

* Red Element   -> Arduino Pin 10 (PWM)
* Green Element -> Arduino Pin 8  (PWM)
* Blue Element  -> Arduino Pin 6  (PWM)

Note: Remember to place current-limiting resistors (like 220 or 330 ohm) between the Arduino digital pins and the LED pins to protect your hardware from burning out.

How to Use It
-------------
1. Open the project sketch in the Arduino IDE.
2. Connect your Arduino board to your computer and select the correct port under Tools > Port.
3. Upload the code to the board.
4. Open the Serial Monitor (Ctrl + Shift + M).
5. Ensure the baud rate is set to 9600 and the line ending configuration is set to "Newline".
6. Type a command (like 'blue', 'orange', or 'rainbow') into the input bar and press Enter.

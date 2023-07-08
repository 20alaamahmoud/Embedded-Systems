# Embedded-Systems
Embedded systems course (college assignments)

--- Assignment 1 ---

Write Embedded C code using ATmega32 to control a 7-segment using two push
buttons.
Requirements:
- If the switch1 is pressed just increase the number appeared in the 7-segment
display, and if the number reach the maximum number (9) do nothing.
- If the switch2 is pressed just decrease the number appeared in the 7-segment
display, and if the number reach the minimum number (0) do nothing.


--- Assignment 2 ---

Write embedded C code using the ATmega32 to make a calculator using both the
keypad and the LCD display.
Requirements: The calculator is allowed to do only one operation at a time
Note: Use ON/C to clear the LCD display


--- Assignment 3 ---

Implement two drivers, the first for the LED and the second for the push
button.
Notes:
These drivers should be configurable to be able to use any LED or any push
button.
Also, we should be able to use many LEDs together in the same project using the
same LED driver. The same applies to the push button.


--- Assignment 4 ---

Write Embedded C code using ATmega32 MCU control 4-LEDs by
external interrupt INT1.
Requirements:
- A roll action is perform using the LEDs each LED for half second.
- The first LED is lit and roll down to the last LED then back to the first LED. This
operation is done continuous.
- Enable the internal pull up resistance at INT1 pin (PD3).
- When the INT1 is triggered all the LEDs flash five times in five seconds.

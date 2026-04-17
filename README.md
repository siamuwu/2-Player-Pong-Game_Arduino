# 2 Player Pong Game by Arduino Uno R4 WiFI
#### I have built a real time 2 player Pong game on an Arduino LED Matrix where two users compete using physical buttons. This project combines embedded systems as well as real time input handling and game logic into a compact interactive system!
---
## System
The game runs on an 8x12 LED matrix on Arduino Uno R4 WiFi where a moving ball interacts with two player controlled paddles.

## How it works:
* Ball moves continuously with x and y direction updates.
* Players control paddles vertically using push buttons.
* Collision detection reverses ball direction.
* Missing the ball triggers a win condition.
* Winner is displayed using scrolling text on the matrix.

Everything is handled in real time inside the Arduino loop without any external processing..

## Impact
* Transformed a simple microcontroller setup into an interactive gaming system.
* Ensured real time control and response using hardware inputs
* Showed strong understanding of embedded logic, timing and state handling.

## Connections and Controls:

You need 4 push buttons.
Each button press moves the paddle one step up or down.

One side of each button → Arduino digital pin
Other side → GND

#### Pin mapping
* Pin 2 → Player 1 Up
* Pin 3 → Player 1 Down
* Pin 6 → Player 2 Up
* Pin 7 → Player 2 Down

The LED matrix is controlled directly using the Arduino_LED_Matrix library so no extra wiring is needed if you are using Arduino UNO R4.

## Features
* Real time two player gameplay.
* Continuous ball physics using directional variables.
* Paddle boundary control to prevent overflow.
* Collision detection with both paddles.
* Win detection with animated text feedback.
* Lightweight and efficient loop execution.

This kind of project ensured us a decent chemistry of code, interaction, hardware, logic and user experience!

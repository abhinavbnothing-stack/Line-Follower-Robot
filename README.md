# Line Follower Robot

An autonomous line following robot built
using Arduino Uno that detects and follows
a black line on a white surface in real time.

## Components Used
- Arduino Uno
- 2x IR Sensor Modules
- L298N Motor Driver
- 2x DC TT Gear Motors
- 9V Battery Pack
- Robot Chassis + Wheels

## How It Works
Two IR sensors mounted at the base of the
bot face downward toward the ground. Black
surface absorbs IR light, white surface
reflects it. Based on which sensor detects
the line, Arduino steers the bot.

- Both on white  → Move forward
- Left on black  → Turn left
- Right on black → Turn right
- Both on black  → Stop

## Pin Configuration
| Component     | Arduino Pin  |
|---------------|--------------|
| Left IR OUT   | Pin 2        |
| Right IR OUT  | Pin 3        |
| L298N IN1     | Pin 4        |
| L298N IN2     | Pin 5        |
| L298N IN3     | Pin 6        |
| L298N IN4     | Pin 7        |
| L298N ENA     | Pin 9 PWM    |
| L298N ENB     | Pin 10 PWM   |

## Skills Demonstrated
- IR sensor integration
- DC motor control via L298N
- PWM based speed control
- Autonomous steering logic
- Embedded C programming in Arduino IDE

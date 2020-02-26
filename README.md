# ArduinoUnoR3SimpleFishFeeder
This is code for a simple fish feeder that dispense food every 24 hours using arduino. It is designed for a device to run on battery.

# Setup
Materials
1) Arduino Uno R3 (or Arduino Mini)
2) Male connectors
3) Wires
4) SG90 Servo
5) Button
6) Buck Converters
7) Batteries and (1.5v x3 battery holders) x2

Arduino Board
Connect the board with the instruction shown below, make sure the voltage from the buck converter supplies 5v of power to the board
1) Connect a bactery holder to the buck converter; then connect the buck converter to the board
  - insert positive to Vin and negative to GND
2) Connect the one side of the button with a red wire, and the other a black wire (make sure the wires are opposite diagonally of each other
  - connect the red wire to 2 and the black wire to GND
3) Connect a black male connector to the following the brown wire on the servo, a red male connector to the red wire, and a blue male connector to the yellow side on the servo
  - connect black wire to GND, red wire to the positive side on the other battery holder, blue male connector to 9
4) Connect the black wire on the battery holder to GND

# Usage
When setting up, simply just press the button to set the current time as the feeding time; and every 24 hours it will dispense food.





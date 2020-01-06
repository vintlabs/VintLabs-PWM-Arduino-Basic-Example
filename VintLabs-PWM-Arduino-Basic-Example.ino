// PWM Example for VintLabs ESP32 PWM Driver DevKit
// Connect an LED light from PWM0 on the board to ground (if using a discrete LED use a current limiting series resistor!)

// Select the PWM output to use - you can use PWM0-PWM7 for the VintLabs boards, or simply specify the GPIO number
const int pwmOutput = PWM0;

// Set the PWM frequency
const int frequency = 10000;

// Set the LED channel. Note that this is not related to a pin number, but an arbitrary channel number from 0-7
const int ledChannel = 0;

// Set the resolution. This can be 8, 10, 12 or 15 bits
const int resolution = 12;


void setup() {
  // Basic PWM setup
  ledcSetup(ledChannel, frequency, resolution);

  // Attach the actual output to the channel
  ledcAttachPin(pwmOutput, ledChannel);

}

void loop() {
  // Just loop from off to max, then back again
  for (int dc = 0; dc < pow(2, resolution); dc++)
  {
    // set the duty cycle
    ledcWrite(ledChannel, dc);
    delay(10);
  }
  for (int dc = pow(2, resolution) - 1; dc >= 0; dc--)
  {
    // set the duty cycle
    ledcWrite(ledChannel, dc);
    delay(10);
  }
}

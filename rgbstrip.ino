
int brightness;

void setup() {

RGB.control(true);
RGB.color(255, 0, 255);
brightness = 0;

}

void loop() {


brightness = (brightness + 10) & 0xFF;
RGB.brightness(brightness);

delay(50);


}

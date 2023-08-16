//neopixels functions
void neopixelsOn() {
  
    strip.clear(); // Set all pixel colors to 'off'
    strip.fill(orange, 0, 16);
    strip.fill(blue, 16, 7);
    strip.fill(orange, 23, 17);
    strip.setBrightness(50);
    strip.show();
}

void neopixelsBreathe() {
    strip.show();
        for (int i=10; i<200; i++) { strip.setBrightness(i); strip.show(); delay(25); }
        for (int i=200; i>10; i--) { strip.setBrightness(i); strip.show(); delay(25); }

}

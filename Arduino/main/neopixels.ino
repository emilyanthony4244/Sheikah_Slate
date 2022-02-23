//neopixels functions
void neopixelsOn() {
  
    strip.clear(); // Set all pixel colors to 'off'
    strip.fill(orange, 0, 15);
    strip.fill(blue, 16, 7);
    strip.show();
}

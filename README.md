# Display_OLED
Arduino library for SSD1306-powered display device

## Prerequisites

- [ArxTypeTraits](https://github.com/hideakitai/ArxTypeTraits)
- [ui_common](https://github.com/ikechangexentrick/ui_common)
- [button](https://github.com/ikechangexentrick/button)

- [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
- [Adafruit_GFX_Library](https://github.com/adafruit/Adafruit-GFX-Library)
- [Adafruit_BusIO](https://github.com/adafruit/Adafruit_BusIO)

## Preparation (if needed)

- I often use [0.96in 128x64 OLED display](https://akizukidenshi.com/catalog/g/gP-12031/), and mount it upside-down on PCB.
- I sometimes use Raspberry Pi Pico, and with Adafruit_SSD1306 I'll get a compilation error.

To deal with the requirement/problem above, I created a patch for Adafruit_SSD1306;
```
% cd Adafruit_SSD1306
% patch -p1 < patch_for_Adafruit_SSD1306.txt
```

## Installation

cd to the directory for Arduino-IDE's library and just clone or copy this.


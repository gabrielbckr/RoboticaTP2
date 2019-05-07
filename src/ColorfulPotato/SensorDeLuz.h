
#ifndef __COLORFUL_POTATO_LIGHT__
#define __COLORFUL_POTATO_LIGHT__


const int DELAY_PARAM = 300;
const char FAILED_TO_DETECT = 'X';
const int blue_threshold = 600;
const int sum_rgb_dark_threshold = 100;

void StartColorSensing(int pin);

char DetectColor();

// int DetectColor();
 
bool isBlue(int r, int g, int b);
bool isYellow(int r, int g, int b);
bool isRed(int r, int g, int b);
bool isGreen(int r, int g, int b);
bool isDark(int r, int g, int b);

#endif

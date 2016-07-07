#ifndef COLOR_H
#define COLOR_H

namespace Color {

    typedef struct Color {
        Color(int r, int g, int b) :
        R(r),
        G(g),
        B(b)
        {}

        int R;
        int G;
        int B;

    } Color;


    const static Color WHITE(255, 255, 255); // RGB Strips can't produce white, you need RGBW
    const static Color BLACK(0, 0, 0);
    const static Color RED(255, 0, 0);
    const static Color GREEN(0, 255, 0);
    const static Color BLUE(0, 0, 255);

};

#endif

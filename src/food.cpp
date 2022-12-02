#include <iostream>

#include "headers/food.h"

int w, h, s;

food::food(const int &width, const int &height, const int &scale) {
    w = width;
    h = height;
    s = scale;
}

float food::foodX() {
    return getFood((float) ((rand() % (w / s) + 1) * s), w);
}

float food::foodY() {
    return getFood((float) ((rand() % (h / s) + 1) * s), h);
}

bool food::foodCollision(float &x, float &y, float &fx, float &fy) {
    if(x == fx && y == fy)
        return true;
    return false;
}

float food::getFood(float a, int& size) {
    if(a >= (float) size) a = (float) (size - s);
    return a;
}

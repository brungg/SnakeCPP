#include "headers/body.h"

float body::moveX(float& currX, char& d, const int& s) {
    switch(d) {
        default:
            return 0.f;
        case 'r':
            return currX + (float) s;
        case 'l':
            return currX - (float) s;
    }
}

float body::moveY(float& currY, char& d, const int& s) {
    switch(d) {
        default:
            return 0.f;
        case 'u':
            return currY - (float) s;
        case 'd':
            return currY + (float) s;
    }
}

bool body::checkCollision(const int& width, const int& height, float& currX, float& currY, const int& s) {
    if(currX > (float) (width - s) || currY > (float) (height - s) || currX < 0.f || currY < 0.f)
        return true;
    return false;
}

#pragma once

class food {
public:
    food(const int& w, const int& h, const int& s);
    float foodX();
    float foodY();

    static bool foodCollision(float& x, float& y, float& fx, float& fy);
private:
    float getFood(float a, int& size);
};
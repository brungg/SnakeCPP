#pragma once

class body {
public:
    static float moveX(float& currX, char& direction, const int& s);
    static float moveY(float& currY, char& direction, const int& s);

    static bool checkCollision(const int& width, const int& height, float& currX, float& currY, const int& s);
};
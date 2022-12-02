#include <SFML/Graphics.hpp>
#include <iostream>

#include "headers/body.h"
#include "headers/food.h"

const int width = 680, height = 480, SCALE = 20;
bool GET_NEW_FOOD = true;
float foodX, foodY;
float bodyX[width] = {}, bodyY[height] = {};
int snakeLength = 1;
char a = 'r';

sf::RenderWindow window(sf::VideoMode(width, height), "Snake");

void draw(bool color, float x, float y) {
    sf::RectangleShape c(sf::Vector2f((float) SCALE, (float) SCALE));
    c.setPosition(x, y);
    if(color)
        c.setFillColor(sf::Color::Red);
    else
        c.setFillColor(sf::Color::Green);
    window.draw(c);
}

char getDirection(bool wcol, bool fcol) {
    if(wcol) {
        bodyX[0] = 0.f;
        bodyY[0] = 0.f;
        snakeLength = 1;
        GET_NEW_FOOD = true;
        return '0';
    }
    if(fcol) {
        GET_NEW_FOOD = true;
        snakeLength++;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) { return 'l'; }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { return 'r'; }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { return 'u'; }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { return 'd'; }
    return a;
}

int main() {
    window.setFramerateLimit(10);
    food food(width, height, SCALE);

    while(window.isOpen()) {
        sf::Event e{};
        if(window.pollEvent(e)) {
            if(e.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        a = getDirection(body::checkCollision(width, height, bodyX[0], bodyY[0], SCALE), food::foodCollision(bodyX[0], bodyY[0], foodX, foodY));

        if(GET_NEW_FOOD) {
            foodX = food.foodX(); foodY = food.foodY();
            GET_NEW_FOOD = false;
        }

        for (int z = snakeLength; z > 0; z--) {
            bodyX[z] = bodyX[(z - 1)];
            bodyY[z] = bodyY[(z - 1)];
        }

        if(a == 'l' || a == 'r') bodyX[0] = body::moveX(bodyX[0], a, SCALE);
        if(a == 'u' || a == 'd') bodyY[0] = body::moveY(bodyY[0], a, SCALE);

        for(int i = 0; i < snakeLength; i++) {
            draw(false, bodyX[i], bodyY[i]);
        }

        draw(true, foodX, foodY);

        window.display();
    }
}
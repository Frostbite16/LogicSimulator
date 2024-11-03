#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>

std::vector<int> clickedBalls;

class Ball {
public:
    Ball(int gridSize, int radius) {
        this->gridSize = gridSize;
        this->radius = radius;
        this->balls = new sf::CircleShape[gridSize * 8];
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < 8; j++) {
                balls[i * 8 + j].setRadius(radius);
                if (i == 0 || i == gridSize - 1) {
                    balls[i * 8 + j].setPosition(175 + j * 50 + 40, i * 80 + 40);
                } else {
                    balls[i * 8 + j].setPosition(j * 100 + 40, i * 80 + 40);
                }
                balls[i * 8 + j].setFillColor(sf::Color::Red);
            }
        }
    }

    ~Ball() {
        delete[] balls;
    }

    sf::CircleShape* getBalls() {
        return balls;
    }

private:
    int gridSize;
    int radius;
    sf::CircleShape* balls;
};

class Line {
public:
    Line() {}

    void draw(sf::RenderWindow& window, sf::CircleShape* balls, std::vector<int>& clickedBalls) {
        window.clear();
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 8; j++) {
                window.draw(balls[i * 8 + j]);
            }
        }
        if (clickedBalls.size() > 1) {
            for (int i = 1; i < clickedBalls.size(); i++) {
                sf::Vertex line[] = {
                    sf::Vertex(balls[clickedBalls[i - 1]].getPosition(), sf::Color::Red),
                    sf::Vertex(balls[clickedBalls[i]].getPosition(), sf::Color::Red)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
        window.display();
    }

    void handleEvents(sf::RenderWindow& window, sf::CircleShape* balls, std::vector<int>& clickedBalls) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 8; j++) {
                        if (balls[i * 8 + j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            bool alreadyClicked = false;
                            for (int k = 0; k < clickedBalls.size(); k++) {
                                if (clickedBalls[k] == i * 8 + j) {
                                    alreadyClicked = true;
                                    break;
                                }
                            }
                            if (!alreadyClicked) {
                                clickedBalls.push_back(i * 8 + j);
                            } else {
                                for (int k = 0; k < clickedBalls.size(); k++) {
                                    if (clickedBalls[k] == i * 8 + j) {
                                        clickedBalls.erase(clickedBalls.begin() + k);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

private:
};

int main() {
    // Criar a janela
    sf::RenderWindow window(sf::VideoMode(800, 800), "Grid 10x8");

    // Definir o tamanho do grid
    int gridSize = 10;

    // Criar um objeto Ball
    Ball ball(gridSize, 5);

    // Criar um vetor para armazenar as bolas clicadas
    clickedBalls.clear();

    // Iniciar o loop principal
    Line line;
    while (window.isOpen()) {
        line.handleEvents(window, ball.getBalls(), clickedBalls);
        line.draw(window, ball.getBalls(), clickedBalls);
    }

    return 0;
}
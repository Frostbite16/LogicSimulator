#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>
std::vector<sf::Vertex> lines;
std::vector<sf::Vertex> linesToDraw;
std::vector<int> clickedBalls;
class boardPin {
    bool connected;
    public:
        boardPin() {
            connected = false;
        }
};

class logicBoard {
    boardPin board[8][8];

    public:

};

int main()
{
    // Criar a janela
    sf::RenderWindow window(sf::VideoMode(800, 800), "Grid 10x8");

    // Definir o tamanho do grid
    int gridSize = 10;

    // Criar um vetor para armazenar as bolas do grid
    sf::CircleShape balls[gridSize * 8];

    // Criar um vetor para armazenar as bolas clicadas
    bool ballsClicked[gridSize * 8];

    // Inicializar as bolas clicadas como false
    for (int i = 0; i < gridSize * 8; i++) {
        ballsClicked[i] = false;
    }

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < 8; j++) {
            // Criar uma bolinha com tamanho 10
            balls[i * 8 + j].setRadius(5);
            // Definir a posição da bolinha no centro de cada grid
            if(i == 0 || i == gridSize - 1) {
                balls[i * 8 + j].setPosition(175 +j * 50 + 40, i * 80 + 40);
            }
            else {
                balls[i * 8 + j].setPosition(j * 100 + 40, i * 80 + 40);
            }

            // Definir a cor da bolinha (vermelha por padrão)
            balls[i * 8 + j].setFillColor(sf::Color::Red);
        }
    }

    // Iniciar o loop principal
    while (window.isOpen()) {
        // Tratar os eventos
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed) {
                // Verificar se o usuário clicou em uma bolinha
                for (int i = 0; i < gridSize; i++) {
                    for (int j = 0; j < 8; j++) {
                        // Verificar se o ponto de clique está dentro da bolinha
                        if (balls[i * 8 + j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Verificar se a bola não foi clicada anteriormente
                            bool alreadyClicked = false;
                            for (int k = 0; k < clickedBalls.size(); k++) {
                                if (clickedBalls[k] == i * 8 + j) {
                                    alreadyClicked = true;
                                    break;
                                }
                            }
                            if (!alreadyClicked) {
                                // Marcar a bolinha como clicada
                                clickedBalls.push_back(i * 8 + j);
                            }
                        }
                    }
                }
            }
        }

        // Desenhar os quadrados e bolas do grid
        window.clear();
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < 8; j++) {
                window.draw(balls[i * 8 + j]);
            }
        }
        if (clickedBalls.size() > 1) {
            for (int i = 0; i < clickedBalls.size() - 1; i++) {
                sf::Vertex line[] = {
                    sf::Vertex(balls[clickedBalls[i]].getPosition(), sf::Color::Red),
                    sf::Vertex(balls[clickedBalls[i + 1]].getPosition(), sf::Color::Red)
                };
                window.draw(line, 2, sf::Lines);
            }
        }
        window.display();
    }

    return 0;
}
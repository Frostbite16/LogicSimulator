#include<iostream>
#include<vector>
#include <SFML/Graphics.hpp>

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
    sf::RenderWindow window(sf::VideoMode(800, 800), "Grid 8x8");

    // Definir o tamanho do grid
    int gridSize = 8;

    // Criar um vetor para armazenar as bolas do grid
    sf::CircleShape balls[gridSize * gridSize];

    // Criar um vetor para armazenar as bolas clicadas
    bool ballsClicked[gridSize * gridSize];

    // Inicializar as bolas clicadas como false
    for (int i = 0; i < gridSize * gridSize; i++) {
        ballsClicked[i] = false;
    }
    // Criar os quadrados do grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            // Criar uma bolinha com tamanho 10
            balls[i * gridSize + j].setRadius(5);
            // Definir a posição da bolinha no centro de cada grid
            balls[i * gridSize + j].setPosition(j * 100 + 50, i * 100 + 50);
            // Definir a cor da bolinha (vermelha por padrão)
            balls[i * gridSize + j].setFillColor(sf::Color::Red);
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
                    for (int j = 0; j < gridSize; j++) {
                        // Verificar se o ponto de clique está dentro da bolinha
                        if (balls[i * gridSize + j].getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                            // Marcar a bolinha como clicada
                            ballsClicked[i * gridSize + j] = true;
                        }
                    }
                }
            }
        }
        // Desenhar os quadrados e bolas do grid
        window.clear();
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                // Verificar se a bolinha foi clicada e desenhar uma borda em volta se sim
                if (ballsClicked[i * gridSize + j]) {
                    if(balls[i * gridSize + j].getOutlineColor() == sf::Color::Blue) {
                        balls[i * gridSize + j].setOutlineColor(sf::Color::Black);
                    }
                    else {
                        balls[i * gridSize + j].setOutlineColor(sf::Color::Blue);
                    }
                    balls[i * gridSize + j].setOutlineThickness(2);
                }
                window.draw(balls[i * gridSize + j]);
            }
        }
        window.display();
    }

    return 0;
}
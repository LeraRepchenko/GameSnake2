#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

// ����������� � �������������� ����������
Game::Game(int width, int height) :
    score(0), level(1), isRunning(false),
    snake(width / 2, height / 2), food(0, 0),
    mapWidth(width), mapHeight(height) {
    initMap();  // ������������� �������� ����
}

// �������� ������� ����
void Game::start() {
    isRunning = true;

    while (isRunning) {
        // ��������� �����
        if (_kbhit()) {
            char key = _getch();
            switch (tolower(key)) {
            case 'w': snake.changeDirection(Direction::UP); break;
            case 'd': snake.changeDirection(Direction::RIGHT); break;
            case 's': snake.changeDirection(Direction::DOWN); break;
            case 'a': snake.changeDirection(Direction::LEFT); break;
            case 'p': pause(); break;
            case 'q': end(); break;
            }
        }

        update();        // ���������� ���������
        clearScreen();   // ������� ������
        printMap();      // ��������� �����
        Sleep(500 / level); // �������� (�������� ������� �� ������)
    }

    // ����� ��������� � ���������� ����
    std::cout << "\t\t!!!Game over!" << std::endl
        << "\t\tYour score is: " << score << std::endl;
    std::cin.ignore();
}

// ���������� ���� �� �����
void Game::pause() {
    isRunning = false;
}

// ����������� ���� ����� �����
void Game::resume() {
    isRunning = true;
}

// ���������� ����
void Game::end() {
    isRunning = false;
}

// ������������� �������� ����
void Game::initMap() {
    food.spawn(mapWidth, mapHeight, snake.getBody());  // ������ ��������� ���
}

// ��������� ����� ���
void Game::generateFood() {
    food.spawn(mapWidth, mapHeight, snake.getBody());
}

// ���������� �������� ���������
void Game::update() {
    snake.move();  // ������� ������

    // ��������, ����� �� ������ ���
    if (snake.getHeadPosition().x == food.getPosition().x &&
        snake.getHeadPosition().y == food.getPosition().y) {
        snake.grow();             // ����������� ������
        score += 10 * level;      // ��������� ����
        if (score % 50 == 0) level++; // �������� ������� ������ 50 �����
        generateFood();           // ������� ����� ���
    }

    // �������� ������������ �� �������
    Position head = snake.getHeadPosition();
    if (head.x <= 0 || head.x >= mapWidth - 1 ||
        head.y <= 0 || head.y >= mapHeight - 1) {
        end();  // ��������� ����
    }
}

// ������� ������ �������
void Game::clearScreen() {
    system("cls");
}

// ��������� �������� ����
void Game::printMap() const {
    // ������� ������� � �����������
    std::cout << "=================================\n";
    std::cout << " �������: " << level << "  |  ����: " << score << "\n";
    std::cout << "=================================\n";

    // ��������� ����� �����
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            // �����
            if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
                std::cout << 'X';
            }
            // ���
            else if (x == food.getPosition().x && y == food.getPosition().y) {
                std::cout << 'O';
            }
            // ������
            else {
                bool isBody = false;
                for (const Segment& segment : snake.getBody()) {
                    Position pos = segment.getPosition();
                    if (pos.x == x && pos.y == y) {
                        std::cout << 'o';
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) std::cout << ' ';  // ������ ������������
            }
        }
        std::cout << std::endl;
    }

    // ������ �������������� ������
    std::cout << "---------------------------------\n";
    std::cout << "����������: WASD | �����: P | �����: Q\n";
}

// ��������� ������� ��� ��������� (�� ������������ � ������� ����������)
char Game::getMapValue(int value) const {
    if (value > 0) return 'o';   // ���� ������
    switch (value) {
    case -1: return 'X';     // �����
    case -2: return 'O';     // ���
    }
    return ' ';                  // ������ �����
}

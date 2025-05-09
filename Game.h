#pragma once
#include "Snake.h"
#include "Food.h"
#include <vector>

class Game {
private:
    // ������� ���������
    int score;          // ������� ����
    int level;          // ������� ���������
    bool isRunning;     // ���� ��������� ����
    Snake snake;        // ������ ������
    Food food;          // ������ ���
    const int mapWidth; // ������ �����
    const int mapHeight; // ������ �����

    // ���������� ������
    void initMap();             // ������������� �����
    void generateFood();        // ��������� ���
    void update();              // ���������� ��������� ����
    void clearScreen();         // ������� ������
    void printMap() const;      // ��������� �����
    char getMapValue(int value) const; // ��������� ������� ��� ���������

public:
    // ����������� � ����������� �� ���������
    Game(int width = 20, int height = 20);

    // �������� ������
    void start();  // ������ ����
    void pause();  // �����
    void resume(); // �����������
    void end();    // ����������

    // ��������� ��������� ����
    bool isGameRunning() const { return isRunning; }
};
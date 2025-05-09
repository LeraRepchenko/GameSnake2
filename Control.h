#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "Game.h"

// ����� ��� ���������� ���������� ���������� ����� �������
class Control {
private:
    Game& game; // ������ �� ������ ����

public:
    Control(Game& g) : game(g) {}

    void handleInput(char input); // ������������ ���� � ����������
};

#endif // CONTROL_H

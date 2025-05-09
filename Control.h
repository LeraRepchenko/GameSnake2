#pragma once
#ifndef CONTROL_H
#define CONTROL_H

#include "Game.h"

// Класс для управления элементами управления через клавиши
class Control {
private:
    Game& game; // Ссылка на объект игры

public:
    Control(Game& g) : game(g) {}

    void handleInput(char input); // Обрабатывает ввод с клавиатуры
};

#endif // CONTROL_H

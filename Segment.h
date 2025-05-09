
#pragma once
#include "Position.h"

class Segment {
private:
    Position position;  // Позиция сегмента на поле

public:
    // Конструкторы
    Segment(int x, int y);      // Создание по координатам
    Segment(Position pos);      // Создание из объекта Position

    // Методы доступа
    Position getPosition() const;  // Получить текущую позицию
    void setPosition(Position pos); // Установить новую позицию
};
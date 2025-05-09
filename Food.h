
#pragma once
#include <vector>
#include "Position.h"
#include "Segment.h"

class Food {
private:
    Position position;  // Позиция еды на поле

public:
    // Конструктор
    Food(int x, int y);

    // Основные методы
    Position getPosition() const;  // Получение позиции
    void spawn(int width, int height, const std::vector<Segment>& snakeSegments); // Появление новой еды
};

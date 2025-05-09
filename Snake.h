
#pragma once
#include <vector>
#include "Direction.h"
#include "Segment.h"

class Snake {
private:
    std::vector<Segment> body;  // Вектор сегментов тела
    Direction direction;       // Текущее направление движения

public:
    // Конструктор с начальной позицией
    Snake(int startX, int startY);

    // Основные методы
    void move();                          // Движение змейки
    void grow();                          // Увеличение длины
    void changeDirection(Direction newDirection); // Смена направления

    // Методы доступа
    const std::vector<Segment>& getBody() const; // Получение тела
    Direction getDirection() const;       // Получение направления
    Position getHeadPosition() const;     // Получение позиции головы
};
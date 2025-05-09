#include "Snake.h"

// Конструктор - создает змейку с одним сегментом
Snake::Snake(int startX, int startY) : direction(Direction::RIGHT) {
    body.emplace_back(startX, startY);  // Добавляем голову
}

// Движение змейки
void Snake::move() {
    Position head = getHeadPosition();  // Текущая позиция головы

    // Изменяем позицию головы в зависимости от направления
    switch (direction) {
    case Direction::UP:    head.y--; break;
    case Direction::RIGHT: head.x++; break;
    case Direction::DOWN:  head.y++; break;
    case Direction::LEFT:  head.x--; break;
    }

    // Добавляем новую голову и удаляем последний сегмент
    body.insert(body.begin(), Segment(head));
    body.pop_back();
}

// Увеличение длины змейки
void Snake::grow() {
    // Просто добавляем копию последнего сегмента
    body.push_back(body.back());
}

// Смена направления с проверкой на "разворот"
void Snake::changeDirection(Direction newDirection) {
    // Не позволяем змейке развернуться на 180 градусов
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT)) {
        direction = newDirection;
    }
}

// Получение тела змейки
const std::vector<Segment>& Snake::getBody() const { return body; }

// Получение текущего направления
Direction Snake::getDirection() const { return direction; }

// Получение позиции головы
Position Snake::getHeadPosition() const {
    return body.front().getPosition();
}

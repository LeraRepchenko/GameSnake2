
#include "Segment.h"

// Конструктор с координатами
Segment::Segment(int x, int y) : position(x, y) {}

// Конструктор с объектом Position
Segment::Segment(Position pos) : position(pos) {}

// Получение текущей позиции
Position Segment::getPosition() const { return position; }

// Установка новой позиции
void Segment::setPosition(Position pos) { position = pos; }

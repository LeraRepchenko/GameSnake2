#pragma once
struct Position {
    int x;  // Координата по горизонтали
    int y;  // Координата по вертикали

    // Конструктор с параметрами по умолчанию
    Position(int x = 0, int y = 0) : x(x), y(y) {}
};
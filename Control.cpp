#include "Control.h"

// Метод обработки ввода с клавиатуры 
void Control::handleInput(char input) {
    switch (input) {
    case 'w': game.getSnake().changeDirection(Direction::UP); break;     // Вверх 
    case 's': game.getSnake().changeDirection(Direction::DOWN); break;   // Вниз 
    case 'a': game.getSnake().changeDirection(Direction::LEFT); break;   // Влево
    case 'd': game.getSnake().changeDirection(Direction::RIGHT); break;  // Вправо 
    case 'p': game.pause(); break;                                         // Пауза 
    case 'r': game.resume(); break;                                       // Возобновление 
    default: break;
    }
}

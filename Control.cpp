#include "Control.h"

// ����� ��������� ����� � ���������� 
void Control::handleInput(char input) {
    switch (input) {
    case 'w': game.getSnake().changeDirection(Direction::UP); break;     // ����� 
    case 's': game.getSnake().changeDirection(Direction::DOWN); break;   // ���� 
    case 'a': game.getSnake().changeDirection(Direction::LEFT); break;   // �����
    case 'd': game.getSnake().changeDirection(Direction::RIGHT); break;  // ������ 
    case 'p': game.pause(); break;                                         // ����� 
    case 'r': game.resume(); break;                                       // ������������� 
    default: break;
    }
}

#include "Snake.h"

// ����������� - ������� ������ � ����� ���������
Snake::Snake(int startX, int startY) : direction(Direction::RIGHT) {
    body.emplace_back(startX, startY);  // ��������� ������
}

// �������� ������
void Snake::move() {
    Position head = getHeadPosition();  // ������� ������� ������

    // �������� ������� ������ � ����������� �� �����������
    switch (direction) {
    case Direction::UP:    head.y--; break;
    case Direction::RIGHT: head.x++; break;
    case Direction::DOWN:  head.y++; break;
    case Direction::LEFT:  head.x--; break;
    }

    // ��������� ����� ������ � ������� ��������� �������
    body.insert(body.begin(), Segment(head));
    body.pop_back();
}

// ���������� ����� ������
void Snake::grow() {
    // ������ ��������� ����� ���������� ��������
    body.push_back(body.back());
}

// ����� ����������� � ��������� �� "��������"
void Snake::changeDirection(Direction newDirection) {
    // �� ��������� ������ ������������ �� 180 ��������
    if ((direction == Direction::UP && newDirection != Direction::DOWN) ||
        (direction == Direction::RIGHT && newDirection != Direction::LEFT) ||
        (direction == Direction::DOWN && newDirection != Direction::UP) ||
        (direction == Direction::LEFT && newDirection != Direction::RIGHT)) {
        direction = newDirection;
    }
}

// ��������� ���� ������
const std::vector<Segment>& Snake::getBody() const { return body; }

// ��������� �������� �����������
Direction Snake::getDirection() const { return direction; }

// ��������� ������� ������
Position Snake::getHeadPosition() const {
    return body.front().getPosition();
}

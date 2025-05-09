
#pragma once
#include <vector>
#include "Direction.h"
#include "Segment.h"

class Snake {
private:
    std::vector<Segment> body;  // ������ ��������� ����
    Direction direction;       // ������� ����������� ��������

public:
    // ����������� � ��������� ��������
    Snake(int startX, int startY);

    // �������� ������
    void move();                          // �������� ������
    void grow();                          // ���������� �����
    void changeDirection(Direction newDirection); // ����� �����������

    // ������ �������
    const std::vector<Segment>& getBody() const; // ��������� ����
    Direction getDirection() const;       // ��������� �����������
    Position getHeadPosition() const;     // ��������� ������� ������
};
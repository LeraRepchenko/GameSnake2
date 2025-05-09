
#pragma once
#include "Position.h"

class Segment {
private:
    Position position;  // ������� �������� �� ����

public:
    // ������������
    Segment(int x, int y);      // �������� �� �����������
    Segment(Position pos);      // �������� �� ������� Position

    // ������ �������
    Position getPosition() const;  // �������� ������� �������
    void setPosition(Position pos); // ���������� ����� �������
};
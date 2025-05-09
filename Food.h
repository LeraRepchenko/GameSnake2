
#pragma once
#include <vector>
#include "Position.h"
#include "Segment.h"

class Food {
private:
    Position position;  // ������� ��� �� ����

public:
    // �����������
    Food(int x, int y);

    // �������� ������
    Position getPosition() const;  // ��������� �������
    void spawn(int width, int height, const std::vector<Segment>& snakeSegments); // ��������� ����� ���
};

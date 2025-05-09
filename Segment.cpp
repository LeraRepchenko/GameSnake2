
#include "Segment.h"

// ����������� � ������������
Segment::Segment(int x, int y) : position(x, y) {}

// ����������� � �������� Position
Segment::Segment(Position pos) : position(pos) {}

// ��������� ������� �������
Position Segment::getPosition() const { return position; }

// ��������� ����� �������
void Segment::setPosition(Position pos) { position = pos; }

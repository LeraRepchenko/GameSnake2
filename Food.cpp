#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

// �����������
Food::Food(int x, int y) : position(x, y) {}

// ��������� ������� �������
Position Food::getPosition() const { return position; }

// ��������� ����� ������� ��� ���
void Food::spawn(int width, int height, const std::vector<Segment>& snakeSegments) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));  // ������������� ���������� ��������� �����
        seeded = true;
    }

    bool validPosition;
    do {
        validPosition = true;
        // ���������� ��������� ���������� � �������� ����
        position.x = 1 + std::rand() % (width - 2);
        position.y = 1 + std::rand() % (height - 2);

        // ���������, ����� ��� �� ��������� �� ������
        for (const Segment& segment : snakeSegments) {
            if (segment.getPosition().x == position.x &&
                segment.getPosition().y == position.y) {
                validPosition = false;
                break;
            }
        }
    } while (!validPosition);  // ���������, ���� �� ������ �������� �������
}

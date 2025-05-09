#include "Food.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

// Конструктор
Food::Food(int x, int y) : position(x, y) {}

// Получение текущей позиции
Position Food::getPosition() const { return position; }

// Генерация новой позиции для еды
void Food::spawn(int width, int height, const std::vector<Segment>& snakeSegments) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));  // Инициализация генератора случайных чисел
        seeded = true;
    }

    bool validPosition;
    do {
        validPosition = true;
        // Генерируем случайные координаты в пределах поля
        position.x = 1 + std::rand() % (width - 2);
        position.y = 1 + std::rand() % (height - 2);

        // Проверяем, чтобы еда не появилась на змейке
        for (const Segment& segment : snakeSegments) {
            if (segment.getPosition().x == position.x &&
                segment.getPosition().y == position.y) {
                validPosition = false;
                break;
            }
        }
    } while (!validPosition);  // Повторяем, пока не найдем валидную позицию
}

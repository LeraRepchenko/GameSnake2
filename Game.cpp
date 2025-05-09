#include "Game.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

// Конструктор с инициализацией параметров
Game::Game(int width, int height) :
    score(0), level(1), isRunning(false),
    snake(width / 2, height / 2), food(0, 0),
    mapWidth(width), mapHeight(height) {
    initMap();  // Инициализация игрового поля
}

// Основной игровой цикл
void Game::start() {
    isRunning = true;

    while (isRunning) {
        // Обработка ввода
        if (_kbhit()) {
            char key = _getch();
            switch (tolower(key)) {
            case 'w': snake.changeDirection(Direction::UP); break;
            case 'd': snake.changeDirection(Direction::RIGHT); break;
            case 's': snake.changeDirection(Direction::DOWN); break;
            case 'a': snake.changeDirection(Direction::LEFT); break;
            case 'p': pause(); break;
            case 'q': end(); break;
            }
        }

        update();        // Обновление состояния
        clearScreen();   // Очистка экрана
        printMap();      // Отрисовка карты
        Sleep(500 / level); // Задержка (скорость зависит от уровня)
    }

    // Вывод сообщения о завершении игры
    std::cout << "\t\t!!!Game over!" << std::endl
        << "\t\tYour score is: " << score << std::endl;
    std::cin.ignore();
}

// Постановка игры на паузу
void Game::pause() {
    isRunning = false;
}

// Продолжение игры после паузы
void Game::resume() {
    isRunning = true;
}

// Завершение игры
void Game::end() {
    isRunning = false;
}

// Инициализация игрового поля
void Game::initMap() {
    food.spawn(mapWidth, mapHeight, snake.getBody());  // Первое появление еды
}

// Генерация новой еды
void Game::generateFood() {
    food.spawn(mapWidth, mapHeight, snake.getBody());
}

// Обновление игрового состояния
void Game::update() {
    snake.move();  // Двигаем змейку

    // Проверка, съела ли змейка еду
    if (snake.getHeadPosition().x == food.getPosition().x &&
        snake.getHeadPosition().y == food.getPosition().y) {
        snake.grow();             // Увеличиваем змейку
        score += 10 * level;      // Добавляем очки
        if (score % 50 == 0) level++; // Повышаем уровень каждые 50 очков
        generateFood();           // Создаем новую еду
    }

    // Проверка столкновения со стенами
    Position head = snake.getHeadPosition();
    if (head.x <= 0 || head.x >= mapWidth - 1 ||
        head.y <= 0 || head.y >= mapHeight - 1) {
        end();  // Завершаем игру
    }
}

// Очистка экрана консоли
void Game::clearScreen() {
    system("cls");
}

// Отрисовка игрового поля
void Game::printMap() const {
    // Верхняя граница с информацией
    std::cout << "=================================\n";
    std::cout << " Уровень: " << level << "  |  Счёт: " << score << "\n";
    std::cout << "=================================\n";

    // Отрисовка самой карты
    for (int y = 0; y < mapHeight; ++y) {
        for (int x = 0; x < mapWidth; ++x) {
            // Стены
            if (x == 0 || x == mapWidth - 1 || y == 0 || y == mapHeight - 1) {
                std::cout << 'X';
            }
            // Еда
            else if (x == food.getPosition().x && y == food.getPosition().y) {
                std::cout << 'O';
            }
            // Змейка
            else {
                bool isBody = false;
                for (const Segment& segment : snake.getBody()) {
                    Position pos = segment.getPosition();
                    if (pos.x == x && pos.y == y) {
                        std::cout << 'o';
                        isBody = true;
                        break;
                    }
                }
                if (!isBody) std::cout << ' ';  // Пустое пространство
            }
        }
        std::cout << std::endl;
    }

    // Нижняя информационная панель
    std::cout << "---------------------------------\n";
    std::cout << "Управление: WASD | Пауза: P | Выход: Q\n";
}

// Получение символа для отрисовки (не используется в текущей реализации)
char Game::getMapValue(int value) const {
    if (value > 0) return 'o';   // Тело змейки
    switch (value) {
    case -1: return 'X';     // Стена
    case -2: return 'O';     // Еда
    }
    return ' ';                  // Пустое место
}

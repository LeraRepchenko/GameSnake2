#pragma once
#include "Snake.h"
#include "Food.h"
#include <vector>

class Game {
private:
    // Игровые параметры
    int score;          // Текущий счет
    int level;          // Уровень сложности
    bool isRunning;     // Флаг состояния игры
    Snake snake;        // Объект змейки
    Food food;          // Объект еды
    const int mapWidth; // Ширина карты
    const int mapHeight; // Высота карты

    // Внутренние методы
    void initMap();             // Инициализация карты
    void generateFood();        // Генерация еды
    void update();              // Обновление состояния игры
    void clearScreen();         // Очистка экрана
    void printMap() const;      // Отрисовка карты
    char getMapValue(int value) const; // Получение символа для отрисовки

public:
    // Конструктор с параметрами по умолчанию
    Game(int width = 20, int height = 20);

    // Основные методы
    void start();  // Запуск игры
    void pause();  // Пауза
    void resume(); // Продолжение
    void end();    // Завершение

    // Получение состояния игры
    bool isGameRunning() const { return isRunning; }
};
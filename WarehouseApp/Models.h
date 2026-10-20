#pragma once
#include <string>
#include <vector>
#include <iostream>

// Структура для категории товаров
struct Category {
    int id;              // Уникальный номер категории
    std::string name;    // Название (например, "Электроника")
};

// Структура для товара на складе (US-2, US-3, US-4, US-5, US-6)
struct Product {
    int id;                     // Уникальный номер товара
    std::string name;           // Название товара
    int categoryId;             // К какой категории относится (ссылка на Category.id)
    int quantity;               // Сколько штук на складе
    std::string location;       // Где лежит (например, "A-1" или "Стеллаж 3")
    std::string writeOffReason; // Причина списания (заполняется в US-4, если товар испорчен)
};

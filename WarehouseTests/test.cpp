#include "pch.h"
#include <vector>
#include <string>
#include "..\WarehouseApp\Models.h" // Подключаем ваши структуры

// ==========================================
// ТЕСТЫ УЧАСТНИКА 1 (Модели данных)
// ==========================================

// Тест 1.1: Проверка создания категории
TEST(Member1_Tests, CategoryCreation) {
    Category cat;
    cat.id = 1;
    cat.name = "Электроника";

    EXPECT_EQ(cat.id, 1);
    EXPECT_EQ(cat.name, "Электроника");
}

// Тест 1.2: Проверка создания товара и инициализации полей
TEST(Member1_Tests, ProductCreation) {
    Product p;
    p.id = 101;
    p.name = "Монитор";
    p.quantity = 10;

    EXPECT_EQ(p.id, 101);
    EXPECT_EQ(p.name, "Монитор");
    EXPECT_EQ(p.quantity, 10);
}

// ==========================================
// ТЕСТЫ УЧАСТНИКА 2 (Логика поиска - эмуляция)
// ==========================================

// Тест 2.1: Проверка, что поиск находит нужный товар
TEST(Member2_Tests, FindProductInVector) {
    std::vector<Product> products;
    products.push_back({ 1, "Мышь", 1, 5, "A-1", "" });
    products.push_back({ 2, "Клавиатура", 1, 3, "A-2", "" });

    std::string searchQuery = "Клавиатура";
    bool found = false;

    for (const auto& p : products) {
        if (p.name == searchQuery) {
            found = true;
            break;
        }
    }

    EXPECT_TRUE(found);
}

// Тест 2.2: Проверка, что поиск не находит несуществующий товар
TEST(Member2_Tests, NotFoundProduct) {
    std::vector<Product> products;
    products.push_back({ 1, "Мышь", 1, 5, "A-1", "" });

    std::string searchQuery = "Принтер";
    bool found = false;

    for (const auto& p : products) {
        if (p.name == searchQuery) {
            found = true;
            break;
        }
    }

    EXPECT_FALSE(found);
}

// ==========================================
// ТЕСТЫ УЧАСТНИКА 3 (Логика выдачи/списания)
// ==========================================

// Тест 3.1: Проверка успешной выдачи (хватает товара)
TEST(Member3_Tests, IssueProductSuccess) {
    Product p = { 1, "Монитор", 1, 10, "A-1", "" };
    int amountToIssue = 4;

    bool success = (p.quantity >= amountToIssue);
    if (success) {
        p.quantity -= amountToIssue;
    }

    EXPECT_TRUE(success);
    EXPECT_EQ(p.quantity, 6);
}

// Тест 3.2: Проверка отказа при нехватке товара
TEST(Member3_Tests, IssueProductFail) {
    Product p = { 1, "Монитор", 1, 2, "A-1", "" };
    int amountToIssue = 5;

    bool success = (p.quantity >= amountToIssue);

    EXPECT_FALSE(success);
    EXPECT_EQ(p.quantity, 2);
}
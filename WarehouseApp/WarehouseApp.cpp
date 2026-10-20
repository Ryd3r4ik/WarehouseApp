#include <iostream>
#include <vector>
#include <windows.h> // Обязательно для SetConsoleCP
#include "Models.h"
#include "Features_Member1.h"
#include "Features_Member2.h"
#include "Features_Member3.h"

int main() {
    // 1. Принудительно переводим консоль в UTF-8 (кодовая страница 65001)
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // ВАЖНО: Никакого setlocale тут быть не должно! Он ломает вывод в VS.

    std::vector<Category> categories;
    std::vector<Product> products;
    int choice;

    do {
        std::cout << "\n=== БАЗА СКЛАДА ФИРМЫ ===\n";
        std::cout << "1. Добавить категорию (US-1)\n";
        std::cout << "2. Добавить товар (US-2)\n";
        std::cout << "3. Поиск товаров (US-5)\n";
        std::cout << "4. Изменить местоположение (US-6)\n";
        std::cout << "5. Выдать товар (US-3)\n";
        std::cout << "6. Списать товар (US-4)\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
        case 1: addCategory(categories); break;
        case 2: addProduct(products, categories); break;
        case 3: searchProducts(products); break;
        case 4: changeLocation(products); break;
        case 5: issueProduct(products); break;
        case 6: writeOffProduct(products); break;
        case 0: std::cout << "Выход...\n"; break;
        default: std::cout << "Неверный выбор!\n";
        }
    } while (choice != 0);

    return 0;
}

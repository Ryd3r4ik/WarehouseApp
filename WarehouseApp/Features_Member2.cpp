#include "Features_Member2.h"

void searchProducts(const std::vector<Product>& products) {
    std::string query;
    std::cout << "Введите название или ID для поиска: ";
    std::cin >> query;

    bool found = false;
    for (const auto& p : products) {
        if (p.name == query || std::to_string(p.id) == query) {
            std::cout << "Найдено: " << p.name << " | Кол-во: " << p.quantity
                << " | Место: " << p.location << "\n";
            found = true;
        }
    }
    if (!found) std::cout << "Товар не найден.\n";
}

void changeLocation(std::vector<Product>& products) {
    int id;
    std::cout << "Введите ID товара для перемещения: "; std::cin >> id;

    for (auto& p : products) {
        if (p.id == id) {
            std::cout << "Текущее местоположение: " << p.location << "\n";
            std::cout << "Введите новое местоположение: ";
            std::cin >> p.location;
            std::cout << "Местоположение обновлено!\n";
            return;
        }
    }
    std::cout << "Товар с таким ID не найден.\n";
}

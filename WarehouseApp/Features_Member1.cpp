#include "Features_Member1.h"

void addCategory(std::vector<Category>& categories) {
    Category c;
    std::cout << "Введите ID категории: "; std::cin >> c.id;
    std::cout << "Введите название категории: "; std::cin >> c.name;
    categories.push_back(c);
    std::cout << "Категория добавлена!\n";
}

void addProduct(std::vector<Product>& products, const std::vector<Category>& categories) {
    Product p;
    std::cout << "Введите ID товара: "; std::cin >> p.id;
    std::cout << "Введите название товара: "; std::cin >> p.name;

    std::cout << "Доступные категории:\n";
    for (const auto& cat : categories) std::cout << cat.id << " - " << cat.name << "\n";

    std::cout << "Введите ID категории: "; std::cin >> p.categoryId;
    std::cout << "Введите количество: "; std::cin >> p.quantity;
    std::cout << "Введите местоположение (например, A-1): "; std::cin >> p.location;

    products.push_back(p);
    std::cout << "Товар добавлен на склад!\n";
}

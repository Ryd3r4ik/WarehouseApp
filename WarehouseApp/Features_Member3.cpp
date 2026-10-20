#include "Features_Member3.h"

void issueProduct(std::vector<Product>& products) {
    int id, amount;
    std::cout << "Введите ID товара для выдачи: "; std::cin >> id;
    std::cout << "Введите количество для выдачи: "; std::cin >> amount;

    for (auto& p : products) {
        if (p.id == id) {
            if (p.quantity >= amount) {
                p.quantity -= amount;
                std::cout << "Товар выдан. Остаток: " << p.quantity << "\n";
            }
            else {
                std::cout << "Ошибка: недостаточно товара на складе! (В наличии: " << p.quantity << ")\n";
            }
            return;
        }
    }
    std::cout << "Товар не найден.\n";
}

void writeOffProduct(std::vector<Product>& products) {
    int id, amount;
    std::string reason;
    std::cout << "Введите ID товара для списания: "; std::cin >> id;
    std::cout << "Введите количество для списания: "; std::cin >> amount;

    for (auto& p : products) {
        if (p.id == id) {
            if (p.quantity >= amount) {
                std::cout << "Введите причину списания (брак/порча/т.д.): ";
                std::cin >> reason;
                p.quantity -= amount;
                p.writeOffReason = reason;
                std::cout << "Списано. Остаток: " << p.quantity << "\n";
            }
            else {
                std::cout << "Ошибка: нельзя списать больше, чем есть!\n";
            }
            return;
        }
    }
    std::cout << "Товар не найден.\n";
}

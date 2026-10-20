#pragma once
#include "Models.h"

/**
 * @brief Ищет товар по названию или ID.
 * @details Пробегается по всему вектору товаров и выводит совпадения.
 * Если товар не найден, выводит соответствующее сообщение.
 * @param products Вектор товаров для поиска (константная ссылка).
 */
void searchProducts(const std::vector<Product>& products);

/**
 * @brief Изменяет местоположение (полку) товара.
 * @details Находит товар по ID и запрашивает новое место хранения.
 * @param products Ссылка на вектор товаров.
 */
void changeLocation(std::vector<Product>& products);

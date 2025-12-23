#pragma once

#include "menu.hpp"

namespace ga {
    const menu_item* show_menu(const menu_item* current);

    const menu_item* exit(const menu_item* current);
    
    const menu_item* go_back(const menu_item* current);

    const menu_item* add(const menu_item* current);
    
    const menu_item* substract(const menu_item* current);
    
    const menu_item* multiply(const menu_item* current);

    const menu_item* divide(const menu_item* current);

    const menu_item* differential(const menu_item* current);

    const menu_item* integral(const menu_item* current);

}
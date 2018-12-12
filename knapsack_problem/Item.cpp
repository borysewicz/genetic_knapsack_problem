#include "Item.h"

int Item::getSize() {
    return size;
}

int Item::getValue() {
    return value;
}

Item::Item(int new_value, int new_size) {
    size = new_size;
    value = new_value;
}

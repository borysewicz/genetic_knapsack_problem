#ifndef LISTA4_ITEM_H
#define LISTA4_ITEM_H


class Item {
public:
    Item(int new_value,int new_size);
    int getSize();;
    int getValue();
private:
    int size;
    int value;
};


#endif //LISTA4_ITEM_H

#ifndef ITEMTYPE_H
#define ITEMTYPE_H

enum Comparison {LESS, GREATER, EQUAL};

class ItemType
{
public:
    ItemType();
    void print();
    void initialize(int number);
    Comparison compareTo(ItemType item);
    int getValue() const;
    
private:
    int value;
};
#endif

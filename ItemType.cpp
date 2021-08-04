#include <iostream>
#include "ItemType.h"

using namespace std;

ItemType::ItemType()
{
}//ItemType

void ItemType::print()
{
  cout << value;
}//print

void ItemType::initialize(int number)
{
  value = number;
}//initialize

Comparison ItemType::compareTo(ItemType item)
{
  if(value < item.value) {
    return LESS;
  }//if
  else if(value > item.value) {
    return GREATER;
  }//else if
  else {
    return EQUAL;
  }//else
}//compareTo

int ItemType::getValue() const{
    return value;
}//getValue

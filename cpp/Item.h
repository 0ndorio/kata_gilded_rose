#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
 public:

  std::string name;
  int sellIn;
  int quality;

  Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality)
  {}
};

#endif //ITEM_H

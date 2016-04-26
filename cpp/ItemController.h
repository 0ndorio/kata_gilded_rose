#ifndef ITEM_CONTROLLER_H
#define ITEM_CONTROLLER_H

#include <map>
#include <string>
#include <vector>

#include "Item.h"

class ItemController
{
 public:

  enum class SpecialItem {
    AGED_BRIE, BACKSTAGE_PASS, SULFURAS
  };

  static const std::map<SpecialItem, std::string> names;
  std::vector<Item> &items;

  ItemController(std::vector<Item> &items);

  void updateSellIn(Item &item);
};

#endif //ITEM_CONTROLLER_H

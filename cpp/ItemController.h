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
    NONE, AGED_BRIE, BACKSTAGE_PASS, SULFURAS
  };

  static const std::map<const SpecialItem, const std::string> names;
  static const SpecialItem specialItemType(const Item &item);

  std::vector<Item> &items;

  ItemController(std::vector<Item> &items);

  void updateSellIn(Item &item);
  void updateQuality(Item &item);
};

#endif //ITEM_CONTROLLER_H

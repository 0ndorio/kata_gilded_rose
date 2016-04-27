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
  static SpecialItem specialItemType(const Item &item);

  ItemController(std::vector<Item> &items);
  void updateItems();

 private:

  std::vector<Item> &items;

  void updateSellIn(Item &item) const;
  void updateQuality(Item &item) const;
};

#endif //ITEM_CONTROLLER_H

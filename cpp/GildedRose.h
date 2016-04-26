#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include <string>
#include <vector>

#include "Item.h"

class GildedRose
{
public:

  std::vector<Item> & items;
  GildedRose(std::vector<Item> & items);
    
  void updateInventory();
  void updateItemSellIn(Item &item);
  void updateItemQuality(Item &item);
};

#endif /* GILDED_ROSE_H */
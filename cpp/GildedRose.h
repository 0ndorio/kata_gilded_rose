#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include <string>
#include <vector>

#include "Item.h"
#include "ItemController.h"

class GildedRose
{
public:

  GildedRose(std::vector<Item> & items);
    
  void updateInventory();
  void updateItemQuality(Item &item);

 private:

  ItemController mItemController;
};

#endif /* GILDED_ROSE_H */
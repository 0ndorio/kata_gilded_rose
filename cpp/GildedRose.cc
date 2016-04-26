#include "GildedRose.h"
#include "ItemController.h"

using SpecialItem = ItemController::SpecialItem;

GildedRose::GildedRose(std::vector<Item> & items)
    : mItemController(items)
{
  for (auto& item : items) {
    if (item.name == ItemController::names.at(SpecialItem::SULFURAS)) {
      item.quality = 80;
      continue;
    }

    if (item.quality < 0) {
      item.quality = 0;
    } else if (item.quality > 50) {
      item.quality = 50;
    }
  }
}

void GildedRose::updateInventory()
{
  for (auto &item : mItemController.items) {
    mItemController.updateSellIn(item);
    mItemController.updateQuality(item);
  }
}

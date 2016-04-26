#include "GildedRose.h"
#include "ItemController.h"

using SpecialItem = ItemController::SpecialItem;

GildedRose::GildedRose(std::vector<Item> & items)
    : mItemController(items)
{}

void GildedRose::updateInventory()
{
  for (auto &item : mItemController.items) {
    mItemController.updateSellIn(item);
    mItemController.updateQuality(item);
  }
}

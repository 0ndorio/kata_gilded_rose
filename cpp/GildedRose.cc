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
    updateItemQuality(item);
  }
}

void GildedRose::updateItemQuality(Item &item)
{
  if (item.name != ItemController::names.at(SpecialItem::AGED_BRIE)
      && item.name != ItemController::names.at(SpecialItem::BACKSTAGE_PASS)) {

    if (item.quality > 0) {
      if (item.name != ItemController::names.at(SpecialItem::SULFURAS)) {
        item.quality = item.quality - 1;
      }
    }
  } else {
    if (item.quality < 50) {
      item.quality = item.quality + 1;

      if (item.name == ItemController::names.at(SpecialItem::BACKSTAGE_PASS)) {
        if (item.sellIn < 10) {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }

        if (item.sellIn < 5) {
          if (item.quality < 50) {
            item.quality = item.quality + 1;
          }
        }
      }
    }
  }

  if (item.sellIn < 0) {
    if (item.name != ItemController::names.at(SpecialItem::AGED_BRIE)) {
      if (item.name != ItemController::names.at(SpecialItem::BACKSTAGE_PASS)) {
        if (item.quality > 0) {
          if (item.name != ItemController::names.at(SpecialItem::SULFURAS)) {
            item.quality = item.quality - 1;
          }
        }
      } else {
        item.quality = item.quality - item.quality;
      }
    } else {
      if (item.quality < 50) {
        item.quality = item.quality + 1;
      }
    }
  }
}


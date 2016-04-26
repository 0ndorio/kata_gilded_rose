#include "ItemController.h"

const std::map<ItemController::SpecialItem, std::string> ItemController::names {
    {SpecialItem::AGED_BRIE, "Aged Brie"},
    {SpecialItem::BACKSTAGE_PASS, "Backstage passes to a TAFKAL80ETC concert"},
    {SpecialItem::SULFURAS, "Sulfuras, Hand of Ragnaros"}
};

ItemController::ItemController(std::vector<Item> &items)
  : items(items)
{}

void ItemController::updateSellIn(Item &item)
{
  if (item.name == ItemController::names.at(SpecialItem::SULFURAS)) {
    return;
  }

  item.sellIn = item.sellIn - 1;
}

void ItemController::updateQuality(Item &item)
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



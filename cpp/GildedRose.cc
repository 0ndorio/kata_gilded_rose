#include "GildedRose.h"

const std::map<SpecialItem::Type, std::string> SpecialItem::names {
    {SpecialItem::Type::AGED_BRIE, "Aged Brie"},
    {SpecialItem::Type::BACKSTAGE_PASS, "Backstage passes to a TAFKAL80ETC concert"},
    {SpecialItem::Type::SULFURAS, "Sulfuras, Hand of Ragnaros"}
};

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{
  for (auto& item : items) {
    if (item.name == SpecialItem::names.at(SpecialItem::Type::SULFURAS)) {
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
  for (auto &item : items) {
    updateItemSellIn(item);
    updateItemQuality(item);
  }
}

void GildedRose::updateItemSellIn(Item &item)
{
  if (item.name == SpecialItem::names.at(SpecialItem::Type::SULFURAS)) {
    return;
  }

  item.sellIn = item.sellIn - 1;
}

void GildedRose::updateItemQuality(Item &item)
{
  if (item.name != SpecialItem::names.at(SpecialItem::Type::AGED_BRIE)
      && item.name != SpecialItem::names.at(SpecialItem::Type::BACKSTAGE_PASS)) {

    if (item.quality > 0) {
      if (item.name != SpecialItem::names.at(SpecialItem::Type::SULFURAS)) {
        item.quality = item.quality - 1;
      }
    }
  } else {
    if (item.quality < 50) {
      item.quality = item.quality + 1;

      if (item.name == SpecialItem::names.at(SpecialItem::Type::BACKSTAGE_PASS)) {
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
    if (item.name != SpecialItem::names.at(SpecialItem::Type::AGED_BRIE)) {
      if (item.name != SpecialItem::names.at(SpecialItem::Type::BACKSTAGE_PASS)) {
        if (item.quality > 0) {
          if (item.name != SpecialItem::names.at(SpecialItem::Type::SULFURAS)) {
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


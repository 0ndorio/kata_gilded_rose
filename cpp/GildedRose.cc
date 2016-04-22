#include "GildedRose.h"

GildedRose::GildedRose(std::vector<Item> & items) : items(items)
{
  for (auto& item : items) {

    if (item.name.find("Sulfuras") != -1) {
      item.quality = 80;
      continue;
    }

    if (item.quality < 0) {
      item.quality = 0;
    }
    else if (item.quality > 50) {
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
  if (item.name == "Sulfuras, Hand of Ragnaros") {
    return;
  }

  item.sellIn = item.sellIn - 1;
}

void GildedRose::updateItemQuality(Item &item)
{
  if (item.name != "Aged Brie" && item.name != "Backstage passes to a TAFKAL80ETC concert") {
    if (item.quality > 0) {
      if (item.name != "Sulfuras, Hand of Ragnaros") {
        item.quality = item.quality - 1;
      }
    }
  } else {
    if (item.quality < 50) {
      item.quality = item.quality + 1;

      if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
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
    if (item.name != "Aged Brie") {
      if (item.name != "Backstage passes to a TAFKAL80ETC concert") {
        if (item.quality > 0) {
          if (item.name != "Sulfuras, Hand of Ragnaros") {
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


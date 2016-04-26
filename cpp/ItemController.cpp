#include <algorithm>

#include "ItemController.h"

//
// Static
//

const std::map<const ItemController::SpecialItem,const std::string> ItemController::names {
    {SpecialItem::AGED_BRIE, "Aged Brie"},
    {SpecialItem::BACKSTAGE_PASS, "Backstage passes to a TAFKAL80ETC concert"},
    {SpecialItem::SULFURAS, "Sulfuras, Hand of Ragnaros"}
};

const ItemController::SpecialItem ItemController::specialItemType(const Item &item)
{
  auto isKnownSpecialItemType =  [item](const auto &entry) -> bool {
    return entry.second == item.name;
  };

  auto iterator = std::find_if(names.begin(), names.end(), isKnownSpecialItemType);
  return names.end() == iterator ? SpecialItem::NONE : (*iterator).first;
}

//
// Instance
//

ItemController::ItemController(std::vector<Item> &items)
  : items(items)
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

void ItemController::updateSellIn(Item &item)
{
  auto type = specialItemType(item);

  switch(type) {
    default: {
      item.sellIn = item.sellIn - 1;
      break;
    }
    case SpecialItem::SULFURAS: {
      break;
    }
  }
}

void ItemController::updateQuality(Item &item)
{
  auto type = specialItemType(item);
  if (type == SpecialItem::SULFURAS) { return; }

  switch(type) {
    default: {
      item.quality = item.sellIn < 0 ? item.quality - 2 : item.quality - 1;
      break;
    }
    case SpecialItem::AGED_BRIE: {
      item.quality = item.sellIn < 0 ? item.quality + 2 : item.quality + 1;
      break;
    }
    case SpecialItem::BACKSTAGE_PASS: {
      item.quality = item.sellIn < 0 ? 0
                       : item.sellIn < 5 ? item.quality + 3
                       : item.sellIn < 10 ? item.quality + 2
                       : item.quality + 1;
      break;
    }
  }

  item.quality = item.quality < 0 ? 0
                   : item.quality > 50 ? 50
                   : item.quality;
}



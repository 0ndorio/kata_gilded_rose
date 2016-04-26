#include "ItemController.h"

const std::map<ItemController::SpecialItem, std::string> ItemController::names {
    {SpecialItem::AGED_BRIE, "Aged Brie"},
    {SpecialItem::BACKSTAGE_PASS, "Backstage passes to a TAFKAL80ETC concert"},
    {SpecialItem::SULFURAS, "Sulfuras, Hand of Ragnaros"}
};

ItemController::ItemController(std::vector<Item> &items)
  : items(items)
{}
#ifndef GILDED_ROSE_H
#define GILDED_ROSE_H

#include <string>
#include <vector>
#include <map>

class Item
{
public:
    std::string name;
    int sellIn;
    int quality;
    Item(std::string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

struct SpecialItem {

  enum class Type {
    AGED_BRIE, BACKSTAGE_PASS, SULFURAS
  };

  static const std::map<Type, std::string> names;
};

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
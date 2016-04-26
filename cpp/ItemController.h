#ifndef ITEM_CONTROLLER_H
#define ITEM_CONTROLLER_H

#include <map>
#include <string>

class ItemController
{
 public:

  enum class SpecialItem {
    AGED_BRIE, BACKSTAGE_PASS, SULFURAS
  };

  static const std::map<SpecialItem, std::string> names;
};

#endif //ITEM_CONTROLLER_H

#include <gtest/gtest.h>
#include "GildedRose.h"

TEST(GildedRoseUnitTest, QualityDecreasesTwiceAsFastAfterSellDatePassed)
{
  int quality = 10;
  int sell_in = 1;

  std::vector<Item> items{{"Generic Item", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_EQ(sell_in - 1, items[0].sellIn);
  EXPECT_EQ(quality - 1, items[0].quality);

  app.updateQuality();
  EXPECT_EQ(sell_in - 2, items[0].sellIn);
  EXPECT_EQ(quality - 3, items[0].quality);
}

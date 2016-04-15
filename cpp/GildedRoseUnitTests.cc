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

TEST(GildedRoseUnitTest, NeverNegativQuality)
{
  int quality = 0;
  int sell_in = 1;

  std::vector<Item> items{{"Generic Item", sell_in, quality}, {"Useless Item", 0, -10}};
  GildedRose app{items};
  EXPECT_EQ(0, items[1].quality);

  app.updateQuality();
  EXPECT_EQ(sell_in - 1, items[0].sellIn);
  EXPECT_EQ(quality, items[0].quality);

  app.updateQuality();
  EXPECT_EQ(sell_in - 2, items[0].sellIn);
  EXPECT_EQ(quality, items[0].quality);
}

TEST(GildedRoseUnitTest, AgedBrieGetsBetterWithAge)
{
  int quality = 0;

  std::vector<Item> items{{"Aged Brie", 0, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_LT(quality, items[0].quality);
}

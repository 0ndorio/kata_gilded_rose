#include <gtest/gtest.h>
#include "GildedRose.h"

//
// General Gilded Rose Tests
//

TEST(GildedRoseUnitTest, QualityAndSellInReducedBy1PerDay)
{
  auto quality = 10;
  auto sell_in = 10;

  std::vector<Item> items{{"Generic Item", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_EQ(sell_in - 1, items[0].quality);
  EXPECT_EQ(quality - 1, items[0].quality);
}

TEST(GildedRoseUnitTest, QualityDecreasesTwiceAsFastAfterSellDatePassed)
{
  auto quality = 10;
  auto sell_in = 1;

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
  auto quality = 0;
  auto sell_in = 1;

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
  auto quality = 0;

  std::vector<Item> items{{"Aged Brie", 1, quality}, {"Aged Brie", 0, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_LT(quality, items[0].quality);
  EXPECT_LT(quality, items[1].quality);
}

TEST(GildedRoseUnitTest, QualityNeverAbove50)
{
  auto quality = 50;

  std::vector<Item> items{{"General Item", 0, 100}, {"Aged Brie", 0, quality}};
  GildedRose app{items};
  EXPECT_EQ(quality, items[0].quality);

  app.updateQuality();
  EXPECT_EQ(quality, items[1].quality);
}

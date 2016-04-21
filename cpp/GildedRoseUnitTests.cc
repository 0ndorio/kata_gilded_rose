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

//
// Special Item Tests
//

TEST(SulfurasTest, QualityAndSellInNeverAlters)
{
  auto quality = 80;
  auto sell_in = 1;

  std::vector<Item> items{{"Sulfuras, Hand of Ragnaros", sell_in, quality}};
  GildedRose app{items};
  EXPECT_EQ(sell_in, items[0].sellIn);
  EXPECT_EQ(quality, items[0].quality);

  app.updateQuality();
  EXPECT_EQ(sell_in, items[0].sellIn);
  EXPECT_EQ(quality, items[0].quality);
}

TEST(SulfurasTest, QualityIsAlways80)
{
  std::vector<Item> items{{"Sulfuras, Hand of Ragnaros", 0, 0}};
  GildedRose app{items};
  EXPECT_EQ(80, items[0].quality);
}

//
// Backstage Pass Tests
//

TEST(BackstagePassTest, QualityIncreasesBy1WhenSellInIsAbove10)
{
  auto quality = 10;
  auto sell_in = 12;

  std::vector<Item> items{{"Backstage passes to a TAFKAL80ETC concert", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_LT(10, items[0].sellIn);
  EXPECT_EQ(quality + 1, items[0].quality);
}

TEST(BackstagePassTest, QualityIncreasesBy2WhenSellInDropsBelow10)
{
  auto quality = 10;
  auto sell_in = 11;

  std::vector<Item> items{{"Backstage passes to a TAFKAL80ETC concert", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_EQ(10, items[0].sellIn);
  EXPECT_EQ(quality + 1, items[0].quality);

  app.updateQuality();
  EXPECT_GT(10, items[0].sellIn);
  EXPECT_EQ(quality + 3, items[0].quality);
}

TEST(BackstagePassTest, QualityIncreasesBy3WhenSellInDropsBelow5)
{
  auto quality = 10;
  auto sell_in = 6;

  std::vector<Item> items{{"Backstage passes to a TAFKAL80ETC concert", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_EQ(5, items[0].sellIn);
  EXPECT_EQ(quality + 2, items[0].quality);

  app.updateQuality();
  EXPECT_GT(5, items[0].sellIn);
  EXPECT_EQ(quality + 5, items[0].quality);
}

TEST(BackstagePassTest, QualityIsZeroAfterTheConcert)
{
  auto quality = 10;
  auto sell_in = 1;

  std::vector<Item> items{{"Backstage passes to a TAFKAL80ETC concert", sell_in, quality}};
  GildedRose app{items};

  app.updateQuality();
  EXPECT_EQ(0, items[0].sellIn);
  EXPECT_LT(quality, items[0].quality);

  app.updateQuality();
  EXPECT_GT(0, items[0].sellIn);
  EXPECT_EQ(0, items[0].quality);
}


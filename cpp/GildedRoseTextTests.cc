#include <gtest/gtest.h>
#include "GildedRose.h"

struct GildedRoseTextOutputTestInterface
{
  /** Number of days to run the shop **/
  int days_to_run;

  /** Expected result of items sell in values and quality levels **/
  std::vector<std::pair<int, int>> expected_results;
};

class GildedRoseTextOutputTest : public ::testing::TestWithParam<GildedRoseTextOutputTestInterface>
{
 public:
  GildedRoseTextOutputTest()
      : items{
      {"+5 Dexterity Vest", 10, 20},
      {"Aged Brie", 2, 0},
      {"Elixir of the Mongoose", 5, 7},
      {"Sulfuras, Hand of Ragnaros", 0, 80},
      {"Sulfuras, Hand of Ragnaros", -1, 80},
      {"Backstage passes to a TAFKAL80ETC concert", 15, 20},
      {"Backstage passes to a TAFKAL80ETC concert", 10, 49},
      {"Backstage passes to a TAFKAL80ETC concert", 5, 49},
      {"Conjured Mana Cake", 3, 6}},
        app(items)
  {}

  void run(int number_of_days)
  {
      for (int day = 0; day < number_of_days; ++day) {
        app.updateInventory();
      }
  }

  void checkExpectedResult(std::vector<std::pair<int, int>> expected_results)
  {
      for (size_t index = 0; index < expected_results.size(); ++index) {
          const auto result = expected_results[index];
          const auto item = items[index];

          EXPECT_EQ(result.first, item.sellIn);
          EXPECT_EQ(result.second, item.quality);
      }
  }

 private:
  /** List of items offered in shop **/
  std::vector<Item> items;

  /** Shop **/
  GildedRose app;
};

TEST_P(GildedRoseTextOutputTest, RunMultipleDays)
{
    auto test_parameters = GetParam();
    run(test_parameters.days_to_run);
    checkExpectedResult(test_parameters.expected_results);
}

INSTANTIATE_TEST_CASE_P(RunMultipleDays, GildedRoseTextOutputTest, ::testing::Values(
    GildedRoseTextOutputTestInterface{10, {
        {0, 10}, {-8, 18}, {-5, 0},
        {0, 80}, {-1, 80}, {5, 35},
        {0, 50}, {-5, 0}, {-7, 0}}},
    GildedRoseTextOutputTestInterface{20, {
        {-10, 0}, {-18, 38}, {-15, 0},
        {0, 80}, {-1, 80}, { -5, 0},
        {-10, 0}, {-15, 0}, {-17, 0}}},
    GildedRoseTextOutputTestInterface{30, {
        {-20, 0}, {-28, 50}, {-25, 0},
        {0, 80}, {-1, 80}, {-15, 0},
        {-20, 0}, {-25, 0}, {-27, 0}}}
));

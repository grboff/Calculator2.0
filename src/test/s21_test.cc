#include <gtest/gtest.h>

#include "../Controller/s21_controller.h"


TEST(Backend, test08) {
  std::string str = "-3-(-4)";
  long double origin = 1;
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, origin);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
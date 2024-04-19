#include <gtest/gtest.h>

#include "../Controller/s21_controller.h"

/*TestPart1*/
TEST(Sum, test1) {
  std::string a = "3.3 + ( 5.0 * 2 )";
  bool error = 0;
  double x = 0;
  bool test_err = false;
  s21::Model m;
  s21::Controller avg(&m);
  if (avg.Start(a, &error, x) == 13.3 and error == false) test_err = true;
  ASSERT_EQ(test_err, 1);
}

// TEST(back, a) {
//   std::string str = "sin(30)+2*3-(5-1)";
//   long double origin = 1.011968375907;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }
TEST(Back, b) {
  std::string str = "2+2.2*54/3+4";
  long double origin = 45.6;
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  EXPECT_NEAR(res, origin, 0.0000001);
}

// TEST(Backend, test01) {
//   std::string str = "sin(cos(2^3))";
//   long double origin = -0.1449871;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

TEST(Backend, test02) {
  std::string str = "sin(cos(2^3)";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

// TEST(Backend, test03) {
//   std::string str = "sqrt(4.12)+asin(0)";
//   long double origin = 2.029778313;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

TEST(Backend, test04) {
  std::string str = "55+3/2";
  long double origin = 56.5;
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  EXPECT_NEAR(res, origin, 0.0000001);
}

// TEST(Backend, test05) {
//   std::string str = "atan(0.5422/23.12)+tan(0.256)+log(2.21)";
//   long double origin = 0.6295825;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

// TEST(Backend, test06) {
//   std::string str = "12+(cos(23.12+sin(12.12-cos(2.21/12))))";
//   long double origin = 11.00962042178;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.00001);
// }

// TEST(Backend, test07) {
//   std::string str = "tan(3.14159/2)";
//   long double origin = 753695.995140;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   EXPECT_NEAR(res, origin, 0.00001);
// }

// TEST(Backend, test08) {
//   std::string str = "-3-(-4)";
//   long double origin = 1;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   ASSERT_EQ(res, origin);
// }

// TEST(Backend, test09) {
//   std::string str = ".";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   control.Start(str, &error, x);
//   ;
//   ASSERT_EQ(error, 1);
// }

TEST(Backend, test10) {
  std::string str = "acos()";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

// TEST(Backend, test11) {
//   std::string str = "sin(3.14159/2)*2.231^3-acos(0.123)";
//   long double origin = 9.65700833938;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.00001);
// }

TEST(Backend, test12) {
  std::string str = "5^2+25/5*6";
  long double origin = 55;
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, origin);
}

// TEST(Backend, test13) {
//   std::string str = "10mod5";
//   long double origin = 0;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

// TEST(Backend, test14) {
//   std::string str = "sqrt(15)";
//   long double origin = 3.8729833;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

// TEST(Backend, test15) {
//   std::string str = "ln(2.718281828459045)";
//   double origin = 0.99999999;
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

// TEST(Backend, test16) {
//   std::string str = "0*3+sin(-55)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 0.9997551, 0.0000001);
// }

// TEST(Backend, test17) {
//   std::string str = "0*3+cos(-55)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 0.022126756262, 0.0000001);
// }

// TEST(Backend, test18) {
//   std::string str = "acos(-1)+53542/4555+(22+1.511)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 38.407148087, 0.0001);
// }

// TEST(Backend, test19) {
//   std::string str = "asin(-1)+53542/4555+(22+1.511)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 33.6947591, 0.0000001);
// }

// TEST(Backend, test22) {
//   std::string str = "sin(22)/cos(22)+5";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 5.0088516, 0.0000001);
// }

// TEST(Backend, test23) {
//   std::string str = "log(10)+ln(5)/sqrt(5)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 1.7197625, 0.0000001);
// }

// TEST(Backend, test24) {
//   std::string str = "75/atan(-5)*7*3*3*2*2*2*2*2";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, -110091.681640989, 0.0000001);
// }

TEST(Backend, test25) {
  std::string str = "3*2*2*2*2*2*";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test26) {
  std::string str = "+7.5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, +7.5);
}

TEST(Backend, test27) {
  std::string str = "7.5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 7.5);
}

// TEST(Backend, test28) {
//   std::string str = "2^cos(2)";
//   bool error = 0;
//   double x = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, 0.74942352, 0.0000001);
// }

TEST(Backend, test29) {
  std::string str = "mod";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test30) {
  std::string str = "5mod0";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test31) {
  std::string str = "5/0";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Singel, test1) {
  std::string str = "-";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Singel, test2) {
  std::string str = "+";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Singel, test3) {
  std::string str = "/";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Singel, test4) {
  std::string str = "*";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Singel, test5) {
  std::string str = "^";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test32) {
  std::string str = "cos(.)";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test33) {
  std::string str = "5^";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test34) {
  std::string str = "---5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test35) {
  std::string str = "++++++5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test36) {
  std::string str = "3*****5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test37) {
  std::string str = "3//5";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test38) {
  std::string str = "3+(5**2)";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(Backend, test39) {
  std::string str = "3-(-3+2)";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
}

TEST(Backend, test40) {
  std::string str = "2^(-5)";
  bool error = 0;
  double x = 0;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 0.03125);
}

TEST(BackendX, test1) {
  std::string str = "x";
  bool error = 0;
  double x = 0.5;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 0.5);
}

TEST(BackendX, test2) {
  std::string str = "x+1";
  bool error = 0;
  double x = 0.5;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 1.5);
}

// TEST(BackendX, test3) {
//   std::string str = "-x+0.5";
//   bool error = 0;
//   double x = 0.5;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   ASSERT_EQ(res, 0);
// }

// TEST(BackendX, test4) {
//   std::string str = "sin(cos(x^3))";
//   long double origin = -0.1449871;
//   bool error = 0;
//   double x = 2;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

// TEST(BackendX, test5) {
//   std::string str = "sin(x)";
//   long double origin = 0.47942553860420301;
//   bool error = 0;
//   double x = 0.5;
//   s21::Model model;
//   s21::Controller control(&model);
//   double res = control.Start(str, &error, x);
//   ASSERT_EQ(error, 0);
//   EXPECT_NEAR(res, origin, 0.0000001);
// }

TEST(BackendX, test6) {
  std::string str = "x^2";
  bool error = 0;
  double x = 2;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 4);
}

TEST(BackendX, test7) {
  std::string str = "x^x";
  bool error = 0;
  double x = 2;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 4);
}

TEST(BackendX, test8) {
  std::string str = "x*2";
  bool error = 0;
  double x = 2.3;
  s21::Model model;
  s21::Controller control(&model);
  double res = control.Start(str, &error, x);
  ASSERT_EQ(error, 0);
  ASSERT_EQ(res, 4.6);
}

TEST(DLS_test, test1) {
  std::string str = "xcos";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test2) {
  std::string str = "2cos";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test3) {
  std::string str = "cosx";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test4) {
  std::string str = "cos2";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test5) {
  std::string str = "coscos(x)";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test6) {
  std::string str = "xcoscos(x)";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test7) {
  std::string str = "coscosx";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

TEST(DLS_test, test8) {
  std::string str = "2.354.36+1";
  bool error = 0;
  double x = 25;
  s21::Model model;
  s21::Controller control(&model);
  control.Start(str, &error, x);
  ASSERT_EQ(error, 1);
}

// TEST(Cred_test, test1) {
//   double loanAmount = 2000000;
//   int term = 180;
//   double interestRate = 8.6;
//   int type = 1;
//   char monthlyPayment[256] = "";
//   double overpayment = 0;
//   double totalPayment = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   control.StartCred(loanAmount, term, interestRate, type, monthlyPayment,
//                     &overpayment, &totalPayment);
//   ASSERT_EQ(totalPayment, 3566196.24);
//   ASSERT_EQ(overpayment, 1566196.24);
//   ASSERT_STREQ(monthlyPayment, "19812.20");
// }

// TEST(Cred_test, test2) {
//   double loanAmount = 2000000;
//   int term = 180;
//   double interestRate = 8.6;
//   int type = 2;
//   char monthlyPayment[256] = "";
//   double overpayment = 0;
//   double totalPayment = 0;
//   s21::Model model;
//   s21::Controller control(&model);
//   control.StartCred(loanAmount, term, interestRate, type, monthlyPayment,
//                     &overpayment, &totalPayment);
//   ASSERT_EQ(totalPayment, 3297166.67);
//   ASSERT_EQ(overpayment, 1297166.67);
//   ASSERT_STREQ(monthlyPayment, "25444.44 ... 11190.74");
// }

// TEST(Graf_test, test1) {
//   s21::Model model;
//   s21::Controller control(&model);
//   std::string str = "x+1";
//   bool error = false;
//   double xBegin = -1;
//   double xEnd = 1;
//   double yBegin = -1;
//   double yEnd = 1;
//   bool result = true;
//   double x = -1;
//   double y = 0;
//   std::vector<std::pair<double, double>> p =
//       control.StartGraf(str, &error, xBegin, xEnd, yBegin, yEnd);
//   for (const auto &pair : p) {
//     y = x + 1;
//     if (x != pair.first) {
//       result = false;
//       break;
//     }
//     if (y != pair.second) {
//       result = false;
//       break;
//     }
//     x += 0.01;
//   }
//   ASSERT_EQ(result, true);
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
// Copyright 2021 Makaryichev Sergey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Makarichev_Sergey_ComplexNumberTest, Multiplication_Of_Conjugates) {
    double re1 = 3.0, re2 = 3.0;
    double im1 = 5.0, im2 = -5.0;
    ComplexNumber num1(3.0, 5.0);
    ComplexNumber num2(3.0, -5.0);

    ComplexNumber cmult = num1 * num2;
    double resutMult = re1 * re1 - im1 * im2;
    ASSERT_DOUBLE_EQ(cmult.getRe(), resutMult);
    ASSERT_DOUBLE_EQ(cmult.getIm(), 0.0);
}

TEST(Makarichev_Sergey_ComplexNumberTest, Equals_Zero) {
    double re1 = 16.89475;
    double im1 = 57.01124;
    ComplexNumber num = ComplexNumber();
    num.setRe(re1);
    num.setIm(im1);

    ComplexNumber cresult = num - num;
    ASSERT_EQ(cresult.getRe() == 0.0, true);
    ASSERT_EQ(cresult.getIm() == 0.0, true);
}

TEST(Makarichev_Sergey_ComplexNumberTest, Arifmetic_Operation_With_Complex) {
    ComplexNumber number1(5.0, 7.0);
    ComplexNumber number2(-2.0, 9.0);
    ComplexNumber number3(5.0, -6.0);

    ComplexNumber cres = number1 * number2 - number3;
  ComplexNumber dres(-78.0, 37.0);

    ASSERT_EQ(dres.getRe(), cres.getRe());
    ASSERT_EQ(cres.getIm(), cres.getIm());
}

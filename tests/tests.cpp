#include "gtest/gtest.h"
#include "../classes/Fraction.h"

TEST(Fraction, DefaultConstructor) {
    Fraction f;
    EXPECT_EQ(0, f.getWhole());
    EXPECT_EQ(0, f.getFractional());
}
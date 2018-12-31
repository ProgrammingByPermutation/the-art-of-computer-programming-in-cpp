#include "pch.h"
#include "permutations.h"

TEST(PermutationTests, MultipleCycles) {
    ASSERT_STREQ(permutations::multiply_cycle("(acfg)(bcd)(aed)(fade)(bgfae)").c_str(), "(adg)(ceb)(f)");
}

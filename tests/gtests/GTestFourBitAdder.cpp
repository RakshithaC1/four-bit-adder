#include <gtest/gtest.h>
#include "FourBitAdder.h"

#include <gtest/gtest.h>
#include "FourBitAdder.h"

// Test fixture for FourBitAdder class
class FourBitAdderTest : public ::testing::Test {
protected:
    FourBitAdder* four_bit_adder;
<<<<<<< Updated upstream
    // SetUp() is called before each test.
    // It initializes the four_bit_adder object
=======

    // Setup the test fixture
>>>>>>> Stashed changes
    void SetUp() override {
        four_bit_adder = new FourBitAdder();
    }

    // Tear down the test fixture
    void TearDown() override {
        delete four_bit_adder;
    }
};

// Test: Adding 0 + 0
TEST_F(FourBitAdderTest, ZeroPlusZero) {
    four_bit_adder->set_input_a(0, 0, 0, 0);
    four_bit_adder->set_input_b(0, 0, 0, 0);
    four_bit_adder->set_carry_in(0);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(0, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(0, four_bit_adder->get_carry_out());
}

// Test: Adding 1 + 1
TEST_F(FourBitAdderTest, OnePlusOne) {
    four_bit_adder->set_input_a(0, 0, 0, 1);
    four_bit_adder->set_input_b(0, 0, 0, 1);
    four_bit_adder->set_carry_in(0);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(1, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(0, four_bit_adder->get_carry_out());
}

// Test: Adding 15 + 1
TEST_F(FourBitAdderTest, FifteenPlusOne) {
    four_bit_adder->set_input_a(1, 1, 1, 1);
    four_bit_adder->set_input_b(0, 0, 0, 1);
    four_bit_adder->set_carry_in(0);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(0, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(1, four_bit_adder->get_carry_out());
}

// Test: Adding 7 + 9
TEST_F(FourBitAdderTest, SevenPlusNine) {
    four_bit_adder->set_input_a(0, 1, 1, 1);
    four_bit_adder->set_input_b(1, 0, 0, 1);
    four_bit_adder->set_carry_in(0);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(0, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(1, four_bit_adder->get_sum(3));
    EXPECT_EQ(0, four_bit_adder->get_carry_out());
}

// Test: Maximum sum with inputs and carry-in
TEST_F(FourBitAdderTest, MaximumSum) {
    four_bit_adder->set_input_a(1, 1, 1, 1);
    four_bit_adder->set_input_b(1, 1, 1, 1);
    four_bit_adder->set_carry_in(1);

    EXPECT_EQ(1, four_bit_adder->get_sum(0));
    EXPECT_EQ(1, four_bit_adder->get_sum(1));
    EXPECT_EQ(1, four_bit_adder->get_sum(2));
    EXPECT_EQ(1, four_bit_adder->get_sum(3));
    EXPECT_EQ(1, four_bit_adder->get_carry_out());
}

// Test: Propagation of carry through the adder
TEST_F(FourBitAdderTest, CarryPropagation) {
    four_bit_adder->set_input_a(1, 0, 1, 1);
    four_bit_adder->set_input_b(0, 1, 0, 1);
    four_bit_adder->set_carry_in(1);

    EXPECT_EQ(1, four_bit_adder->get_sum(0));
    EXPECT_EQ(0, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(1, four_bit_adder->get_carry_out());
}

// Test: Changing inputs and carry-in during operation
TEST_F(FourBitAdderTest, ChangeInputs) {
    four_bit_adder->set_input_a(0, 0, 0, 0);
    four_bit_adder->set_input_b(0, 0, 0, 0);
    four_bit_adder->set_carry_in(0);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(0, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(0, four_bit_adder->get_carry_out());

    four_bit_adder->set_input_a(1, 1, 0, 1);
    four_bit_adder->set_input_b(0, 1, 1, 1);

    EXPECT_EQ(0, four_bit_adder->get_sum(0));
    EXPECT_EQ(1, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(1, four_bit_adder->get_carry_out());

    four_bit_adder->set_carry_in(1);

    EXPECT_EQ(1, four_bit_adder->get_sum(0));
    EXPECT_EQ(1, four_bit_adder->get_sum(1));
    EXPECT_EQ(0, four_bit_adder->get_sum(2));
    EXPECT_EQ(0, four_bit_adder->get_sum(3));
    EXPECT_EQ(1, four_bit_adder->get_carry_out());
}

// Main function to run tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

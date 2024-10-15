#include <gtest/gtest.h>

#include "check_whitespace.h"

void assert_stripped_output(const char* original_input, const char* expected_output) {
    char* stripped_result = strip(original_input);
    ASSERT_STREQ(expected_output, stripped_result);
    free(stripped_result);
}

TEST(strip, EmptyString) {
    assert_stripped_output("", strip(""));
}

TEST(strip, NoWhitespace) {
    assert_stripped_output("frog", strip("frog"));
}

TEST(strip, WhitespaceOnFront) {
    assert_stripped_output("frog", strip("   frog"));
}

TEST(strip, WhitespaceOnBack) {
    assert_stripped_output("frog", strip("frog  "));
}

TEST(strip, WhitespaceOnBothEnds) {
    assert_stripped_output("frog", strip("  frog     "));
}

TEST(is_clean, EmptyString) {
    ASSERT_TRUE(is_clean(""));
}

TEST(is_clean, NoWhitespace) {
    ASSERT_TRUE(is_clean("University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnFront) {
    ASSERT_FALSE(is_clean("   University of Minnesota Morris"));
}

TEST(is_clean, WhitespaceOnBack) {
    ASSERT_FALSE(is_clean("University of Minnesota Morris  "));
}

TEST(is_clean, WhitespaceOnBothEnds) {
    ASSERT_FALSE(is_clean(" University of Minnesota Morris"    ));
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>

#include "check_whitespace.h"

void assert_stripped_output(const char* original_input, const char* expected_output) {
    char* stripped_result = strip(original_input);
    if (stripped_result != NULL) {
        ASSERT_STREQ(expected_output, stripped_result);
    } else {
    }
    free(stripped_result);
}


TEST(assert_stripped_output, EmptyString) {
    ("", "");
}

TEST(strip, NoWhitespace) {
    assert_stripped_output("frog", "frog");
}

TEST(strip, WhitespaceOnFront) {
    assert_stripped_output("   frog", "frog");
}

TEST(strip, WhitespaceOnBack) {
    assert_stripped_output("frog  ", "frog");
}

TEST(strip, WhitespaceOnBothEnds) {
    assert_stripped_output("  frog     ", "frog");
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
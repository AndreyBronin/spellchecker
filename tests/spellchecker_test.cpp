#include <spellchecker/spellchecker.h>
#include <gtest/gtest.h>

using namespace spellchecker;

constexpr const auto originalWord = "triangle";

TEST(spellchecker, wrong_letter_highlighted)
{
    Spellchecker s;
    EXPECT_EQ("trEangle", s.SpellCheck("treangle", originalWord));
    EXPECT_EQ("trianglW", s.SpellCheck("trianglw", originalWord));
    EXPECT_EQ("Zriangle", s.SpellCheck("zriangle", originalWord));
    EXPECT_EQ("5riangle", s.SpellCheck("5riangle", originalWord));
}

TEST(spellchecker, missed_letter_not_highlighted)
{
    Spellchecker s;
    EXPECT_EQ("tiangle", s.SpellCheck("tiangle", originalWord));
    EXPECT_EQ("triangl", s.SpellCheck("triangl", originalWord));
    EXPECT_EQ("riangle", s.SpellCheck("riangle", originalWord));
}

TEST(spellchecker, excess_letters_highlighted)
{
    Spellchecker s;
    EXPECT_EQ("trIianglEe", s.SpellCheck("triianglee", originalWord));
    EXPECT_EQ("trXiangle", s.SpellCheck("trxiangle", originalWord));
    EXPECT_EQ("trXXXiangle", s.SpellCheck("trxxxiangle", originalWord));

}

TEST(spellchecker, swap_letters_highlighted)
{
    Spellchecker s;
    EXPECT_EQ("trAIngle", s.SpellCheck("traingle", originalWord));
    EXPECT_EQ("triangEL", s.SpellCheck("triangel", originalWord));
    EXPECT_EQ("RTiangEL", s.SpellCheck("rtiangel", originalWord));
}

TEST(spellchecker, misspeling_several_letters_highlighted)
{
    Spellchecker s;
    EXPECT_EQ("trEangXe", s.SpellCheck("treangXe", originalWord));
    EXPECT_EQ("SOMEWORD", s.SpellCheck("someword", originalWord));
}

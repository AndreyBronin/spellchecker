#include <spellchecker/spellchecker.h>
#include <gtest/gtest.h>

using namespace spellchecker;

constexpr const auto originalWord = L"треугольник";

class CyrillicFixture : public ::testing::Test
{
protected:
    void SetUp() final
    {
        std::setlocale(LC_ALL, "ru_RU.UTF-8");
    }

    Spellchecker s;
};

TEST_F(CyrillicFixture, wrong_letter_highlighted)
{
    EXPECT_EQ(L"трИугольник", s.SpellCheck(L"триугольник", originalWord));
    EXPECT_EQ(L"треугольниУ", s.SpellCheck(L"треугольниу", originalWord));
    EXPECT_EQ(L"Ьреугольник", s.SpellCheck(L"ьреугольник", originalWord));
    EXPECT_EQ(L",реугольник", s.SpellCheck(L",реугольник", originalWord));
}

TEST_F(CyrillicFixture, missed_letter_not_highlighted)
{
    EXPECT_EQ(L"треуольник", s.SpellCheck(L"треуольник", originalWord));
    EXPECT_EQ(L"треугольни", s.SpellCheck(L"треугольни", originalWord));
    EXPECT_EQ(L"реугольник", s.SpellCheck(L"реугольник", originalWord));

    EXPECT_EQ(L"медвед", s.SpellCheck(L"медвед", L"медведь"));
}

TEST_F(CyrillicFixture, excess_letters_highlighted)
{
    EXPECT_EQ(L"трЕеугольник", s.SpellCheck(L"трееугольник", originalWord));
    EXPECT_EQ(L"треуКгольник", s.SpellCheck(L"треукгольник", originalWord));
    EXPECT_EQ(L"треуголБДЮьник", s.SpellCheck(L"треуголбдюьник", originalWord));

}

TEST_F(CyrillicFixture, swap_letters_highlighted)
{
    EXPECT_EQ(L"треГУольник", s.SpellCheck(L"трегуольник", originalWord));
    EXPECT_EQ(L"треугольнКИ", s.SpellCheck(L"треугольнки", originalWord));
    EXPECT_EQ(L"РТеугольник", s.SpellCheck(L"ртеугольник", originalWord));

    EXPECT_EQ(L"пЕРзидент", s.SpellCheck(L"перзидент", L"президент"));
}

TEST_F(CyrillicFixture, misspeling_several_letters_highlighted)
{
    EXPECT_EQ(L"трИугольнЕк", s.SpellCheck(L"триугольнек", originalWord));

    EXPECT_EQ(L"ЖОПА", s.SpellCheck(L"жопа", L"счастье"));
    EXPECT_EQ(L"прЕвеД", s.SpellCheck(L"превед", L"привет"));
}

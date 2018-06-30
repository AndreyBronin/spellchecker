#include <iostream>
#include <spellchecker/spellchecker.h>

int main()
{
    //std::locale ru = std::locale("ru_RU.UTF-8");
    //std::locale ru = std::locale("");
    //std::wcout.imbue(ru);
    //std::wcin.imbue(ru);

    std::wstring word;
    std::wstring originalWord;

    std::cout << "Type word to check: ";
    std::wcin >> word;

    std::wcout <<  "Type original word: ";
    std::wcin >> originalWord;

    spellchecker::Spellchecker s;
    std::wcout << L"Check result: " << s.SpellCheck(word, originalWord) << std::endl;

    return 0;
}
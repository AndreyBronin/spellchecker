#pragma once

#include <spellchecker/i_spellchecker.h>

namespace spellchecker
{
    class Spellchecker : public ISpellChecker
    {
    public:
        Spellchecker() = default;

        std::string SpellCheck(const std::string &word, const std::string &originalWord) override;
        std::wstring SpellCheck(const std::wstring &word, const std::wstring &originalWord) override;

    };

} // namespace spellchecker

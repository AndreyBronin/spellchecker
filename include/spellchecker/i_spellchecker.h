#pragma once

#include <string>

namespace spellchecker
{

/**
 * SpellChecker interface
 */
    struct ISpellChecker {
        /**
         * SpellChecking method uses fuzzy search algorithm
         * @param word - word to check
         * @param originalWord - word without misspelling
         * @return result word with highlighted(uppercase) wrong letters
         */
        virtual std::string SpellCheck(const std::string &word, const std::string &originalWord) = 0;
        virtual std::wstring SpellCheck(const std::wstring &word, const std::wstring &originalWord) = 0;

        virtual ~ISpellChecker() = default;
    };

} // namespace spellchecker
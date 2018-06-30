#include <spellchecker/spellchecker.h>

#include <algorithm>
#include <cwctype>
#include <vector>

namespace
{
    // FuzzySearch based on Levenshtein distance between two strings.
template <typename T>
T FuzzySearch(const T& word, const T& originalWord)
{
    const auto m = word.length() + 1;
    const auto n = originalWord.length() + 1;
    
    // simulating a matrix with table[i][j] <=> array[i*n + j]
    std::vector<size_t> table(m * n);


#define _table(i,j) table[(i)*n + (j)]

    for (size_t i = 0; i < m; i++)
    {
        _table(i, 0) = i;
    }

    for (size_t j = 0; j < n; j++)
    {
        _table(0, j) = j;
    }


    for (size_t i = 1; i < m; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            size_t diff = word[i - 1] == originalWord[j - 1] ? 1 : 0;

            _table(i, j) = std::min(_table(i - 1, j) + 1,
                         std::min(_table(i, j - 1) + 1, _table(i - 1, j - 1) + 1 - diff));

        }
    }

    T result;
    // Starting from the bottom right corner
    size_t i = m - 1, j = n - 1;
    while (i && j)
    {
        if (_table(i, j) == _table(i - 1, j - 1) && word[i - 1] == originalWord[j - 1])
        {
            result.push_back(word[i - 1]);
            --i; --j;
        }
            // The last several (!) operations have been substitutions
        else if (_table(i, j) == _table(i - 1, j - 1) + 1 && word[i - 1] != originalWord[j - 1])
        {
            while (i && j && _table(i, j) == _table(i - 1, j - 1) + 1 && word[i - 1] != originalWord[j - 1])
            {
                result.push_back(std::towupper(word[i - 1]));
                --i; --j;
            }
        }
            // The last operation has been insertion into word
        else if (_table(i, j) == _table(i, j - 1) + 1)
        {
            --j;
        }
            // The last operation has been deletion from word
        else //_table(i, j) == _table(i, j - 1) + 1
        {
            result.push_back(std::towupper(word[i - 1]));
            --i;
        }
    }

    std::reverse(result.begin(), result.end());

    return result;
#undef _table
}
} //namespace

namespace spellchecker
{
    std::string Spellchecker::SpellCheck(const std::string &word, const std::string &originalWord)
    {
        return FuzzySearch(word, originalWord);
    }

    std::wstring Spellchecker::SpellCheck(const std::wstring &word, const std::wstring &originalWord)
    {
        return FuzzySearch(word, originalWord);
    }

} //namespace spellchecker
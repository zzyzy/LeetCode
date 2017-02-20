/*
 * LeetCode Weekly Contest 20
 * Detect Capital
 * Written by Zhen Zhi Lee in C++11
 */

#include <iostream>

bool IsStringUpper(std::string word) {
    for (auto c : word) {
        if (!isupper(c)) return false;
    }

    return true;
}

bool IsStringLower(std::string word) {
    for (auto c : word) {
        if (isupper(c)) return false;
    }

    return true;
}

bool IsStringCapital(std::string word) {
    if (word.length() > 1) {
        for (auto i = 1; i < word.length(); ++i) {
            if (isupper(word[i])) return false;
        }
        return isupper(word[0]);
    }

    return false;
}

// Naive solution in O(n*3) time
bool DetectCapitalUse(std::string word) {
    return IsStringUpper(word) || IsStringLower(word) || IsStringCapital(word);
}

// Better solution in O(n) time
//bool DetectCapitalUse(const std::string &word) {
//    size_t count = 0;
//    for (auto c : word) { if (isupper(c)) ++count; }
//    return count == word.length() ||        // All letters in this word are capitals
//           count == 0 ||                    // All letters in this word are not capitals
//           count == 1 && isupper(word[0]);  // Only the first letter in this word is capital
//                                            // if it has more than one letter
//}

int main() {
    std::string word;

    std::cin >> word;

    std::cout << std::boolalpha << DetectCapitalUse(word) << std::endl;

    return 0;
}
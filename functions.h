#pragma once

#include <string>
#include <vector>

struct strtWords{
    std::string engWord;
    std::string uaWord;
};

void showMenu();
bool wordExists(const std::vector<strtWords>& words, const std::string& word);
void addWords(std::vector<strtWords>& words);
void showWords(const std::vector<strtWords>& words);
void saveWordstoCSV(const std::vector<strtWords>& words);
void removetrailingSpaces(std::string& str);
void loadwordsfromCSV(std::vector<strtWords>& words);
void testYourself(const std::vector<strtWords>& words);
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>



struct strtWords{
    std::string engWord;
    std::string uaWord;
};

void showMenu() {
    std::cout << "1 - Add word! " << std::endl;
    std::cout << "2 - View vocabulary!" << std::endl;
    std::cout << "3 - Exit!" << std::endl;
    std::cout << "4 - Test yourself!" << std::endl;
    std::cout << "5 - Clear vocabulary!" << std::endl;
    std::cout << "Enter your choice : ";
    }

bool wordExists(const std::vector<strtWords>& words, const std::string& word) 
    {
    for (const strtWords& savedWord : words) 
    {
        if (savedWord.engWord == word) 
            {
            return true;
            }
    }
    return false;
    }
  
void addWords(std::vector<strtWords>& words) 
{
    std::string word;
    std::cout << "Enter a English word or 'exit' for exit): ";
    std::cin >> word;
    while (word != "exit")
    {
        if (wordExists(words, word)) {
        std::cout << "This word already adds!" << std::endl;
        std ::cout << "Enter a English word or 'exit' for exit): ";
        std::cin >> word;
        continue;
        }
    if (word.empty())
        {
        std::cout << "Word cannot be empty!" << std::endl;
        continue;
        }
    strtWords newWord;
    newWord.engWord = word;
    std::cout << "Enter a Ukrainian translation: ";
    std::cin >> newWord.uaWord;

    if (newWord.uaWord.empty())
        {
        std::cout << "Translation cannot be empty!" << std::endl;
        std::cin >> word;
        continue;
        }
    words.push_back(newWord);
    std::cout << "Word added!" << std::endl;   
    std::cout << "Enter a English next word or type 'exit' to return to menu : ";
    std::cin >> word;
    }
}

void showWords(const std ::vector<strtWords>& words) 
    {
        if(words.empty())
            {
                std::cout << "Your vocabulary is empty!" << std::endl; 
            }
        else 
            {std::cout<< "Your vocabulary: " << std::endl;
                for(const strtWords& savedWord : words)
                    {
                        std::cout << savedWord.engWord << " - " << savedWord.uaWord << std::endl;
                    }
            }
    }

void saveWordstoCSV (const std::vector<strtWords>& words)
    {
        std::ofstream file("vocabularystore.csv");
        for(const strtWords& word : words)
        {
            file << word.engWord << " - " << word.uaWord << std::endl;
        }   
    }


void removetrailingSpaces(std::string& str) 
    {
        while (!str.empty() && str.back() == ' ') 
        {
            str.pop_back();
        }
    }
void loadwordsfromCSV(std::vector<strtWords>& words)
    {
        std::ifstream file("vocabularystore.csv");
        if(!file)
        {
            return;
        }

        std::string engWord;
        std::string uaWord;

        while (std ::getline (file, engWord, '-') && std::getline(file, uaWord))
        {
            removetrailingSpaces(engWord);
            removetrailingSpaces(uaWord);
            strtWords word;
            word.engWord = engWord;
            word.uaWord = uaWord;

            words.push_back(word);
        }

    }
void testYourself(const std::vector<strtWords>& words) 
    {
    if (words.empty())
        {
            std::cout << "Vocabulary is empty!" << std::endl;
            return;
        }

        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(0, words.size() - 1);

        int index = dist(gen);

        std::string answer;

        std::cout << "Translate this word: " << words[index].engWord << std::endl;
        std::cout << "Your answer: ";
        std::cin >> answer;

    if (answer == words[index].uaWord)
        {
            std::cout << "Correct!" << std::endl;
        }
    else
        {
            std::cout << "Wrong. Correct answer: " << words[index].uaWord << std::endl;
        }
    }
int main()
{
    std::vector<strtWords> words;
    loadwordsfromCSV(words);
    int menuPoint = 0;

     while(menuPoint !=3){

        showMenu();
        std::cin >> menuPoint;
        if (menuPoint < 1 || menuPoint > 5){
            std::cout << "Invalid choice! Please enter a number between 1 and 5." << std::endl;
            return 1;
        }

        if (menuPoint == 1){
            addWords(words);
            saveWordstoCSV(words);
        }
        else if (menuPoint == 2)
        {
            showWords(words);
        }
        else if (menuPoint == 3)
        {
        std::cout << "Exiting..." << std::endl;
        }
        else if (menuPoint == 4)
        {
            testYourself(words);
        }
        else if (menuPoint == 5)
        {
            words.clear();
            saveWordstoCSV(words);
            std::cout << "Vocabulary cleared!" << std::endl;
        }
    }
return 0;
}
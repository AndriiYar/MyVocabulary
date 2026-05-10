#include <iostream>
#include <string>
#include <vector>
#include <fstream>



struct strtWords{
    std::string engWord;
    std::string uaWord;
};

void showMenu() {
    std::cout << "1 - Add word! " << std::endl;
    std::cout << "2 - View vocabulary!" << std::endl;
    std::cout << "3 - Exit!" << std::endl;
    std::cout << "Enter your choice : ";
    }

void addWords(std::vector<strtWords>& words) {
    std::string word;
    std::cout << "Enter a English word or 'exit' for exit): ";
    std::cin >> word;
    while (word != "exit") 
        {
        strtWords newWord;
        newWord.engWord = word;
        newWord.uaWord = "";
        words.push_back(newWord);
        std::cout << "Word added!" << std::endl;
        std::cout << "Enter a English nextword or type 'exit' to return to menu : ";
        std::cin >> word;
        }
    }

void showWords(const std ::vector<strtWords>& words) {
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
            strtWords word;
            word.engWord = engWord;
            word.uaWord = uaWord;

            words.push_back(word);
        }

    }
int main() {
    std::string word;
    std::vector<strtWords> words;
    loadwordsfromCSV(words);
    int menuPoint = 0;

     while(menuPoint !=3){

        showMenu();
        std::cin >> menuPoint;
        if (menuPoint < 1 || menuPoint > 3){
            std::cout << "Invalid choice! Please enter a number between 1 and 3." << std::endl;
            return 1;
        }

        if (menuPoint == 1){
            addWords(words);
            saveWordstoCSV(words);
        }
        else if (menuPoint == 2){
            showWords(words);
        }
        else if (menuPoint == 3){
        std::cout << "Exiting..." << std::endl;
        }
    }
return 0;
}
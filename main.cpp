#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include <windows.h>
#include "functions.h"


int main()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    
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
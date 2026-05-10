#include <iostream>
#include <string>
#include <vector>

void showMenu() {
    std::cout << "1 - Add word! " << std::endl;
    std::cout << "2 - View vocabulary!" << std::endl;
    std::cout << "3 - Exit!" << std::endl;
    std::cout << "Enter your choice : ";
}

void addWords(std::vector<std::string>& words) {
    std::string word;
    std::cout << "Enter a English word or 'exit' for exit): ";
    std::cin >> word;
    while (word != "exit") {
        words.push_back(word);
        std::cout << "Word added!" << std::endl;
        std::cout << "Enter a English nextword or type 'exit' to return to menu : ";
        std::cin >> word;
    }
}

void showWords(const std ::vector<std::string>& words) {
    if(words.empty())
        {
            std::cout << "Your vocabulary is empty!" << std::endl; 
        }
        else {std::cout<< "Your vocabulary: " << std::endl;
              for(const std::string& savedWord : words)
                {
                 std::cout << savedWord << std::endl;
                }
              }
}
int main() {
    std::string word;
    std::vector<std::string> words;
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
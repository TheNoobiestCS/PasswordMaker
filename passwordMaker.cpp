#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void generateCombinations(const std::vector<std::string>& opts, std::string combination, int k, std::ofstream& file);

int main(){

    int n = 0;

    while(n <= 0 || n > 300){
        std::cout << "Comnbination Length?: ";
        std::cin >> n;
    }

    std::vector<std::string> options(n);
    std::string defaultChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+[]{}|;:',.<>?/";

    for(int i = 0; i < n; i++){
        std::cout << "Chars for position N " << i+1 << " (All together, EOF = pred. char.): ";
        std::getline(std::cin >> std::ws, options[i]);

        if(options[i].empty()){
            options[i] = defaultChars;
        }
    }

    std::ofstream file("combinations.txt");

    for(int i = 1; i <= n; i++){
        generateCombinations(options, "", i, file);
    }

    file.close();

    std::cout << "Combinations saved in 'combinations.txt'." << std::endl;

    return 0;
}

void generateCombinations(const std::vector<std::string>& opts, std::string combination, int k, std::ofstream& file){
    if(k == 0){
        file << combination << std::endl;
        std::cout << combination << std::endl;
        return;
    }

    std::string availableChars = opts[k-1];

    for(int i = 0; i < availableChars.length(); i++){
        std::string newCombination = combination + availableChars[i];
        generateCombinations(opts, newCombination, k-1, file);
    }
}



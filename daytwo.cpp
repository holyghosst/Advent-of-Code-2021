#include <iostream>
#include <fstream>
#include <string>

int main() {
    int depth{0};
    int horizontal{0};
    int aim{0};

    std::ifstream file("inputday2");
    std::string s;

    while(std::getline(file, s)) {
        if(s.find("forward") != std::string::npos) {
            horizontal += (int) s.at(8) - '0';
            depth += aim * (s.at(8) - '0');
            
        }
        else if(s.find("down") != std::string::npos) {
            aim += (int) s.at(5)- '0';
        }
        else {
            aim -= (int) s.at(3)- '0';
        }
        
    }
    std:: cout << depth << " " << horizontal << "\n";
    std::cout << depth*horizontal;
    return 0;
}
#include <iostream>
#include <vector>
#include <fstream>

int main() {
    std::vector<int> input = {};
    int result{0};

    std::ifstream infile("input");
    int data;
    while(infile >> data) {
        input.push_back(data);
    }
    
    for(int i = 0; i < input.size() - 3; i++) {
        int a = input.at(i) + input.at(i+1) + input.at(i+2);
        int b = input.at(i+1) + input.at(i+2) + input.at(i+3);
        if(b > a) result++;
    }
    std::cout << result;

    /*  First Star 
    for(int i{0}; i < input.size() - 1; i++) {
        if(input[i+1] > input[i]) result++;
    }
    std::cout << result;
    */


    return 0;
}
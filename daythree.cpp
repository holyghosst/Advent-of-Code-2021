#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

int bin_to_dec(std::string n) {
    int base{1};
    int ret{0};

    for(int i = n.length() - 1; i >= 0; i--) {
        if(n.at(i) == '1') ret += base;
        base *= 2;
    }
    return ret;
}

void first_part() {
    std::string gamma = "";
    std::string epsilon = "";
    std::string one;

    std::vector<std::string> input_vc = {};
    std::ifstream input("day3input");
    while(std::getline(input, one)) {
        input_vc.push_back(one);
    }

    for(int letter{0}; letter < 12; letter++) {
            int ones{0};
            int zeros{0};
        for(auto& word  : input_vc) {
            if(word.at(letter) == '0') zeros++;
            else ones++;
            
        }
        gamma += (ones > zeros) ? '1' : '0';
    }
    for(auto& c: gamma) {
        if (c == '0') epsilon += '1';
        else epsilon += '0';
    }

    std::cout << bin_to_dec(gamma) * bin_to_dec(epsilon);
}

bool contains(std::string s, std::string sub) {
    for(size_t i{0}; i < sub.length(); i++ ) {
        if(s.at(i) != sub.at(i)) return false;
    }
    return true;
}

void del_notsubstring(std::vector<std::string> &v, std::string substring) {
    v.erase(std::remove_if(v.begin(), v.end(), [&substring](std::string& el){
        return !contains(el, substring);
    }), v.end());
}

int main(){
    std::string control_oxy;
    std::string control_scr;
    std::vector<std::string> input_first = {};
    std::vector<std::string> input_second = {};
    std::string one;
    
    std::ifstream input("day3input");
    while(std::getline(input, one)) {
        input_first.push_back(one);
        input_second.push_back(one);
    }
    
    for(int letter{0}; letter < 12; letter++) {
            int ones{0};
            int zeros{0};
        for(auto& word  : input_first) {
            if(word.at(letter) == '0') zeros++;
            else ones++;
        }

        if(ones >= zeros) {
            control_oxy += '1';
        }
        else if(zeros > ones) {
            control_oxy += '0';
        }
        if(input_first.size() == 1) break;
        del_notsubstring(input_first,control_oxy);
    }
    control_oxy = input_first.at(0);

    for(int letter{0}; letter < 12; letter++) {
            int ones{0};
            int zeros{0};
        for(auto& word  : input_second) {
            if(word.at(letter) == '0') zeros++;
            else ones++;
        }

        if(ones >= zeros) {
            control_scr += '0';
        }
        else if(zeros > ones) {
            control_scr += '1';
        }
        if(input_second.size() == 1) break;
        del_notsubstring(input_second,control_scr);
    }
    control_scr = input_second.at(0);
    std::cout << bin_to_dec(control_oxy) * bin_to_dec(control_scr);

    return 0;
}
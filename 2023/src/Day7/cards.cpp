#include<iostream>
#include<fstream>
#include<string>
#include<regex>
#include<unordered_map>

int rankCards() {
  static const unordered_map<string, int> mapping = {
    {"A", 13}, {"K", 12}, {"Q", 11}, {"J", 10}, {"T", 9}, {"9", 8},
    {"8", 7}, {"7", 6}, {"6", 5}, {"5", 4}, {"4", 3}, {"3", 2}, {"2", 1}
  }

  auto it = mapping.find(hand);

  if (it != mapping.end()) {
    return it->second;
  }

  return -1;
  
}

int rankHand(string& hand) {
  
  
}

int main() {
  std::string line;
  std::ifstream file("input.txt");
  std::string highestCard;
  std::string highestHand;

  if(file.is_open()) {
    while (getline(file, line)) {
      regex pattern("^//S+");
      sregex_iterator it(line.begin(), line.end(), pattern);
      sregex_iterator end;

      while (it != end) {
        smatch result = *it;
        string hand = result.str();

        rankHand(hand);
        


        ++it;
      }
    }
  }
}

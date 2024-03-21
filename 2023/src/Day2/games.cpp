#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/regex.hpp>
#include <unordered_map>

using namespace std;

int possibleGames(string& line, int& game) {

    int highestRedPossible = 0;
    int highestGreenPossible = 0;
    int highestBluePossible = 0;

    boost::regex pattern("(\\d+) (red|blue|green)");
    boost::sregex_iterator it(line.begin(), line.end(), pattern);
    boost::sregex_iterator end;

    while (it != end)
    {
      boost::smatch match = *it;
      int number = stoi(match[1].str());
      string color = match[2].str();

      if (color == "green" && number > highestGreenPossible) {
        highestGreenPossible = number;
      } else if (color == "blue" && number > highestBluePossible) {
        highestBluePossible = number;
      } else if (color == "red" && number > highestRedPossible) {
        highestRedPossible = number;
      }

      ++it;
    }

    return highestBluePossible * highestRedPossible * highestGreenPossible;
}

int colorCheck(string& line, int& game) {
    int maxRed = 12;
    int maxGreen = 13;
    int maxBlue = 14;
    bool possible;
  
    boost::regex pattern("(\\d+) (red|blue|green)");
    boost::sregex_iterator it(line.begin(), line.end(), pattern);
    boost::sregex_iterator end;

    while (it != end)
    {
      boost::smatch match = *it;
      int number = stoi(match[1].str());
      string color = match[2].str();

      if (color == "green" && number > maxGreen) {
        return 0;
      } else if (color == "blue" && number > maxBlue) {
        return 0;
      } else if (color == "red" && number > maxRed) {
        return 0;
      } else {
        possible = true;
      }

      ++it;
    }

    if (possible == true) {
      return game;
    } else {
      return 0;
    }
}

int main () {
  string line;
  string strResult;
  int sum = 0;
  int game = 1;
  int result = 0;

  ifstream file("input.txt");

  if (file.is_open()) {
    while (getline(file, line)) {

      int colorMatch = colorCheck(line, game);
      int possible = possibleGames(line, game);

      result += possible;
      sum += colorMatch;
      ++game;
    }
  }
  cout << "Total sum of possible games " << sum << endl;
  cout << "Sum of the power of highest numbers of cube in each game: " << result << endl;
}
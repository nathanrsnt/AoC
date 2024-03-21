#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cctype>
#include <string>

int main() {
	long long int sRemain = 0;
	
  std::string line;
  std::ifstream file("input.txt");
  std::vector<long long int> time;
  std::vector<long long int> distance;
  std::vector<long long int> possibleGames;

  if(file.is_open()) {
    while (getline(file, line)) {

      //search for number and store in time vector 
      std::istringstream stream(line); 
      char character;
      long long int number;
      char firstLetter = line[0];
      
      while (stream >> std::skipws >> character) {
        if (std::isdigit(character)) {
          stream.unget();
          stream >> number;
          if (firstLetter == 'T') {
            time.push_back(number);
          } else {
            distance.push_back(number);
          }
        } else {
          stream.ignore();
        }
      }
    }

    //concatenating results for time and distance
    std::string resultT;
    std::string resultD;

    for (size_t i = 0; i < time.size(); ++i) {
      resultT += std::to_string(time[i]);
    }
    
    time.clear();
    long long int intTime = stoll(resultT, nullptr);
    time.push_back(intTime);

    for (size_t i = 0; i < distance.size(); ++i) {
      resultD += std::to_string(distance[i]);
    }

    distance.clear();
    long long int intDistance = stoll(resultD, nullptr);
    distance.push_back(intDistance);
    
    // show results
    //std::cout << "resultT: " << resultT << std::endl;
    //std::cout << "resultD: " << resultD << std::endl;


    for (auto i = time.begin(); i != time.end(); i++) {
      long long int totalRecord = 0;

      //brute force check
      for (int j = 0; j < *i; j++) {
        long long int msPressing = j;
        long long int totalTravel = 0;

        totalTravel = msPressing * (*i - msPressing);
        
        if (totalTravel > distance.at(std::distance(time.begin(), i))) {
          //testing
          std::cout << "Record travel: " << totalTravel
          << " at: " << *i << "s" << " With distance to beat: " 
          << distance.at(std::distance(time.begin(), i)) 
          << " holding button for: " << msPressing << "s" << std::endl;

          totalRecord++;
        }
      }

      possibleGames.push_back(totalRecord);
    }

    long long int result = 1;
    std::cout << "Possible Games: ";
    if (!possibleGames.empty()) {
      for (size_t i = 0; i < possibleGames.size(); ++i) {
        result *= possibleGames[i];
        std::cout << possibleGames[i] << " ";
      }
    }

    std::cout << std::endl << result << std::endl;
  }
}
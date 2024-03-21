#include <iostream>
#include <fstream>
#include <vector>

int main () {
	std::string line;
	std::vector<int> values;
	std::ifstream file("input.txt");
	
	//populate vector values
	
	if(file.is_open()) {
		while(getline(file, line)) {
			std::vector<int> lastV;
			std::vector<int> valueBfr;
			int dif = 0;
			int zeroCheck = 0;
			bool allZ = false;
			
			for (int i = 0; i != values.end(); i++) {
				if (values[i] == 0) {
					zeroCheck++;
					allZ = true;
				}	
			}
			
			
			for (int i = 0; i != values.end(); i++) {
				dif = values[i+1] - values[i]; 
				lastV.push_back(dif);
				
				if (i == values.end()) {
					valueBfr.push_back(values[i]);
				}
			}
			
			for (int i = 0; i != lastV.end(); i++) {
				
			}
		}
	}
}

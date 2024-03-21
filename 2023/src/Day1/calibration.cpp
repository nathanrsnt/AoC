#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <unordered_map>

using namespace std;

int converter (const string& word) {
	static const unordered_map<string, int> mapping = {
		{"zero", 0}, {"one", 1}, {"two", 2},
		{"three", 3}, {"four", 4}, {"five", 5}, 
		{"six", 6}, {"seven", 7}, {"eight", 8}, 
		{"nine", 9}
	};

	auto it = mapping.find(word);

	if (it != mapping.end()) {
		return it->second;
	}

	return -1;
}

int regexSearch(ifstream& file, ofstream& outfile) {
	string line;
	string replaceString;
	static const unordered_map<string, string> mapping = {
		{"zero", "0o"}, {"one", "1e"}, {"two", "2o"},
		{"three", "3e"}, {"four", "4r"}, {"five", "5e"}, 
		{"six", "6x"}, {"seven", "7n"}, {"eight", "8t"}, 
		{"nine", "9e"}
	};

	if (file.is_open()) {
		while (getline (file, line)) {
			regex pattern("(zero|one|two|three|four|five|six|seven|eight|nine)"); 
			sregex_iterator it(line.begin(), line.end(), pattern);
			sregex_iterator end;

			while (it != end) {
				smatch result = *it;
				string strResult = result.str();

				auto itM = mapping.find(strResult);

				if (itM != mapping.end()) {
					 line.replace(result.position(), result.length(), itM->second);
				}

				++it;
			}

			outfile << line << endl;
		}
	}

	return 0;
}

int main () {
	string line;
	string strResult;
	vector<int> v;
	int add = 0;
	int intResult = 0;
	int lines = 1;
	
	ifstream initfile ("input.txt");
	ofstream outfile ("new_input.txt");
	regexSearch(initfile, outfile);
	initfile.close();
	outfile.close();

	ifstream newfile ("new_input.txt");
	if (newfile.is_open()) {
		while (getline (newfile, line)) {
			regex pattern("(zero|one|two|three|four|five|six|seven|eight|nine|[1-9])"); 
			sregex_iterator it(line.begin(), line.end(), pattern);
			sregex_iterator end;

			while (it != end) {
				smatch result = *it;
				strResult = result.str();

				if (regex_match(strResult, regex("(one|two|three|four|five|six|seven|eight|nine)"))) {
						intResult = converter(result.str());
				} else {
					if (!strResult.empty() && strResult.find_first_not_of("0123456789") == string::npos) {
					  intResult = stoi(result.str());
					} else {
						cerr << "Error: invalid value - " << strResult << endl;
					}
				}

				v.push_back(intResult);
				++it;
			}

			string f = to_string(v.front());
			string b = to_string(v.back());

			string sr = f + b;
			int ir = stoi(sr);

			
			cout << lines << " - " << ir << endl;
			add = add + ir;

			v.clear();
			++lines;
		}

		cout << "Result: " << add << endl;
		newfile.close();
	} else {
		cout << "Error opening file";
	}

	return 0;
}

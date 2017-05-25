#include <iostream>
#include <fstream>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Compilor{
	vector <string> swords;
	ifstream infile;
	ofstream outfile;
	public:
		Compilor(char* filename);
		void parse();
		void printFile();
		void printState(vector<string> stateWord);
		void printAssignation(vector<string> assignWord);
		void printCondition(vector<string> condWord);
};
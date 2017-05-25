#include "compilor.h"

using namespace std;


Compilor::Compilor(char* filename){
	swords = {"take", "transition", "When", "you", "are", "in", "State:","Strategy", "to", "avoid", "losing:"};
	infile.open(filename,ifstream::in);
	outfile.open("fileout.cpp", ofstream::out);
	printFile();
		
}

void Compilor::parse(){
	int k = 0;
	vector<string> state;
	vector<string> assignation;
	vector<string> condition;
	string word = "";
	string word2 ="";
	bool begin = false;
	bool st = false;
	bool cond = false;
	bool assign = false;
	char c;
	string line;
	if (infile){
		outfile<< "\t" <<"/** Automatically generated**/"<<endl;
		while (!infile.eof()){
			getline(infile, line);
			if (begin ==true){
				int i = 0;
				line = line +"\n";
				while (line[i]){
					char c = line[i];
					if (c == '\n'){
						if (line == "\n"){
							word = "";
							word2 = "";
							break;
						}
						if (st == true || assign == true){
							c = ' ';
						}
						else{
							word += "";
							break;
						}
					}
					if (c== ' '){
						if (!(find(swords.begin(), swords.end(), word) != swords.end())){
							if (st == true){state.push_back(word);}
							else if (cond == true){condition.push_back(word);}
							else if (assign == true){assignation.push_back(word);}
							word2="";
						}
						else{word2 += (word + " ");}

						if (word2 == "State: "){
							cout<<"state"<<endl;
							st = true;
							cond = false;
							assign = false;
							if (!state.empty()){
								if (k > 0){
									outfile << "\t}\n";
								}
								k++;
								printState(state);
								state.clear();
							}
							word2 ="";
					
						}
						else if (word2 == "When you are in "){
							st = false;
							cond = true;
							assign = false;
							if (!state.empty()){
								if (k > 0){
									outfile << "\t}\n";
								}
								k++;
								printState(state);
								state.clear();
							}
							if (!condition.empty()){
								printCondition(condition);
								condition.clear();
							}
							word2 ="";
					
						}
						else if (word2 == "take transition "){
							st = false;
							cond = false;
							assign = true;
							if (!assignation.empty()){
								printAssignation(assignation);
								assignation.clear();
							}
							word2 ="";
					
						}
						word = "";
						
					}
					else{word += c;}
					
					i++;
				}
			}
			if (line == "Strategy to avoid losing:"){
				begin = true;
			}
		}
	}
}
void Compilor::printFile(){
	if (outfile.is_open()){
		outfile<<"#include <iostream>\n";
		outfile<<"bool controlCondition(Worker[] Worker, WorkerSalary[] WorkerSalary, Company Company){\n";
		parse();
		outfile<<"}";
	}
}

void Compilor::printCondition(vector<string> condWord){
	outfile<<"\t\tif";
	for (unsigned int i = 0; i < condWord.size(); i++){
		string word = condWord[i];
		for(int j = 0; j < word.size(); ++j) {
			char c = word[j];
			if (c == '(' && (word[j-1] != ' ') && j > 0){
				outfile<<'[';
			}
			else if (c == ')' && word[j-1] != ' ' && j > 0 && j<word.size()-2){
				
				outfile<<']';	
			}
			else if (j == word.size()-1 && word[j] == ','){
				outfile<<"";
			}
			
			else{
				outfile << c;
			}
			
		}
		outfile << ' ';

	}
	outfile<<"\n";
}
void Compilor::printState(vector<string> stateWord){
	outfile << "\tif (";
	for (unsigned int i = 0; i < stateWord.size(); i++){
		string word = stateWord[i];
		if (word != " " && word != "" && word != "\n"){
			if (word != "(" && word!= ")"){
				for(int j = 0; j < word.size(); ++j) {
					char c = word[j];
					if (c == ')'){
						outfile<<']';
					}
					else if (c == '('){
						outfile<<'[';
					}
					else if (c == '='){
						outfile<<"==";
					}
					else if (c == '.'){
						bool point = false;
						string word2 = "";
						for (int k = j+1; k < word.size(); k++){
							char c2 = word[k];
							if (c2 == '='){
								word2 += c2;
								point = true;
							}
							if (c == ')'){
								c2 = ']';
							}
							else if (c == '('){
								c2 = ']';
							}
							word2 +=c2;
						}
						if (point == true){
							outfile << ("." + word2);
						}
						else{
							outfile<<(".state == \""+ word2+ "\"");
						}
						break;
					
					
					}
					else{
						outfile<<c;
					}
					
				
				}	
			}
		}
		if (i < stateWord.size()-2 && i>0){
			outfile<<" && ";
		}
	}
	outfile<< ")\n\t{\n";
}


void Compilor::printAssignation(vector<string> assignWord){
	string word = assignWord[0];
	bool beg = false;
	string word4 = "";
	outfile<<"\t\t{\n\t\t\t";
	for(int j = 0; j < word.size(); ++j) {
		char c = word[j];
		if (beg == true){
			if (c == '.'){
				string word2 = "";
				for (int k = j+1; k < word.size(); k++){
					char c2 = word[k];
					word2 +=c2;
				}
				outfile<<(".state = \""+ word2+ "\"");
				j = word.size();
				break;
			}
			else if (c == '('){
				c = '[';
			}
			else if (c == ')'){
				c = ']';
			}
			word4 += c;
				
			outfile<<c;
		}
					
		if (j < (word.size()-1) && c == '-' && word[j+1] == '>'){
			beg = true;
			cout << "okkkk" <<endl;
			j+=1;
		}			
	}
	outfile<<";\n";
	string word2 = "";
	for (unsigned int i = 1; i < assignWord.size(); i++){
		string word3 = assignWord[i];
		if (word3 != "tau," && word3 != "{" && word3 != "}"){
			word2 += word3;
		}
	}
	outfile<<("\t\t\treturn takeTransition("+ word4 + ",\""+ word2+"\");\n\t\t}\n");
}
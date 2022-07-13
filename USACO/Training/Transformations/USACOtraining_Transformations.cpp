/*
ID: michaelwong11
PROG: transform
LANG: C++14 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> firstRotation(const vector<string> &input) {

	const int N = input.size();

	vector<string> horizontal;

	for(int i = 0; i < N; i++){

		string horizontalRow;

		for(int j=0; j < N; j++) {

			const string & str = input[j];

			horizontalRow += str[i];

		}

	reverse(horizontalRow.begin(), horizontalRow.end());

	horizontal.push_back(horizontalRow);

	}

	return horizontal;
}

vector<string> reflect(const vector<string> &input){
	vector<string> newInput;
	for(string elem: input){
		reverse(elem.begin(), elem.end());
		newInput.push_back(elem);
	}
	return newInput;
}





int main() {
	ofstream fout("transform.out");
	ifstream fin("transform.in");
	int N;
	fin >> N;
	vector<string> input;
	vector<string> output;
	for(int i = 0; i < N; i++){
		string stringTmp;
		fin >> stringTmp;
		input.push_back(stringTmp);
	}
	for(int i = 0; i < N; i++){;
		string stringTmp;
		fin >> stringTmp;
		output.push_back(stringTmp);
	}
	vector<string> final = firstRotation(input);
	vector<string> reflected = firstRotation(reflect(final)); 


	if (final == output){
		fout << 1 << endl;
	}
	else if (firstRotation(final) == output){
		fout << 2 << endl;
	}
	else if (firstRotation(firstRotation(final)) == output){
		fout << 3 << endl;
	}
	else if (input == output){
		fout << 6 << endl;
	}

	else if(reflect(input) == output){
		fout << 4 << endl;
	}

	else if(reflected == output){
		fout << 5 << endl;
	}

	else if (firstRotation(reflected) == output){
		fout << 5 << endl;
	}
	else if (firstRotation(firstRotation(reflected)) == output){
		fout << 5 << endl;
	}
	else {
		fout << 7 << endl;
	}
	// for(auto elem:reflect(input)){
	// 	cout << elem << endl;

	// }

	// vector<string> reversedFinal = firstRotation(input);
	// else if (&reversedFinal == &output){
	// 	fout << 5 << endl;
	// } 
	// else if (firstRotation(&reversedFinal) == &output){
	// 	fout << 5 << endl;
	// }
	// else if (firstRotation(firstRotation(&reversedFinal)) == &output){
	// 	fout << 5 << endl;
	// }
	// else {
	// 	fout << 7 << endl;
	// }


}


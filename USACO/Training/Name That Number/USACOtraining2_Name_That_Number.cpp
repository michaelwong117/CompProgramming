 /*
ID: michaelwong11
PROG: namenum
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<size_t> getDigits(long long num){
	long long numTest = num;
	vector<size_t> digits;
	while (numTest != 0){
		digits.push_back(numTest%10);
		numTest /= 10;
	}

	return digits;
}
//if nothing returns empty string
vector<string> checkInFile(long long number){

	vector<string> usedDigits;

	const string sec("ABC");
	const string third("DEF");
	const string fourth("GHI");
	const string fifth("JKL");
	const string six("MNO");
	const string sev("PRS");
	const string eig("TUV");
	const string nin("WXY");

	const vector<string> touchTone = {sec, third, fourth, fifth, six, sev, eig, nin};
	vector<size_t> v = getDigits(number);
	reverse(v.begin(), v.end());
	// for(int elem: v){
	// 	cout << elem << endl;
	// }

	ifstream fin("dict.txt");
	for (size_t elem: v){
		usedDigits.push_back(touchTone[elem-2]);
		// cout << touchTone[elem-2] << " " << elem << endl;
	}
	vector<string> final;
	while(!fin.eof()){
		string input;
		string output;
		fin >> input;
		if(input.length() == usedDigits.size()){
			// cout << "input = " << input << endl;
			for(size_t j = 0; j < input.length(); j++){
				const string check = usedDigits[j];
				if(find(check.begin(), check.end(), input[j]) != check.end()){
					// cout << "input[j] = " << input[j] << "; check = " << check << endl;
					output += input[j];
				}
				else {
					break;
				} 
			}
			if(output == input){
				final.push_back(output);
			}
			
		}

	}
	return final;
}

int main() {

	ofstream fout("namenum.out");
	ifstream fin("namenum.in");
	long long N;
	fin >> N;
	// cout << "N= " << N << endl;
	const vector<string> output = checkInFile(N);

	if(!output.empty()){
		for(const string & elem: output){
			fout << elem << endl;
		}
	}
	else{
		fout << "NONE" << endl;
	}

}

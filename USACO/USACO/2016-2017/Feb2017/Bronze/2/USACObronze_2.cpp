#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ofstream fout("circlecross.out");
	ifstream fin("circlecross1.in");

	string N;
	fin >> N;
	vector<int> notSecond;
	int pairs = 0;

	for(int i=0;i<N.length();i++){
		//the position of the second occurence of the character
		if (find(notSecond.begin(), notSecond.end(), i) == notSecond.end()){
			int first = N[i];
			int second = N.find(N[i], i+1);
			string smallN = N.substr(i, second);

			for(auto elem: smallN){
				if(smallN.find(elem, i+1) == string::npos){
					pairs++;


				}
			}
			notSecond.push_back(second);
		}
		


		//cout << "second = " << second << endl;
		//if (second == i+1){
		//	N.erase(i)
		//	N.erase(second);
		//	continue;
	
		




	}
	fout << pairs << endl;







}
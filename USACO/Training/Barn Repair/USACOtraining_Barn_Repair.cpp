/*
ID: michaelwong11
PROG: barn1
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<int, int> gapCount(int C){
	ifstream fin("barn1.in");
	int M;
	int S;
	int occupied;
	fin >> M >> S >> occupied;

	map<int, int> startEnd;
	vector<int> stalls;
	for(int i = 0; i < C; i++){
		int stall;
		fin >> stall;
		stalls.push_back(stall);
	}
	sort(stalls.begin(), stalls.end());
	for(int j = 0; j < stalls.size() - 1; j++){
		if((stalls[j+1] - stalls[j]) > 1){
			// cout << stalls[j+1] << endl;

			startEnd[stalls[j]] = stalls[j+1];
		}
	}
	return startEnd;
}

vector<int> getInput(){
	ifstream fin("barn1.in");
	int M;
	int S;
	int C;
	fin >> M >> S >> C;
	vector<int> input;
	for(int i = 0; i < C; i++){
		int num;
		fin >> num;
		input.push_back(num);
	}
	return input;
}

int main(){

	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int M; //max num of boards
	int S; //num of stalls
	int C; //num of occupied stalls (cows)
	fin >> M >> S >> C;
	map<int, vector<int>, greater<int>> gaps;
	map<int,int> startEnd = gapCount(C);
	for(const auto &elem: startEnd){
		if(gaps[elem.second - elem.first].size() == 0){
			gaps[elem.second - elem.first] = {elem.first, elem.second};
		}
		else{
			vector<int> value = gaps[elem.second-elem.first];
			//using the size of value to check if there are multiple occurences of a key.
			value.push_back(elem.second-elem.first);
			gaps[elem.second-elem.first] = value;
		
		}
		//cout << elem.first << " " << elem.second << " " << elem.second - elem.first << endl;
		//cout << gaps[elem.second - elem.first][0] <<  " " << gaps[elem.second - elem.first][1] << endl;
	}
	int i = 0;
	vector<int> occupiedStalls = getInput();
	sort(occupiedStalls.begin(), occupiedStalls.end());
	// for(auto elem: occupiedStalls){
	// 	cout << elem << endl;
	// }
	int max = *max_element(occupiedStalls.begin(), occupiedStalls.end());
	int min = *min_element(occupiedStalls.begin(), occupiedStalls.end());
	// fout << max << " " << min << endl;
	int range = max - min + 1;
	// cout << range << endl;
	for(auto &elem: gaps){
		
		while((elem.second.size() > 2) && (i < (M-1))){
			range -= (elem.first - 1);
			elem.second.erase (elem.second.begin()+elem.second.size() - 1);
			cout << elem.first << endl;
			i++;

		}
		if(i >= (M - 1)){
			break;
		}
		range -= (elem.first - 1);
		cout << elem.first << endl;
		i++;



	}
	fout << range << endl;

		// fout << "gap = " << elem.first << endl;
		// fout << elem.second[0] << " " << elem.second[1] << endl;



}
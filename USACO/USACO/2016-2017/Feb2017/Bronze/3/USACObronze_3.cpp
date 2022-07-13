#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ofstream fout("cowqueue.out");
	ifstream fin("cowqueue.in");
	int N;
	fin >> N;
	map<int, int> sortedtimes;
	int minTime;
	int pastSum = 0;
	for(int i = 0; i<N; i++){
		int arrival;
		int processing;
		fin >> arrival >> processing;
		sortedtimes[arrival] = processing;

	}
	for (map<int,int>::iterator it=sortedtimes.begin(); it!=sortedtimes.end(); ++it){
		if(it == sortedtimes.begin()){
			pastSum = it->first + it->second;
		}
		else{
			int first = it->first;

			if(first > pastSum){
				pastSum = first + it->second;
			}
			else {
				pastSum = pastSum + it->second;
			}
		}
		minTime = pastSum;
		//cout << minTime << endl;

	}
	fout << minTime << endl;



}
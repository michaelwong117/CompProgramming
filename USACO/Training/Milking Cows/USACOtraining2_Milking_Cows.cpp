/*
ID: michaelwong11
PROG: milk2
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval {


	Interval(int l, int h) : low(l), high(h){}

	int low;
	int high;
};

struct Compare {
	inline bool operator() (const Interval& interval1, const Interval& interval2){
		return (interval1.low < interval2.low);	
	}



};





int main() {
	int N;  // Number of cows.
	int milkingTime = 0, maxMilk = 0;
	int idleTime = 0, maxIdle = 0;
	int diff, maxDiff = 0;
	int s = 0, t = 0;
	int pastStartingTime;
	int oldFinish;
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	fin >> N;
	vector <Interval> vec;
	for(int i = 0; i < N; ++i){
		int start;
		int finish;
		fin >> start >> finish;
		vec.push_back(Interval(start, finish));
	}
	sort(vec.begin(), vec.end(), Compare());


	// Start processing.

	// Special case -- work on the 1st interval.
	const Interval & currentInterval = vec[0];
	int startingTime = currentInterval.low;
	pastStartingTime = startingTime;
	int finish = currentInterval.high;
	oldFinish = finish;
	milkingTime += finish - startingTime;
	maxMilk = milkingTime;

	// Process 2nd interval to the last.
	for (int i = 1; i < vec.size(); i++){

		//currentInterval.low is start, currentInterval.high is finish.
		//fout << elem.low <<  ", " << elem.high << endl;

		const Interval & currentInterval = vec[i];

		int startingTime = currentInterval.low;

		int finish = currentInterval.high;

		diff = finish - startingTime;


		if (diff >= maxDiff){

			maxDiff = diff;

		}

		if (oldFinish >= startingTime){
			// 2 intervals overlap.

			//all other overlapping cases
			if(finish > oldFinish) {
				milkingTime += (finish - oldFinish);
			}

		} else {
			//cout << oldFinish << " " << startingTime << endl;
			milkingTime = 0;

			//cout << maxDiff << " " << idleTime << endl;
			idleTime = startingTime - oldFinish;

		}


		oldFinish = finish;
		pastStartingTime = startingTime;

		if (milkingTime > maxMilk){
			maxMilk = milkingTime;

		}
		if (idleTime > maxIdle){
			maxIdle = idleTime;
			//cout << maxIdle << endl;
		}

	}
	fout << maxMilk << " " << maxIdle << endl;

	
		


	
	return 0;

}














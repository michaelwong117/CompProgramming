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
	//don't do milkingtime, do high and low
	int milkingTime, maxMilk;
	int unionlow, unionhigh;
	//same with idle
	int idleTime, maxIdle = 0;
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

	int finish = currentInterval.high;
	unionlow = startingTime;
	unionhigh = finish;
	//instead of milkingTime, implement milking high and low and subtract
	milkingTime += unionhigh - unionlow;
	maxMilk = milkingTime;

	// Process 2nd interval to the last.
	for (int i = 1; i < vec.size(); i++){

		//currentInterval.low is start, currentInterval.high is finish.
		//fout << elem.low <<  ", " << elem.high << endl;

		const Interval & currentInterval = vec[i];

		int startingTime = currentInterval.low;

		int finish = currentInterval.high;


		if (unionhigh >= startingTime){
			// 2 intervals overlap.

			//all other overlapping cases
			if(finish > unionhigh) {
				//implement the high and low of milk
				unionhigh += finish - unionhigh;

			}

		} else {
			//check gap between high interval and new union
			//set the intervals to zero
			milkingTime = unionhigh - unionlow;
			idleTime = startingTime - unionhigh;
			unionlow = startingTime;
			unionhigh = finish;
			

		}




		if (milkingTime > maxMilk){
			maxMilk = milkingTime;

		}
		if (idleTime > maxIdle){
			maxIdle = idleTime;

		}

	}
	fout << maxMilk << " " << maxIdle << endl;

	
		


	
	return 0;

}














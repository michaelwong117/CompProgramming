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

using namespace std;

int main() {
	ofstream fout("milk2.out");
	ifstream fin("milk2.in");
	int N;
	int milkingTime = 0, maxMilk = 0;
	int idleTime = 0, maxIdle = 0;
	int pastStartingTime;
	int oldFinish;
	//int maxFinish = 0;
	//int leastStart = 999999;
	fin >> N;

	for(int i = 0; i < N; ++i){
		int startingTime;
		int finish;

		fin >> startingTime >> finish;
		if(i == 0){
			pastStartingTime = startingTime;
			oldFinish = finish;	
		}

		//if (finish > maxFinish){
		//	maxFinish = finish;
		//}
		//if (startingTime < leastStart){
		//	leastStart = startingTime;
		//}


		if (oldFinish >= startingTime){

			if(i == 0){
				milkingTime += finish - startingTime;
			}
			else {
				milkingTime += (finish - oldFinish);
			}


		}
		else {
			idleTime = (startingTime - oldFinish);
			milkingTime = 0;

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
}









}

/*
ID: michaelwong11
PROG: wormhole
LANG: C++14     
*/
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int N;
vector<int> X(13), Y(13), pairs(13), nextInCycle(13);
bool checkCycle(){
	for(int i = 1; i <= N; i++){
		int cur = i;
		for(int j = 0; j<N; j++){
			cur = nextInCycle[pairs[cur]];

		}
		if(cur != 0){
			return true;
		}
	}
	return false;


}
int wormhole(){
	int i, sum = 0;
	for(i = 1; i <= N; i++){
		if(pairs[i] == 0){
			break;
		}
	}
	if(i > N){
		if(checkCycle()){
			return 1;
		}
		else{
			return 0;
		}
	}
	for(int j = i+1; j <= N; j++){
		if(pairs[j] == 0){
			pairs[i] = j;
			pairs[j] = i;
			sum += wormhole();
			pairs[i] = 0;
			pairs[j] = 0;
		}
	}
	return sum;
}
int main(){
	ofstream fout("wormhole.out");
	ifstream fin("wormhole.in");
	fin >> N;
	for(int i = 1; i<= N; i++){
		fin >> X[i] >> Y[i];
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if((X[j] > X[i])&&(Y[j] == Y[i])){
				if((nextInCycle[i] == 0) || (X[j] - X[i] < X[nextInCycle[i]] - X[i])){
					nextInCycle[i] = j;
				}
			}
		}
	}

	fout << wormhole() << endl;

	

}
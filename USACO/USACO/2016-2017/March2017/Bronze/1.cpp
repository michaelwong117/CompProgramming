
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;
//remember to use fin and fout
int computeDistance(int x, int y, int distance){
	if(x == y){
		return 0;
	}
	int distanceT = 0;
	int i = 1;
	int v = 1;
	if(x > y){
		while(x > y){
			distanceT += i + (i / 2);
			if((x <= y+i) &&(v % 2 == 0)){
				break;
			}
			i = 2*i;
			v++;
			//increase y until it reaches x
		}
		if((y+i)-x > 0){
			distanceT -= (y+i) - x;
		}
	}
	else if(y > x){
		while(y > x){
			distanceT += i + (i / 2);
			if((y <= x+i) &&(v % 2 != 0)){
				break;
			}
			i = 2*i;
			v++;
			//increase x until it reaches y
		}
		if((x+i)-y > 0){
			distanceT -= (x+i) - y;
		}
 

	}
	return distanceT;
}

int main(){

	ofstream fout("lostcow.out");
	ifstream fin("lostcow.in");
	int x;
	int y;
	fin >> x >> y;
	int distance = abs(x-y);
	fout << computeDistance(x, y, distance) << endl;


}
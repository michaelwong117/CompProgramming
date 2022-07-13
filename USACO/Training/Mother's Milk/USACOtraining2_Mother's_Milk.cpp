/*

ID: michaelwong11
PROG: milk3
LANG: C++14

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
using namespace std;




int main(){
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");
	int A, B, C;
	fin >> A >> B >> C;

	int capacityA = A;
	int capacityB = B;
	int capacityC = C;
	set<int> cval;
	if(B >= A){


		int fit = B / A;
		int remain = B % A;
		cval.insert(C);
		
		if(fit != 0){
			for(int i = 0; i < fit; i++){
				if(C - (i+1)*A > 0){
					cval.insert(C - (i+1)*A);
				}
				
			}
		}
	}
	else{
		int fit = A / B;
		int remain = A % B;
		cval.insert(C);
		cval.insert(C-A);
		if(fit != 0){
			for(int i = 0; i < fit; i++){
				if(C - (i+1)*B > 0){
					cval.insert(C - (i+1)*B);
				}
				
			}
		}
	}
	for(auto a: cval){
		fout << a << " ";
	}





}
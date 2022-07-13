/*
ID: michaelwong11
PROG: beads
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
	ofstream fout ("beads.out");
	ifstream fin ("beads.in");

	int N, count = 0, total = 1, a = 0, max = 0, start = -1, whites = 0;

 	fin >> N;
 	string beads;
 	fin >> beads;


 	char prev = beads[0];
 	int i = 1;
 	for(i = 1; i < 2*N; i++){
 		// cout << i << endl;
 		
 		if(count > 1){
 			i = start;
 			prev = beads[i % N];

 			count = 0;
 			i++;
 			// i % N = i % N;
 			// cout << i << endl;
 			// cout << i % N << endl;
 		}

 		
 		

 		if(prev == 'w' && beads[i % N] != 'w'){
 			prev = beads[i % N];
 		}
 		//if the bead you are looking at is white and start is invalid 
 		//start is invalid if you haven't seen a white bead previously
 		//with no breaks
 		if(beads[i % N] == 'w'){
 			whites++;
 			// cout << whites << endl;
 		}
 		if(beads[i % N] != 'w'){
 			whites = 0;
 		}
 		if(beads[i % N] != 'w' && beads[i % N] != prev){
 			count++;
 			if(count > 1){
 				if(total > max){
 					max = total;
 				}
 				// cout << i << " furthest " << N+a << endl;
 				// i % N = start % N;
 				i = start;
 				cout << "newcycle " << start << endl;
 				// cout << whites << endl;
				total = 1;
				prev = beads[i % N];
 				// cout << prev << endl;
				// count = 0;
 			}
 			else{
 				// cout << start << endl;

				start = i;
 				
 				// cout << "halfcycle " << start << endl;
 				total++;
 			}
			
		
 			prev = beads[i % N];
 		}
 		else{
 			total++;
 		}
 		cout << i << " " << beads[i % N] << " " << total << endl;
 		
 		
 		

 	}
 	
 	fout << max << endl;

}
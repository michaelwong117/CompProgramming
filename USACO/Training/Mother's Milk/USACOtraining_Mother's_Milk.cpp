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


set<int> cval;
vector<vector<int>> seen;
// int i;

//pours bucket2 into bucket1
bool vContains(vector<vector<int>> seen, vector<int> sequence){
	for(auto a: seen){
		if(a == sequence){
			return true;
		}
	}
	return false;
}
vector<int> pour(int bucket1, int capacity1, int bucket2, int capacity2){
	int x = bucket1;
	int y = bucket2;
	while((x < capacity1)&&(y > 0)){
		x++;
		y--;

	}
	return {x, y};

}
void generateStates(int A, int B, int C, int capacityA, int capacityB, int capacityC){
	//generate all possible states of the three buckets
	// i++;
	// cout << A << " " << B << " " << C << " " << i << endl;
	// cout << a << " " << b << " " << c << endl;
	if(C != 0){
		if(A != capacityA){
			vector<int> newVal = pour(A, capacityA, C, capacityC);
			if(!vContains(seen, {newVal[0], B, newVal[1]})){
				seen.push_back({newVal[0], B, newVal[1]});
				generateStates(newVal[0], B, newVal[1], capacityA, capacityB, capacityC);
			}
		}
		if(B != capacityB){
			vector<int> newVal = pour(B, capacityB, C, capacityC);
			if(!vContains(seen, {A, newVal[0], newVal[1]})){
				seen.push_back({A, newVal[0], newVal[1]});
				generateStates(A, newVal[0], newVal[1], capacityA, capacityB, capacityC);
			}
			
		}
	}

	if(A != 0){
		//pouring A into B
		if(B != capacityB){
			vector<int> newVal = pour(B, capacityB, A, capacityA);
			if(!vContains(seen, {newVal[1], newVal[0], C})){
				seen.push_back({newVal[1], newVal[0], C});
				generateStates(newVal[1], newVal[0], C, capacityA, capacityB, capacityC);
			}
			

		}
		if(C != capacityC){
			vector<int> newVal = pour(C, capacityC, A, capacityA);
			if(!vContains(seen, {newVal[1], B, newVal[0]})){
				seen.push_back({newVal[1], B, newVal[0]});
				generateStates(newVal[1], B, newVal[0], capacityA, capacityB, capacityC);
			}
			
		}
	}

	if(B != 0){
		//pouring A into B
		if(A != capacityA){
			vector<int> newVal = pour(A, capacityA, B, capacityB);
			if(!vContains(seen, {newVal[0], newVal[1], C})){
				seen.push_back({newVal[0], newVal[1], C});
				generateStates(newVal[0], newVal[1], C, capacityA, capacityB, capacityC);
			}

		}
		if(C != capacityC){
			vector<int> newVal = pour(C, capacityC, B, capacityB);
			if(!vContains(seen, {A, newVal[1], newVal[0]})){
				seen.push_back({A, newVal[1], newVal[0]});
				generateStates(A, newVal[1], newVal[0], capacityA, capacityB, capacityC);
			}

		}
		
	}
}


int main(){
	ofstream fout("milk3.out");
	ifstream fin("milk3.in");
	int a, b, c;
	fin >> a >> b >> c;
	int capacityA = a;
	int capacityB = b;
	int capacityC = c;

	// cout << capacityA << " " << capacityB << " " << capacityC << endl;
	// fout << A << " " << B << " " << C << endl;

	generateStates(0, 0, c, capacityA, capacityB, capacityC);
	// generateStates(8, 0, 2);

	for(auto v: seen){
		// cout << v[0] << " " << v[1] << " " << v[2] << endl;
		if(v[0] == 0){
			cval.insert(v[2]);
		}
	}
	int i = 0;
	for(auto c: cval){
		if(i == 0){
			fout << c;
		}
		else{
			fout << " " << c;
		}
		i++;
	}
	fout << "\n";
	// cout << pour(0, 9, 8, 8)[0] << " " <<  pour(0, 9, 8, 8)[1] << endl;
	
	

	
}
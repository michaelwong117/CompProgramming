#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map> 


using namespace std;


int main(){

	int n;
	cin >> n;

	vector<int> rooms (n+1);
	rooms[0] = 1;
	int roomCount = 1;
	for(int i = 1; i < n+1; i++){
		int t;
		cin >> t;
		if(rooms[t] != 0){
			rooms[i] = rooms[t];
			rooms[t] = 0;
		}
		else{
			roomCount++;
			rooms[i] = 1;
		}

	}

	cout << roomCount << endl;




}
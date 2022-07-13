#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;


int main(){
	// ifstream fin("numbers.cpp");
	int n;
	cin >> n;

	int pastwin;
	cin >> pastwin;
	int spectate = 3;
	bool valid = true;
	if(pastwin == spectate){
		cout << "NO" << endl;
		valid = false;
	}
	else{
		for(int i = 1; i < n; i++){
			vector<int> vec = {1, 2, 3};
			int win;
			cin >> win;
			vec.erase(remove(vec.begin(), vec.end(), win), vec.end());
			vec.erase(remove(vec.begin(), vec.end(), spectate), vec.end());
			if(win != pastwin){
				if(win != spectate){
					cout << "NO" << endl;
					valid = false;
					break;
				}
			}
			
			if(vec.size() > 1){
				vec.erase(remove(vec.begin(), vec.end(), pastwin), vec.end());
			}
			spectate = vec[0];
			
			pastwin = win;
			

			
		}
	}

	if(valid){
		cout << "YES" << endl;
	}




}
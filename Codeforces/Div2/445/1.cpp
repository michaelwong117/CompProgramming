#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>


using namespace std;


int main(){
	bool valid = false;
	
	vector<int> scores;
	for(int i = 0; i < 6; i++){
		int a;		
		cin >> a;
		scores.push_back(a);
		
	}

	vector<int> possibleTeams;

	
 	for(int i = 0; i < scores.size()-3; i++){

		for(int j = i+1; j < scores.size()-2; j++){
			
			for(int z = j+1; z < scores.size()-1; z++){
				vector<int> copy = scores;
				int sum = 0;
				copy.erase(copy.begin() + i);
				copy.erase(copy.begin() + j-1);
				copy.erase(copy.begin() + z-2);
				for(auto c: copy){
					sum += c;
				}
				if(scores[i] + scores[j] + scores[z] == sum){
					cout << "YES" << endl;
					valid = true;
					break;
				}
				
				
			}
			if(valid){
				break;
			}
		}
		if(valid){
			break;
		}
	}
	// for(auto a: possibleTeams){
	// 	if(count (possibleTeams.begin(), possibleTeams.end(), a) > 1){
	// 		cout << "YES" << endl;
	// 		valid = true;
	// 		break;
	// 	}
		
	// }
	if(!valid){
		cout << "NO" << endl;
	}
	


	
}
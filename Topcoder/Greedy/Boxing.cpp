#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;


class Boxing {
	public:
   	int maxCredit(vector<int> a, vector<int> b,
   		vector<int> c, vector<int> d, vector<int> e);       
};
int Boxing::maxCredit(vector<int> a, vector<int> b,
   			vector<int> c, vector<int> d, vector<int> e) {
	vector<vector<int>> v = {a, b, c, d, e};
	int count = 0;
	int rightLimit = 0;
	while(1){
		vector<int> T;
		for(int i = 0; i < v.size(); i++){
			//find the first three button presses
			while(!v[i].empty() && v[i][0] <= rightLimit){
				v[i].erase(v[i].begin());
			}
			if(v[i].empty()) continue;
			if(T.size() < 3){
				T.push_back(v[i][0]);
			}
			else{
				//finding min button presses
				vector<int>::iterator it = max_element(T.begin(), T.end());
				if(*it > v[i][0] && *it ){
					// cout << *it << endl;
					// cout << T[it-T.begin()] << " " << it-T.begin() << endl;
					T[it-T.begin()] = v[i][0];
				} 
			}
		}
		//if exists call it a button press
		if(T.size() == 3){
			for(auto a: T){
				cout << a << " ";
			}
			cout << endl;
			count++;
			rightLimit = *max_element(T.begin(), T.end());
		}
		//else there are no more verifiable punches left
		else{
			return count;
		}
	}
}
int main(){
	Boxing instanceOfClass;
	// vector<int> a = {10000000, 30000000, 40000000};
	// vector<int> b = {};
	// vector<int> c = {2, 3};
	// vector<int> d = {};
	// vector<int> e = {1, 5};
	int out = instanceOfClass.maxCredit({180000}, {1, 2, 3, 4, 5, 6, 179000, 179500, 179800}, {5, 10, 1000, 10000}, {5, 10, 1000, 10000}, {6, 9000});
	cout << out << endl;

}



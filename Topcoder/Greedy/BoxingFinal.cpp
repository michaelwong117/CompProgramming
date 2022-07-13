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

int search(vector<int> v, int st){
	for(int i = 0; i < v.size(); i++){
		if(v[i] >= st){
			return v[i];
		}
	}
	return 10000000;
}


class Boxing {
	public:
   	int maxCredit(vector<int> a, vector<int> b,
   		vector<int> c, vector<int> d, vector<int> e);       
};
int Boxing::maxCredit(vector<int> a, vector<int> b,
   			vector<int> c, vector<int> d, vector<int> e) {
	vector<vector<int>> v = {a, b, c, d, e};
	int count = 0;
	for(int st = 0; st <= 180000; st++){
		vector<int> times (5);

		times[0] = search(a, st);
				
		times[1] = search(b, st);

		times[2] = search(c, st);

		times[3] = search(d, st);

		times[4] = search(e, st);

		sort(times.begin(), times.end());
		//interval at least a thousand
		if(times[2] <= st+1000){
			cout << times[0] << " " << times[1] << " " << times[2] << endl;
			count++;
			st = times[2];

		}
	}
	return count;
	
}
// int main(){
// 	Boxing instanceOfClass;
// 	// vector<int> a = {10000000, 30000000, 40000000};
// 	// vector<int> b = {};
// 	// vector<int> c = {2, 3};
// 	// vector<int> d = {};
// 	// vector<int> e = {1, 5};
// 	int out = instanceOfClass.maxCredit({180000}, {1, 2, 3, 4, 5, 6, 179000, 179500, 179800}, {5, 10, 1000, 10000}, {5, 10, 1000, 10000}, {6, 9000});
// 	cout << out << endl;

// }



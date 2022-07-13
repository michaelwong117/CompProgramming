#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int,int> pii;

set<vector<int>> all;

vector<int> shuffle(vector<int> &org, vector<int> &order){
	vector<int> temp = org;
	for(int i = 0; i < org.size(); i++){
		temp[order[i]-1] = org[i];
	}
	return temp;
}
void printV(vector<int> &v){
	for(int i = 0; i < v.size(); i++) cout << v[i] << " " << i+1 << endl;
}

void permute(vector<int> &final, int l, int r){
	if(l == r){
		all.insert(final);
		// printV(final);
	}
	else{
		for(int i = 0; i <= r; i++){
			swap(final[l], final[i]);
			permute(final, l+1, r);
			swap(final[l], final[i]);
		}
	}

}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N;
	fin >> N;
	vector<int> shuffles (N);
	vector<int> final;
	for(int i = 0; i < N; i++){
		fin >> shuffles[i];
		// cout << shuffles[i] << endl;
	}
	for(int i = 0; i < N; i++){
		int a;
		fin >> a;
		final.push_back(a);
	}

	permute(final, 0, final.size()-1);
	// cout << all.size() << endl;
	// for(auto f: final) cout << f << endl;
	// vector<int> res = {1234567, 2222222, 3333333, 4444444, 5555555};
	for(auto a: all){
		vector<int> temp = a;
		// if(a == res){
		// 	for(auto a: temp) cout << a << endl;
		// }
		for(int i = 0; i < 3; i++){
			temp = shuffle(temp, shuffles);
			// printV(temp);
		}
		// for(int i = 0; i < temp.size(); i++)
		// 	cout << temp[i] << " " << final[i] << endl;
		if(temp == final){
			for(auto t: a)
				fout << t << endl;
			// cout << "found" << endl;
			// printV(a);
			// cout << "manual" << endl;
			// vector<int> manual = {1234567, 5555555,2222222,3333333,4444444};
			// printV(manual);
			for(int i = 0; i < 3; i++){
				a = shuffle(a, shuffles);
				// manual = shuffle(manual, shuffles);
				// cout << "found" << endl;
				// printV(a);
				// cout << "manual" << endl;
				// printV(manual);

			}
			return 0;
		}
	}
	//for every ordering up to 100
	//do three shuffles and check if it matches up


}
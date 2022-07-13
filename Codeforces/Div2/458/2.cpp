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

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	cin >> n;
	vector<int> v (n);
	int max = -99999;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(v[i] > max){
			max = v[i];
		}
	}
	int c = 0;
	map<int, int> m;
	for(int i = 0; i < v.size(); i++){
		if(v[i] == max){
			c++;
		}
	}
	if(c == 1){
		cout << "Conan" << endl;
	}
	else if(c == v.size()){
		if(c % 2 == 0){
			cout << "Agasa" << endl;
		}
		else{
			cout << "Conan" << endl;
		}
	}
	else{
		if(c % 2 == 1){
			cout << "Conan" << endl;
		}
		else{
			for(int i = 0; i < v.size(); i++){
				if(m.count(v[i]) == 0){
					m[v[i]] = 1;
				}
				else{
					m[v[i]]++;
				}
			}
			for(auto x: m){
				if(x.sec % 2 != 0){
					cout << "Conan" << endl;
					return 0;
				}
			}
			cout << "Agasa" << endl;
		}
	}

	
	
}
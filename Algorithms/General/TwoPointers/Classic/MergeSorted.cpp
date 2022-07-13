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
#define MOD 1e9 + 7


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	vector<int> s1 = {1, 4, 5, 9, 12}, s2 = {1, 3, 4, 5, 5, 9, 20}, final;
	int i = 0, j = 0;
	while(i != s1.size() || j != s2.size()){
		if(i == s1.size()){
			final.push_back(s2[j]);
			j++;
			continue;
		}
		if(j == s2.size()){
			final.push_back(s1[i]);
			i++;
			continue;
		}
		if(s1[i] < s2[j]){
			final.push_back(s1[i]);
			i++;
		}
		else{
			final.push_back(s2[j]);
			j++;
		}
	}
	for(auto a: final){
		cout << a << " ";	
	}
	cout << endl;

}
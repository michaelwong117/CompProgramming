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
typedef pair<int, string> pis;


vector<string> findMax(map<string, int> &m){
	vector<string> out;
	int max = -99999;
	for(auto x: m){
		if(x.sec > max){
			max = x.sec;
		}
	}
	out.push_back(to_string(max));
	for(auto x: m){
		if(x.sec == max){
			out.push_back(x.fir);
		}
	}
	return out;
}

string getName(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '-' || s[i] == '+'){
			return s.substr(0, i);
		}
	}
	return s;
}
string getChange(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '-' || s[i] == '+'){
			return s.substr(i, s.length()-i+1);
		}
	}
	return s;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int N;
	fin >> N;
	map<string, int> milk;

	vector<pis> v;
	for(int i = 0; i < N; i++){
		int a;
		string name, increase;
		fin >> a >> name >> increase;
		milk[name] = 7;
		v.push_back(pis(a, name+increase));

	}
	int count = 0; 
	sort(v.begin(), v.end());
	// for(auto a: v){
	// 	cout << a.fir << " " << a.sec << endl;
	// }
	vector<string> max = findMax(milk);
	for(int i = 0; i < v.size(); i++){
		// cout << milk[getName(v[i].sec)] << endl;
		milk[getName(v[i].sec)] += stoi(getChange(v[i].sec));
		// cout << milk[getName(v[i].sec)] << endl;
		vector<string> newmax = findMax(milk);
		if(max[0] != newmax[0]){
			count++;
			max = newmax;
		}
		else{
			sort(max.begin(), max.end());
			sort(newmax.begin(), newmax.end());
			for(int i = 0; i < max.size(); i++){
				if(max[i] != newmax[i]){
					count++;
					max = newmax;
					break;
				}
			}
		}
	}
	// cout << findMax(milk) << endl;
	fout << count << endl;

}
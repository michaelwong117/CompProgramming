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


int findMax(map<string, int> &m){
	int nmax = -99999999;
	for(auto x: m){
		if(x.sec > nmax){
			nmax = x.sec;
		}
	}
	return nmax;
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
	int max = 7;
	for(int i = 0; i < v.size(); i++){
		if(milk[getName(v[i].sec)] == max){
			if(stoi(getChange(v[i].sec)) > 0){
				int c = 0;
				// cout << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;

				// cout << nmax << " " << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
				for(auto x: milk){
					if(x.sec == max){
						c++;
					}
				}
				milk[getName(v[i].sec)] += stoi(getChange(v[i].sec));
				max = milk[getName(v[i].sec)];
			
				if(c > 1){
					// cout << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
					count++;
				}
			
			}	

			else{
				milk[getName(v[i].sec)] += stoi(getChange(v[i].sec));
				//if the top cow drops but it still stays the max alone
				//then don't increment the count
				//else increment the count
				int nmax = findMax(milk), c = 0;
				// cout << nmax << " " << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
				if(nmax == max){
					// cout << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
					count++;
				}
				else if(nmax != max){
					for(auto x: milk){
						if(x.sec == max){
							c++;
						}
					}
					max = nmax;

				}
				if(c > 0){
					// cout << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
					count++;
				}


			}
		}
		else{
			milk[getName(v[i].sec)] += stoi(getChange(v[i].sec));
			if(milk[getName(v[i].sec)] >= max){
				// cout << getName(v[i].sec) << " " << getChange(v[i].sec) << endl;
				count++;
				max = milk[getName(v[i].sec)];
			}
		}
		//if the maximum milk changes or another cow gets the maximum milk
		//then add to the count
		//store the cows that have maximum milk

	}
	// cout << findMax(milk) << endl;
	fout << count << endl;

}
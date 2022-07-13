/*
ID: michaelwong11
PROG: preface
LANG: C++14     
*/
//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;

vector<map<int,int>> numeral;
vector<int> num = {1, 5, 10, 50, 100, 500, 1000};
string st = "IVXLCDM";


void split(map<int, int> &roman, int sum){
	for(auto &a: roman){
		a.s = 0;
	}
	int i = 0;
	// if(sum == 45){
	// 	cout << "TESTING " << sum << endl << endl;
	// 	while(sum){
	// 		cout << sum%10 << " " << pow(10, i) << endl;
	// 		int j = 0;
	// 		for(auto &a: numeral[(sum%10)*(pow(10, i))]){
	// 			cout << num[j] << " " << roman[num[j]] << " " << a.s << endl;
	// 			roman[num[j]] += a.s;
	// 			j++;
	// 		}
	// 		i++;
	// 		sum /= 10;
	// 	}
	// 	for(auto a: roman){
	// 		cout << a.f << " " << a.s << endl;

	// 	}
	// 	cout << endl << endl;
	// }
	while(sum){
		int j = 0;
		for(auto a: numeral[(sum%10)*(pow(10, i))]){
			roman[num[j]] += a.s;
			j++;
		}
		i++;
		sum /= 10;
	}
	

}

void check(map<int, int> &roman, int sum){
	auto end = roman.end();
	end--;
	for(int i = 1; i < num.size(); i++){
		if(sum >= num[i]-num[i-1] && sum < num[i] && num[i] > 10 && sum % 10 != 0){
			split(roman, sum);
		}
		if(sum == num[i]-num[i-1] && sum != num[i-1]){
			roman[num[i]] = 1;
			roman[num[i-1]] = 1;

		}
		if(i > 1){
			if(sum >= num[i]-num[i-2] && sum < num[i] && sum % 10 != 0){
				split(roman, sum);
			}
			if(sum == num[i]-num[i-2] && sum != num[i-2]){
				roman[num[i]] = 1;
				roman[num[i-1]] = 0;
				roman[num[i-2]] = 1;
			}
		}

	}
	// if(sum == 45){
	// 	for(auto a: roman){
	// 		cout << a.f << " " << a.s << endl;
	// 	}
	// }
	bool five = 1;
	for(auto it = roman.begin(); it != end; it++){
		if(five){
			if(it->s >= 5){
				it->s -= 5;
				*next(it)++;
				five = 0;
			}
		}
		else{
			if(it->s >= 2){
				it->s -= 2;
				*next(it)++;
				five = 1;
			}
		}
	}

}

void solve(){
	for(int i = 1; i < numeral.size(); i++){
		for(int i2 = num.size()-1; i2 >= 0; i2--){
			if(i-num[i2] >= 0){
				numeral[i] = numeral[i-num[i2]];
				numeral[i][num[i2]]++;
				check(numeral[i], i);
				// if(i == 45){
				// 	for(auto a: numeral[i]){
				// 		cout << a.f << " " << a.s << endl << endl;
				// 	}
				// }
				break;
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int N;
	fin >> N;
	map<int,int> m;
	for(auto c: num){
		m[c] = 0;
	}
	numeral.resize(N+1, m);
	solve();
	for(int i = 0; i < numeral.size(); i++){
		int j = 0;
		cout << i << endl;
		for(auto c: numeral[i]){
			m[c.f] += c.s;
			cout << st[j++] << " " << c.s << endl;
		}
	}
	int i = 0;
	for(auto a: m){
		if(a.s > 0){
			fout << st[i++] << " " << a.s << endl;
		}
	}
	
}
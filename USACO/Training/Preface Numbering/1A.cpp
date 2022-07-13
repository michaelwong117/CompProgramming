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
	//splits it up into subtractable factors
	//e.g., 99 into 90 and 9, and then into XC and IX
	//since you've already precomputed the previous sums
	//you can recreate the new roman numeral from previous
	for(auto &a: roman){
		a.s = 0;
	}
	int i = 0;
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

bool zeroes(int num){
	//note: split does not work on a single digit with zeroes 
	//if num only contains one digit besides zero, return false
	//there is nothing to split to
	int len = 0, count = 0;
	while(num){
		len++;
		if(num % 10 == 0) count++;
		num /= 10;
	}
	if(len == count+1) return false;
	return true;

}

void check(map<int, int> &roman, int sum){
	auto end = roman.end();
	end--;
	for(int i = 1; i < num.size(); i++){
		//subtract previous
		if(sum >= num[i]-num[i-1] && sum < num[i] && zeroes(sum) && num[i] > 10){
			split(roman, sum);
		}
		else if(sum == num[i]-num[i-1] && sum != num[i-1]){
			roman[num[i]] = 1;
			roman[num[i-1]] = 1;
		}
		if(i > 1){
			//subtract two previous
			if(sum >= num[i]-num[i-2] && sum < num[i] && zeroes(sum) && num[i] > 10){
				split(roman, sum);
			}
			else if(sum == num[i]-num[i-2] && sum != num[i-2]){
				roman[num[i]] = 1;
				roman[num[i-1]] = 0;
				roman[num[i-2]] = 1;
			}
		}
	}
	//gaps between symbols
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
				//build on past numerals
				numeral[i] = numeral[i-num[i2]];
				numeral[i][num[i2]]++;
				check(numeral[i], i);
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
		// cout << i << endl;
		for(auto c: numeral[i]){
			m[c.f] += c.s;
			// cout << st[j++] << " " << c.s << endl;
		}
	}
	int i = 0;
	for(auto a: m){
		if(a.s > 0){
			fout << st[i++] << " " << a.s << endl;
		}
	}
	
}
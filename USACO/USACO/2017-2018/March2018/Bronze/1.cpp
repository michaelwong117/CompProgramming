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
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
vector<bool> v (27);
vector<vector<bool>> s (27,vector<bool>(27));
vector<string> row, col;
string diag1="", diag2="";
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("tttt.in"); ofstream fout("tttt.out");
	for(int i = 0; i < 3; i++){
		string s = "";
		for(int i2 = 0; i2 < 3; i2++){
			char c; fin >> c;
			s += c;
			if(i == i2) diag1 += c; 
			if(abs(i2-i) == 2 || (i==i2 && i==1)) diag2 += c;
		}
		row.pb(s);
	}
	for(int i = 0; i < 3; i++){
		string s = "";
		for(auto a: row){
			s += a[i];
		}
		col.pb(s);
	}
	int res = 0, in = 0;
	for(auto a: row){
		if((a[0]-65) == (a[1]-65) && (a[0]-65) == (a[2]-65)){
			if(!v[(a[0]-65)]){
				in++; v[(a[0]-65)] = 1;
			}
		}
		if((a[0]-65) != (a[1]-65) && (a[0]-65) == (a[2]-65)){
			if(!s[(a[0]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[0]-65)]){
				res++; s[(a[0]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[0]-65)] = 1;
			}
		}
		if((a[0]-65) != (a[2]-65) && (a[0]-65) == (a[1]-65)){
			if(!s[(a[0]-65)][(a[1]-65)] && !s[(a[1]-65)][(a[0]-65)]){
				res++; s[(a[0]-65)][(a[1]-65)] = 1; s[(a[1]-65)][(a[0]-65)] = 1;
			}
		} 
		if((a[0]-65) != (a[1]-65) && (a[1]-65) == (a[2]-65)){
			if(!s[(a[1]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[1]-65)]){
				res++; s[(a[1]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[1]-65)] = 1;
			}
		}
	}
	for(auto a: col){
		if((a[0]-65) == (a[1]-65) && (a[0]-65) == (a[2]-65)){
			if(!v[(a[0]-65)]){
				in++; v[(a[0]-65)] = 1;
			}
		}
		if((a[0]-65) != (a[1]-65) && (a[0]-65) == (a[2]-65)){
			if(!s[(a[0]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[0]-65)]){
				res++; s[(a[0]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[0]-65)] = 1;
			}
		}
		if((a[0]-65) != (a[2]-65) && (a[0]-65) == (a[1]-65)){
			if(!s[(a[0]-65)][(a[1]-65)] && !s[(a[1]-65)][(a[0]-65)]){
				res++; s[(a[0]-65)][(a[1]-65)] = 1; s[(a[1]-65)][(a[0]-65)] = 1;
			}
		} 
		if((a[0]-65) != (a[1]-65) && (a[1]-65) == (a[2]-65)){
			if(!s[(a[1]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[1]-65)]){
				res++; s[(a[1]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[1]-65)] = 1;
			}
		}
	}
	string a = diag1;
	if((a[0]-65) == (a[1]-65) && (a[0]-65) == (a[2]-65)){
		if(!v[(a[0]-65)]){
			in++; v[(a[0]-65)] = 1;
		}
	}
	if((a[0]-65) != (a[1]-65) && (a[0]-65) == (a[2]-65)){
		if(!s[(a[0]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[0]-65)]){
			res++; s[(a[0]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[0]-65)] = 1;
		}
	}
	if((a[0]-65) != (a[2]-65) && (a[0]-65) == (a[1]-65)){
		if(!s[(a[0]-65)][(a[1]-65)] && !s[(a[1]-65)][(a[0]-65)]){
			res++; s[(a[0]-65)][(a[1]-65)] = 1; s[(a[1]-65)][(a[0]-65)] = 1;
		}
	} 
	if((a[0]-65) != (a[1]-65) && (a[1]-65) == (a[2]-65)){
		if(!s[(a[1]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[1]-65)]){
			res++; s[(a[1]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[1]-65)] = 1;
		}
	}
	a = diag2;
	if((a[0]-65) == (a[1]-65) && (a[0]-65) == (a[2]-65)){
		if(!v[(a[0]-65)]){
			in++; v[(a[0]-65)] = 1;
		}
	}
	if((a[0]-65) != (a[1]-65) && (a[0]-65) == (a[2]-65)){
		if(!s[(a[0]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[0]-65)]){
			res++; s[(a[0]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[0]-65)] = 1;
		}
	}
	if((a[0]-65) != (a[2]-65) && (a[0]-65) == (a[1]-65)){
		if(!s[(a[0]-65)][(a[1]-65)] && !s[(a[1]-65)][(a[0]-65)]){
			res++; s[(a[0]-65)][(a[1]-65)] = 1; s[(a[1]-65)][(a[0]-65)] = 1;
		}
	} 
	if((a[0]-65) != (a[1]-65) && (a[1]-65) == (a[2]-65)){
		if(!s[(a[1]-65)][(a[2]-65)] && !s[(a[2]-65)][(a[1]-65)]){
			res++; s[(a[1]-65)][(a[2]-65)] = 1; s[(a[2]-65)][(a[1]-65)] = 1;
		}
	}
	fout << in << endl << res << endl;
	
} 
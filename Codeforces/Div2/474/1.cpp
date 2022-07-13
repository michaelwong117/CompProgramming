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
 
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("filename.in"); ofstream fout("filename.out");
	string s; cin >> s;
	int a = 0, b = 0, c = 0;
	int cont = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'a') a++; 
		else if(s[i] == 'b'){
			cont = i;
			break;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = cont; i < s.length(); i++){
		if(s[i] == 'b') b++;
		else if(s[i] == 'c'){
			cont = i;
			break;
		}
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	for(int i = cont; i < s.length(); i++){
		if(s[i] == 'c') c++;
		else{
			cout << "NO" << endl;
			return 0;
		}
	}
	if(a < 1 || b < 1) cout << "NO" << endl;
	else if(a != c && b != c) cout << "NO" << endl;
	else cout << "YES" << endl;
	
}
/*
ID: michaelwong11
PROG: prefix
LANG: C++11   
*/
//g++-7 filename.cpp -std=c++14
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>> //min pq
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

vector<string> sv;

string s = "";

bool dp[250000];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("prefix.in","r",stdin); freopen("prefix.out","w",stdout);	
	//before you start coding, think it through

	string a1; 

	while(cin >> a1)
	{
		if(a1[0] == '.') break; 
		sv.pb(a1);
	}

	string part;

	while(cin >> part)
	{
		s += part;
	}
	dp[0] = 1;
	for(int i = 0; i <= s.size(); i++)
	{
		for(auto &a: sv)
		{
			int st = i - a.size();
			if(st < 0) continue;
			if(a == s.substr(st, a.size()))
			{
				dp[i] |= dp[st];
			}
		}
	}

	for(int i = s.size(); i >= 0; i--)
	{
		if(dp[i])
		{
			cout << i << endl;
			return 0;
		}
	}
}

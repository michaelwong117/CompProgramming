/*
ID: michaelwong11
PROG: zerosum
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


int n, dp[101]; //50 is weight 0, 49 is -1, 51 is 1

vector<string> v;

void solve(int w, string s)
{
	int idx = s.size() + 2;

	if(s.size() == n-1)
	{
		if(w == 50){
			string res = "";
			res += '1';
			for(int i = 0; i < s.size(); i++){
				res += s[i];
				res += (i+2) + '0';
			}
			v.pb(res);
			// cout << 1;
			// for(int i = 0; i < s.size(); i++)
			// {
			// 	cout << s[i] << i+2;
			// }
			// cout << endl;	
		}	
		return;
	}

	solve(w + idx, s + "+");
	solve(w - idx, s + "-");
	if(s == "") solve(w + (idx - 1) * 9 + idx, s + " ");
	else
	{
		if(s.back() == '+') solve(w + (idx - 1) * 9 + idx, s + " ");
		else if(s.back() == '-') solve(w - (idx - 1) * 9 - idx, s + " ");
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("zerosum.in","r",stdin); freopen("zerosum.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	solve(51, "");
	sort(all(v));
	for(auto a: v)
	{
		cout << a << endl;
	}
}
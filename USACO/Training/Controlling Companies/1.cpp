/*
ID: michaelwong11
PROG: concom
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


int n, o[101];

vector<vpi> adjO (101), adj (101);

vi own;

set<pi> res;

void dfs(){
	for(int i = 0; i < own.size(); i++)
	{	
		int st = own[i];
		memset(o, 0, sizeof o);
		for(auto a: adjO[st])
		{
			for(auto b: adj[a.f])
			{
				if(b.f != st) o[b.f] += b.s;
			}
		}
		for(auto a: adj[st])
		{
			o[a.f] += a.s;
		}
		for(int j = 1; j <= 100; j++)
		{
			if(o[j] > 50 && j != st)
			{
				bool in = 0;
				for(auto a: adjO[st])
				{
					if(a.f == j) in = 1;
				}
				if(!in) adjO[st].pb({j, 0});
				res.insert({st, j});
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("concom.in","r",stdin); freopen("concom.out","w",stdout);	
	//before you start coding, think it through
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int a, b, p; cin >> a >> b >> p;

		if(p > 50) 
		{
			adjO[a].pb({b,p});

			own.pb(a);

			if(a != b) res.insert({a,b});
		}
		adj[a].pb({b,p});
	}
	int c = 0;
	while(c < 100)
	{
		dfs(); c++;
	}
	for(auto a: res)
	{
		cout << a.f << " " << a.s << endl;
	}
}

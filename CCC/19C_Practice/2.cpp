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

using namespace std::chrono;
#define START auto start = high_resolution_clock::now();
#define STOP auto stop = high_resolution_clock::now(); auto span = duration_cast<milliseconds>(stop - start); cout << span.count() << endl;


vi pri = {2};

int t, n;

bool isprime(int n)
{
	for(int i = 2; i <= (int) sqrt(n); i++)
	{
		if(n % i == 0) return false;
	}
	return true;
}

void gen()
{
	for(int i = 3; i < 2e6; i+=2)
	{
		if(isprime(i)) pri.pb(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	gen();
	// for(auto a: pri) if(a < 1000) cout << a << endl;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;

		int l = 0, r = pri.size()-1;

		while(pri[l] + pri[r] != 2*n)
		{
			// cout << pri[l] << " " << pri[r] << endl;
			if(pri[l] + pri[r] > 2*n) r--;
			
			else if(pri[l] + pri[r] < 2*n) l++;
		}
		cout << pri[l] << " " << pri[r] << endl;
	}






}

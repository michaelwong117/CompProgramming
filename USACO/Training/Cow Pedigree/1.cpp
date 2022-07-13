/*
ID: michaelwong11
PROG: nocows
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

int n, k, res = 0, dp[101][201][8]; //leaves can be max of 8 given 2^8 (256) nodes

//https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c
int c(int n, int k)
{
	if(k > n) return 0;
	if(k * 2 > n) k = n - k;
	if(k == 0) return 1;

	int res = n;

	for(int i = 2; i <= k; i++)
	{
		res *= (n - i + 1);
		res /= i;
	}

	return res;
}

void solve(int h, int tot, int l, int res)
{
	if(h > k || tot > n) return;
	if(dp[h][tot][l] != -1) return dp[h][tot][l];

	for(int i = 1; i <= l; i++)
	{
		dp[h+1][tot+2*i][2*i] = solve(h+1, tot+2*i, 2*i) * c(l, i);
	}
	
}


void solve(int h, int tot, int l)
{
	if(h > k || tot > n) return 1;
	if(dp[h][tot][k] != -1) return dp[h][tot][k];

	for(int i = 1; i <= l; i++)
	{
		dp[h+1][tot+2*i][2*i] = c(l, i) * solve(h+1, tot+2*i, 2*i);
	}

	return dp[h][tot][l];

		 //cur			//x,y
	//cur+1,cur+2						//a,b
}

void solve (int h, int tot)
{
	

}


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("nocows.in","r",stdin); //freopen("nocows.out","w",stdout);	
	//before you start coding, think it through
	cin >> n >> k;
	if(n % 2 == 0 || (n + 1) / 2 < k || n > pow(2, k) - 1)
	{
		cout << 0 << endl;
		return 0;
	}

	//(1) (n + 1) / 2 ... pow(2, k) - 1 nodes (1)

}
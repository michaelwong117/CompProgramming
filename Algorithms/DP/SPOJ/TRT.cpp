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

//https://www.quora.com/Are-there-any-good-resources-or-tutorials-for-dynamic-programming-DP-besides-the-TopCoder-tutorial#s
//great resource explaining DP

//SPOJ TRT 1/25/19

const int N = 2001;

int n, treat[N];

//come up with a backtracking solution first

//understand the variables and the *key question*:

//given some current year and some interval [be, en] of the treats lefts
//what is my best revenue possible?

int solve(int year, int be, int en){
	if(be > en) return 0;
	return max(solve(year+1, be+1, en) + year * treat[be],
					solve(year+1, be, en-1) + year * treat[en]);
}

//next, simplify your DP variables
//notice year = n - (en - be), so del its

//how many unique parameters can your function be called with?
//be and en go up to n, and be <= en for all valid calls, so
//there's a total of O(n^2) distnct calls made

//the current complexity is O(2^n) because we're recomputing states
//so let's cache each of the O(n^2) states so we don't recompute

//each function call takes O(1), and there's a total of 
//O(n^2) unique calls, so the total complexity is O(n^2)


int cache[N][N]; //initialize as all uncomputed (-1)

int memo(int be, int en){
	if(be > en) return 0;
	if(cache[be][en] != -1){
		return cache[be][en];
	}
	int year = n - (en - be);
	return cache[be][en] = max(memo(be+1, en) + year * treat[be],
										memo(be, en-1) + year * treat[en]);
}


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start cosding, think it through
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> treat[i];
	// cout << solve(1, 1, n) << endl;
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++) cache[i][j] = -1;
	}
	cout << memo(1, n) << endl;
}

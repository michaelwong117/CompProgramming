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
const int N = 1e5+10;

vector<pl> job;

int n;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n; job.resize(n+1);
	for(int i = 0; i < n; i++){
		cin >> job[i].f >> job[i].s;
	}
	job[n] = {0, 0};
	sort(all(job), greater<pl>());

	ll lastD = 1e18, res = 0;
	priority_queue<ll> q;

	for(int i = 0; i <= n; i++){
		//d, d+1, d+2, d+3, d+4
		//for an open space like d+3, i can either do a job that has deadline d+3 or d+4
		//since they're sorted, I can only use jobs from d+3 or d+4 to fill in the spot at d+3
		//use the pq to determine max profit when filling in d+3
		while(q.size() && job[i].f < lastD){
			lastD--;
			res += q.top(); q.pop();
		}
		//from a set deadline job[i].f, I can do this job i for profit job[i].s at any time before job[i].f
		//choose a maximal time 
		//do this for all deadlines and all jobs so your priority queue stores the best for everything ahead of you
		lastD = job[i].f;
		q.push(job[i].s);
	}
	cout << res << endl;



}
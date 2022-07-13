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

priority_queue<ll, vl, greater<ll>> profit;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n; job.resize(n+1);
	for(int i = 1; i <= n; i++){
		cin >> job[i].f >> job[i].s;
	}
	sort(all(job));

	//for(int i = 1; i <= n; i++) cout << job[i].f << " " << job[i].s << endl;

	int j = 1;

	for(int i = 1; i <= n; i++){

		if(j > n) break;

		if(job[j].f > i){
			profit.push(job[j].s); j++; continue;
		}
		int c = 0;
		while(j <= n && job[j].f == i){
			if(c == 0){ //should only trigger on first job of its deadline
				profit.push(job[j].s); c++;
			}
			else{
				ll low = profit.top();
				if(low < job[j].s){
					profit.pop(); profit.push(job[j].s);
				}
			}
			j++;
		}

	}
	ll res = 0;
	while(!profit.empty()){
		res += profit.top(); profit.pop();
	}
	cout << res << endl;


}
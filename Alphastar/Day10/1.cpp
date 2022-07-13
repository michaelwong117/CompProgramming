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
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;


int N, M, curmx;


int check(int cow, vi gang, int cur, int onfield){
	if(cur != -1e9) gang[cur] += onfield; 
	gang[cow]--;
	int mx = 0, mxi;
	for(int i = 2; i <= M; i++){
		if(gang[i] > mx){
			mx = gang[i]; mxi = i;
		}
	}
	gang[mxi]--; curmx = mxi;

	mpq q; 
	for(int i = 2; i <= M; i++){
		if(gang[i] != 0) q.push(gang[i]); 
	}
	for(int i = 0; i < N; i++){
		if(q.empty() || q.size() == 1){
			break;
		}
		int t1 = q.top(); q.pop();
		int t2 = q.top(); q.pop();
		if(t1-1 > 0) q.push(t1-1); 
		if(t2-1 > 0) q.push(t2-1);
	}
	if(q.empty()) return gang[1];
	else return gang[1]-q.top();


}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> N >> M;
	vi gang (M+1);
	for(int i = 1; i <= M; i++){
		cin >> gang[i];
	}
	int best = 0;
	for(int i = 1; i <= M; i++){
		best = max(best, check(i, gang, -1e9, 0));
	}
	vi order;
	int cur = -1e9, onfield = 0, next;
	for(int i = 0; i < N; i++){
		for(int j = 1; j <= M; j++){
			if(gang[j] < 1) continue;

			//cout << j << " " << cur << " " << onfield << endl;
			if(check(j, gang, cur, onfield) == best){
				// cout << j << endl;
				// for(int k = 1; k < gang.size(); k++){
				// 	cout << gang[k] << " ";
				// }
				// cout << endl;
				next = j; gang[j]--; gang[curmx]--; 
				order.pb(next); order.pb(curmx);
				break;

			}
		}
		if(cur == -1e9){
			cur = next;
		}
		if(cur == next){
			onfield++; 
		}
		else{
			onfield--;
			if(onfield == 0) cur = -1e9;
		}

	}
	for(int i = 0; i < order.size(); i++){
		cout << order[i] << endl;
	}



}
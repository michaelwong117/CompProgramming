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

vi gang (101), order;

int n, m, best = 0;


int check(int g, int control, int onfield){
	if(control != -1) gang[control] += onfield;
	mpq q;
	//subtract from g
	gang[g]--; 
	for(int i = 2; i <= m; i++){
		
		q.push(gang[i]);

	}
	gang[g]++;

	while(!q.empty() && q.size() > 1){
		int t1 = q.top(); q.pop();
		int t2 = q.top(); q.pop();
		if(t1 > 1) q.push(t1-1);
		if(t2 > 1) q.push(t2-1);
	}

	if(q.empty()) return gang[1];
	if(q.size() == 1) return (gang[1]-q.top());

}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		cin >> gang[i];
	}

	best = check(0, -1, 0);
	
	cout << best << endl;
	int control = -1, onfield = 0;

	rep(i, n){
		for(int g = 1; g <= m; g++){
			//can't place any more of this gang
			if(gang[g] <= 0) continue;
			//you can place g to get best
			if(check(g, control, onfield) == best){
				gang[g]--; order.pb(g); break;
			}
		}
		int curG = order.back();
		if(control == -1) control = curG;
		if(control == curG) onfield++;
		else{
			onfield--; if(onfield == 0) control = -1;
		}
	}
	for(int i = 0; i < order.size(); i++){
		cout << order[i] << endl;
	}










}
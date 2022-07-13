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
#define pq priority_queue<ll, vector<ll>, greater<ll>>
#define mpq priority_queue<ll>
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(ll i = 0; i < n; i++)
typedef long long ll; typedef vector<ll> vi; typedef vector<ll> vl;
typedef pair<ll, ll> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<ll,3>> multiv;

const ll mx = 2*1e5+1;

//minv[1] is the min of the entire tree/array
//node i has range lo[i]...hi[i]
//minv[i] is min for lo[i] to hi[i]
//delta is just possible changes waiting to be propped down
ll lo[4*mx], hi[4*mx], minv[4*mx], delta[4*mx];


//pushing down delta change to children
void prop(ll i){
	delta[2*i] += delta[i];
	delta[2*i+1] += delta[i];
	delta[i] = 0;
}
//aggregate update function (min value)
//going back up the tree and updating values after delta is pushed down to child delta values
void update(ll i){
	minv[i] = min(minv[2*i]+delta[2*i], minv[2*i+1]+delta[2*i+1]);
}


//0 idxed
//a is beginning of range, b is end of range

void init(ll i, ll a, ll b, vi &arr){
	lo[i] = a;
	hi[i] = b;
	if(a == b){
		minv[i] = arr[a];
		return;
	}
	ll m = (a+b)/2;
	init(2*i, a, m, arr);
	init(2*i+1, m+1, b, arr);
	minv[i] = min(minv[2*i], minv[2*i+1]);
}


void add(ll i, ll a, ll b, ll val){
	//  [----b]  [lo[i]-----]
	//  [----hi[i]]   [a-----]

	//out of range (no cover)
	if(b < lo[i] || hi[i] < a){
		return;
	}

	//a  lo[i] hi[i] b
	//full cover
	if(a <= lo[i] && hi[i] <= b){
		delta[i] += val; 
		return;
	}

	//partial cover case, so we go down tree

	//push deltas down
	prop(i);
	//trying to find full cover to add val to deltas
	add(2*i, a, b, val);
	add(2*i+1, a, b, val);

	update(i);
}


void add(ll a, ll b, ll val){
	add(1, a, b, val);
}


ll minQ(ll i, ll a, ll b){
	if(b < lo[i] || hi[i] < a){
		return 1e9;
	}
	if(a <= lo[i] && hi[i] <= b){
		//may or may not be something in delta, just take care of it
		return minv[i]+delta[i];
	}
	//partial cover case

	//push deltas
	prop(i);

	ll minL = minQ(2*i, a, b);
	ll minR = minQ(2*i+1, a, b);

	update(i);

	return min(minL, minR);

}


ll minQ(ll a, ll b){
	return minQ(1, a, b);
}



int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//start from root node, 1
	//range 0 to n-1 since indicies of arr[n] are 0...n-1
	ll n, m; cin >> n;
	vi v(n);
	rep(i, n){
		cin >> v[i];
	}
	init(1, 0, n-1, v);
	// for(ll i = 1; i < 2*n; i++){
	// 	cout << minv[i] << " ";
	// }
	cin >> m;
	string use; getline(cin, use);
	rep(i, m){
		string nex; vi op;
		getline(cin, nex);
		rep(j, nex.size()){
			string cur = ""; int k;
			if(nex[j] == '-'){
				for(k = j+1; k < nex.size(); k++){
					if(nex[k] == ' ') break;
					else cur += nex[k];
				}
				op.pb(-1*(stoi(cur))); j=k;
			}
			else if(nex[j] != ' '){
				for(k = j; k < nex.size(); k++){
					if(nex[k] == ' ') break;
					else cur += nex[k];
				}
				op.pb(stoi(cur)); j=k;
			}
		}
		//case has circular, so from 3...1 is 3 4 0 1 if n = 4
		//has to wrap around, that's why special case
		//otherwise just minQ(op[0], op[1])
		if(op.size() == 2){
			if(op[0] > op[1]) out(min(minQ(op[0], n-1), minQ(0, op[1])));
			else out(minQ(op[0], op[1]));
		}
		else{
			if(op[0] > op[1]){
				add(op[0], n-1, op[2]);
				add(0, op[1], op[2]);
			}
			else add(op[0], op[1], op[2]);
		}
	}
	




}
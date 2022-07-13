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

const int N = 2*1e3+10;

int p[N];

vpi pairs;

unordered_map<int,int> phero;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	int n, m; cin >> n >> m;
	for(int i = 1; i <= 2*n; i++){
		cin >> p[i];
	}
	for(int i = 0; i < m; i++){
		int a, b; cin >> a >> b;
		pairs.pb({a,b});
		phero[a] = b; phero[b] = a;
	}
	int t; cin >> t;

	int term = 0;
	if(t == 1){
		bool greedy = 0;
		int x = 0, next;
		while(term < n){
			//switch from pairs to greedy
			if(x == pairs.size() && !greedy){
				greedy = 1;
			}
			if(!greedy){
				if(p[pairs[x].f] >= p[pairs[x].s]){
					cout << pairs[x].f << endl;
					cout.flush();
				}
				else{
					cout << pairs[x].s << endl;
					cout.flush();
				}
				cin >> next; //next should j be pairs[x].s
				//move onto next pair, mark powers as used
				p[pairs[x].f] = -1e9; p[pairs[x].s] = -1e9;
				x++; 
			}
			else if(greedy){
				pi mx = {0, 0};
				for(int i = 1; i <= 2*n; i++){
					mx = max(mx, {p[i],i});
				}
				p[mx.s] = -1e9;
				cout << mx.s << endl;
				cout.flush();
				cin >> next;
				p[next] = -1e9;
			}
			term++;
		}

	}

	else{
		bool greedy = 0, tookover = 0;
		int x = 0, next;
		while(term < n){
			cin >> next; p[next] = -1e9;
			if(phero.find(next) != phero.end() && !tookover){
				//it's a pair
				cout << phero[next] << endl;
				cout.flush();
				p[next] = -1e9; p[phero[next]] = -1e9;
				phero.erase(phero[next]); phero.erase(next); 
			}
			else{
				if(phero.empty() && !greedy){
					greedy = 1;
				}
				if(!greedy){
					int a= phero.begin()->first;
					int b = phero.begin()->second;
					if(p[a] >= p[b]){
						cout << a << endl;
						cout.flush();
					}
					else{
						cout << b << endl;
						cout.flush();
					}
					p[a] = -1e9; p[b] = -1e9;
					phero.erase(a); phero.erase(b);
				}
				else if(greedy){
					pi mx = {0, 0};
					for(int i = 1; i <= 2*n; i++){
						mx = max(mx, {p[i],i});
					}
					p[mx.s] = -1e9;
					cout << mx.s << endl;
					cout.flush();
				}
				tookover = 1;

			}
			term++;

		}

	}



}

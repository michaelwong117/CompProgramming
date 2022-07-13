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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	string top, bot; cin >> top >> bot;
	int b = 0;
	for(int i = 0; i < top.size(); i++){
		if(i+1 == top.size()) break;
		if(top[i+1] == 'X' && bot[i+1] == 'X') continue;
		if(top[i+1] == 'X' || bot[i+1] == 'X'){
			if(top[i] == '0' && bot[i] == '0'){
				//top[i+1],top[i] and bot[i+1],bot[i] are now filled 
				top[i+1] = 'X'; bot[i+1] = 'X';	
				//cout << "DAMNIT1 " << i << endl;
				b++;  
			}
			else{
				if(i+2 == top.size()) break;
				if(top[i+2] == '0' && bot[i+2] == '0'){
					//cout << "DAMNIT2 " << i << endl;
					b++;
					//top[i+2], top[i+1], bot[i+2], bot[i+1] are filled 
					top[i+1] = 'X'; bot[i+1] = 'X';
					top[i+2] = 'X'; bot[i+2] = 'X';

				}
		
			}
		}
		else{
			if(top[i] == '0' && bot[i] == '0'){
				//cout << "DAMNIT3 " << i << endl;
				top[i+1] = 'X'; b++;
			}
			else if(top[i] == '0' || bot[i] == '0'){
				//cout << "DAMNIT4 " << i << endl;
				top[i+1] = 'X'; bot[i+1] = 'X';
				b++;
			}
			else if(top[i+2] == '0'){
				//cout << "DAMNIT5 " << i << endl;
				top[i+1] = 'X'; bot[i+1] = 'X';
				b++; top[i+2] = 'X';
			}
			else if(bot[i+2] == '0'){
				//cout << "DAMNIT6 " << i << endl;
				top[i+1] = 'X'; bot[i+1] = 'X';
				b++; bot[i+2] = 'X';
			}
		}

	}
	out(b);
}
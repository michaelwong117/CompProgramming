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

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, moron, think it through
	string s; cin >> s;
	if(s.size() == 1){
		cout << 1 << endl;
		return 0;
	}
	char prev = s[0];
	int z = 1, mx = 1, firstzeb = 1;
	bool fir = 1;
	for(int i = 1; i < s.size(); i++){
		if(s[i] != prev){
			z++;
			if(fir) firstzeb++;
			mx = max(mx, z);
		}
		else{
			fir = 0;
			z = 1;
		}
		prev = s[i];
	}
	char first = s[0], end = s[s.size()-1];
	if(first == end){
		out(mx);
		return 0;
	}
	firstzeb++;
	prev = s[s.size()-1];
	for(int i = s.size()-2; i >= 1; i--){
		if(s[i] != prev){
			firstzeb++;
		}
		else{
			break;
		}
		prev = s[i];
	}
	cout << min(max(firstzeb, mx), (int)s.size()) << endl;


}	
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

const int N = 60001;
const int K = ceil(log2(N))+1;

struct sfx{
	int rank[2], idx;
};

bool cmp (const sfx a, const sfx b){
	return ((a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1]) : (a.rank[0] < b.rank[0]));

}

int n;
string s;
int order[K][N];
sfx SA[N];
deque<char> org;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	cin >> n; 
	for(int i = 0; i < n; i++){
		char c; cin >> c; s += c;
		org.pb(c);
	}
	n += n;
	string rev = s; reverse(all(rev));
	// cout << s << " " << rev << endl;
	s += rev;
	for(int i = 0; i < n; i++){
		order[0][i] = s[i] - 'a';
	}
	int k, jump;
	for(k = 1, jump = 1; k <= ceil(log2(n)); k++, (jump <<= 1)){
		for(int i = 0; i < n; i++){
			SA[i].rank[0] = order[k-1][i];
			if(i + jump >= n) SA[i].rank[1] = -1e9; 
			else SA[i].rank[1] = order[k-1][i+jump];
			SA[i].idx = i;
		}
		sort(SA, SA + n, cmp);
		for(int i = 0; i < n; i++){
			int I = SA[i].idx, prev = SA[i-1].idx;
			if(i > 0 && SA[i-1].rank[0] == SA[i].rank[0] && SA[i-1].rank[1] == SA[i].rank[1]){
				order[k][I] = order[k][prev]; 
			}
			else order[k][I] = i;
		}
	}

	int mx = ceil(log2(n)), p = pow(2,k);
	// for(int i = 0; i < n; i++){
	// 	cout << order[mx][i] << " " << s.substr(i, p) << endl;
	// }

	string final = "";
	int a = 0, b = 0;
	n /= 2;
	while(a + b < n-1){
		// cout << order[mx][n+a] << " " << s.substr(n+a, p) << endl;
		// cout << order[mx][b] << " " << s.substr(b, p) << endl;
		// cout << endl;
		if(order[mx][n+a] < order[mx][b]){
			a++; final += org.back(); org.pop_back();
		}
		else{
			b++; final += org.front(); org.pop_front();
		}
	}
	final += org.front();
	int i = 0;
	while(i < final.size()){
		if(i+80 > final.size()) cout << final.substr(i, string::npos) << endl;
		else cout << final.substr(i, 80) << endl;
		i += 80;
	}

	


}

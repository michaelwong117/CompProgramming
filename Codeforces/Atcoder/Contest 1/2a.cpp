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
typedef unsigned long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

int L;

bool seen[1000000];

vector<vi> digits(1000010);

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	// ofstream fout("input.out");
	string s = "10001101";
	cout << stoi(s, nullptr, 2) << endl;
	//before you start coding, think it through
	// vl v;
	// cin >> L;
	// for(int i = 1; i < 25; i++){
	// 	for(int j = 1; j < 25; j++){
	// 		for(int k = 1; k < 25; k++){
	// 			if(i+j+k > 60) continue;
	// 			for(int a = 1; a < 25; a++){
	// 				if(i+j+k+a > 60) continue;
	// 				for(int b = 1; b < 25; b++){
	// 					if(i+j+k+a+b > 60) continue;

	// 					for(int c = 1; c < 25; c++){
	// 						if(i+j+k+a+b+c > 60) continue;

	// 						for(int d = 1; d < 25; d++){
	// 							if(i+j+k+a+b+c+d > 60) continue;

	// 							for(int e = 1; e < 25; e++){

	// 								for(int f = 1; f < 25; f++){

	// 									ll res = i*j*k*a*b*c*d*e*f;
	// 									if(i+j+k+a+b+c+d+e+f <= 60 && res <= 1000000 && !seen[res]){
	// 										seen[res] = 1;
	// 										digits[res] = {i,j,k,a,b,c,d,e,f};
	// 										v.pb(res);
	// 									}
	// 								}
	// 							}
	// 						}
							
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// sort(all(v));
	// fout << "{";
	// for(int i = 0; i < v.size()-1; i++){
	// 	fout << v[i] << ",";
	// }
	// fout << v[v.size()-1] << "};" << endl;
	// fout << endl;
	// fout << "{";
	// for(int i = 0; i < v.size(); i++){
	// 	fout << "{";
	// 	for(int j = 0; j < digits[v[i]].size()-1; j++){
	// 		fout << digits[v[i]][j] << ",";
	// 	}
	// 	if(i == v.size()-1){
	// 		fout << digits[v[i]][digits[v[i]].size()-1] << "};";
	// 	}
	// 	else fout << digits[v[i]][digits[v[i]].size()-1] << "},";
	// }
	// fout << "};" << endl;
	// fout << endl;
}

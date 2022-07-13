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

int k; 

vi v;


int recurse(){
	set<int> s;
	for(int i = 1; i <= 7; i++){
		for(int a = 1; a < 10; a++){
			for(int b = 0; b < 10; b++){
				if(a+b == 10) s.insert(a*10+b);
				if(i < 2) continue;
				//cout << b << endl;
				for(int c = 0; c < 10; c++){
					if(a+b+c == 10) s.insert(a*100+b*10+c);
					if(i < 3) continue;
					for(int d = 0; d < 10; d++){
						if(a+b+c+d == 10) s.insert(a*1000+b*100+c*10+d);
						if(i < 4) continue;
						for(int e = 0; e < 10; e++){
							if(a+b+c+d+e == 10) s.insert(a*10000+b*1000+c*100+d*10+e);
							if(i < 5) continue;
							for(int f = 0; f < 10; f++){
								if(a+b+c+d+e+f == 10) s.insert(a*100000+b*10000+c*1000+d*100+e*10+f);
								if(i < 6) continue;
								for(int g = 0; g < 10; g++){
									if(a+b+c+d+e+f+g == 10) s.insert(a*1000000+b*100000+c*10000+d*1000+e*100+f*10+g);
									if(i < 7) continue;
									for(int h = 0; h < 10; h++){
										if(a+b+c+d+e+f+g+h == 10) s.insert(a*10000000+b*1000000+c*100000+d*10000+e*1000+f*100+g*10+h);
									}
								}

							}
							
						}
					}
				}
			}
		}
	}
	int c = 1;
	for(auto a: s){
		if(c == k) return a;
		c++;
	}
	// sort(all(v));
	// int c = 0;
	// for(int i = 0; i < v.size(); i++){
	// 	//cout << v[i] << endl;
	// 	if(i == 0){
	// 		c++;
	// 		if(k == 1) return v[0];
	// 	}
	// 	if(v[i] == v[i-1]) continue;
	// 	c++;
	// 	if(c == k) return v[i];
	// }
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	cin >> k;
	cout << recurse() << endl;


}
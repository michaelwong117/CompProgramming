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

string s;

int k;


int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through

	cin >> s >> k;

	int cane = 0, flake = 0;

	for(int i = 0; i < s.size(); i++){
		if(s[i] == '?') cane++;
		if(s[i] == '*') flake++;
	}
	int doublef = -1, removef = -1, removec = -1;
	
	// else{
		for(int i = 0; i <= flake; i++){ // number we want to double
			for(int j = 0; j <= flake; j++){ //number we want to remove
				if(i + j > flake) continue;
				for(int c = 0; c <= cane; c++){ //number we want to remove canes
					int leftf = flake - i - j;
					int leftc = cane - c;
				
					if(k == s.size() - 2*j - 2*c - leftf - leftc){
						// cout << s.size() << " " << i << " " << 2*j << " " << 2*c << " " << leftf << " " << leftc << endl;
						doublef = i; removef = j; removec = c;
						// cout << "double i " << i << endl;
						// cout << "remove flake " << j << endl;
						// cout << "remove cane " << c << endl;
						// cout << "left flake " << leftf << endl;
						// cout << "left cane " << leftc << endl << endl;
					}
				}
			}
		}
	// }
	string final = ""; 
	if(doublef == -1){
		cout << "Impossible" << endl;
		// cout << "3" << endl;
		return 0;
	}
	else{
		final += s[0];
		for(int i = 1; i < s.size(); i++){
			if(doublef > 0 && s[i] == '*'){
				final += final.substr(final.size()-1, 1); doublef--;
			}
			else if(removef > 0 && s[i] == '*'){
				final = final.substr(0, final.size()-1); removef--;
			}
			else if(removec > 0 && s[i] == '?'){
				final = final.substr(0, final.size()-1); removec--;
			}
			else if(s[i] == '?' || s[i] == '*'){
				continue;
			}
			else{
				final += s[i];
			}
		}
	}
	cout << final << endl;
}

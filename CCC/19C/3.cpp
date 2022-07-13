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

vector<int> rows, r1, r2, r3, c1, c2, c3;
vector<vector<int>> tot;


int countX(vector<int> &v){
	int c = 0;
	for(auto a: v){
		if(a == -1e9) c++;
	}
	return c;
}
bool checkX(vector<vector<int>> v){
	for(auto a: v){
		for(auto b: a){
			if(b == -1e9) return false;
		}
	}
	return true;
}
void print(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << tot[i][j] << " ";
		}
		cout << endl;
	}
}
void oneX(int &x, int &y){
	if(x == -1e9 && y != -1e9) x = y;
	else if(y == -1e9 && x != -1e9) y = x;
}
void solve(){
	for(int j = 0; j < tot.size(); j++){
		// cout << countX(tot[j]) << endl;
		// cout << tot[j][0] << " " << tot[j][1] << " " << tot[j][2] << endl;
		if(tot[j][0] == -1e9 || tot[j][1] == -1e9 || tot[j][2] == -1e9){
			int idx, c=0;
			for(int i = 0; i < tot[j].size(); i++){
				if(tot[j][i] == -1e9){
					idx = i;
					c++;
				}
			}
			if(c > 1) continue;
			if(idx == 0){
				int diff = tot[j][2] - tot[j][1];
				tot[j][0] = tot[j][1] - diff;
			}
			else if(idx == 1){
				int diff = tot[j][2] - tot[j][0];
				tot[j][1] = tot[j][0] + (diff / 2);
			}
			else if(idx == 2){
				int diff = tot[j][1] - tot[j][0];
				tot[j][2] = tot[j][1] - diff;
			}
			
		}
	}
	oneX(tot[0][0],tot[3][0]);
	oneX(tot[0][1],tot[4][0]);
	oneX(tot[0][2],tot[5][0]);
	oneX(tot[1][0],tot[3][1]);
	oneX(tot[1][1],tot[4][1]);
	oneX(tot[1][2],tot[5][1]);
	oneX(tot[2][0],tot[3][2]);
	oneX(tot[2][1],tot[4][2]);
	oneX(tot[2][2],tot[5][2]);
	// vector<int> nrow;
	// for(int j = 0; j < 3; j++){
	// 	for(auto a: tot[j]){
	// 		nrow.pb(a);
	// 	}
	// }
	// int a = nrow[0], b = nrow[1], c = nrow[2], d = nrow[3], e = nrow[4], f = nrow[5];
	// int x = nrow[6], y = nrow[7], z = nrow[8];
	// r1 = {a,b,c};
	// r2 = {d,e,f};
	// r3 = {x,y,z};
	// c1 = {a,d,x};
	// c2 = {b,e,y};
	// c3 = {c,f,z};
	// tot = {r1,r2,r3,c1,c2,c3};
	// nrow = {};
	// for(int j = 3; j < 6; j++){
	// 	for(auto a: tot[j]){
	// 		nrow.pb(a);
	// 		cout << a << " ";
	// 	}
	// }
	// cout << endl << endl;
	// a = nrow[0], b = nrow[1], c = nrow[2], d = nrow[3], e = nrow[4], f = nrow[5];
	// x = nrow[6], y = nrow[7], z = nrow[8];
	// r1 = {a,b,c};
	// r2 = {d,e,f};
	// r3 = {x,y,z};
	// c1 = {a,d,x};
	// c2 = {b,e,y};
	// c3 = {c,f,z};
	// tot = {c1,c2,c3,r1,r2,r3};

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	//before you start coding, think it through
	for(int i = 0; i < 9; i++){
		string s; cin >> s;
		if(s == "X"){
			rows.pb(-1e9);
		}
		else{
			rows.pb((int) stoi(s));
		}
		// cout << rows[i] << endl;
	}
	int a = rows[0], b = rows[1], c = rows[2], d = rows[3], e = rows[4], f = rows[5];
	int x = rows[6], y = rows[7], z = rows[8];
	r1 = {a,b,c};
	r2 = {d,e,f};
	r3 = {x,y,z};
	c1 = {a,d,x};
	c2 = {b,e,y};
	c3 = {c,f,z};
	tot = {r1,r2,r3,c1,c2,c3};
	if(checkX(tot)){
		print();
	}
	for(int i = 0; i < 20; i++) solve();
	int three = 0;
	if(checkX(tot)){
		print();
	}
	else{
		for(int i = 0; i < 3; i++){
			if(countX(tot[i]) == 3){
				three++;
			}
		}
		if(three == 3){
			cout << 1 << " " << 2 << " " << 3 << endl;
			cout << 2 << " " << 3 << " " << 4 << endl;
			cout << 3 << " " << 4 << " " << 5 << endl;
			return 0;
		}
		int idx, start;
		vpi xs;
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				if(tot[i][j] == -1e9){
					idx = j;
					start = i;
					xs.pb({i,j});
				}
			}
		}
		for(int a = -1000; a <= 1000; a++){
			tot[start][idx] = a;
			for(int i = 0; i < 4; i++){
				solve();
			}
			if(checkX(tot)){
				print();
				return 0;
			}
		}
	
		// for(int a = -1000; a <= 1000; a++){
		// 	for(int i = 0; i < xs.size(); i++){
		// 		tot[xs[i].f][xs[i].s] = a;
		// 		for(int j = i+1; j < xs.size(); j++){
		// 			for(int b = -1000; b <= 1000; b++) tot[xs[j].f][xs[j].s] = b;
		// 			for(int i = 0; i < 4; i++){
		// 				solve();
		// 			}
		// 			if(checkX(tot)){
		// 				print();
		// 				return 0;
		// 			}
		// 		}
				
		// 	}
		// }
// 
	
		// vpi xs;
		// for(int i = 0; i < 3; i++){
		// 	for(int j = 0; j < 3; j++){
		// 		if(tot[i][j] == -1e9){
		// 			xs.pb({i,j});
		// 		}
		// 	}
		// }



	}
}

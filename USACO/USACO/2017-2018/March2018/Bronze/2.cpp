//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define mpq priority_queue<int>
 
typedef long long ll; typedef vector<int> vi;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;
const int maxN = 101;
int N, M, K, order[maxN], res[maxN];
vi pos;
unordered_set<int> in;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	ifstream fin("milkorder.in"); ofstream fout("milkorder.out");
	fin >> N >> M >> K;
	pos.resize(N+1,-1);
	for(int i = 1; i <= M; i++) fin >> order[i];
	for(int i = 1; i <= K; i++){
		int c, p; fin >> c >> p;
		if(c == 1){
			fout << p << endl;
			return 0;
		}
		res[c] = p;
		pos[p] = c;
		in.insert(c);
	}
	int past = 1, end = 1;
	for(int i = 1; i <= M; i++){
		//if a cow in order is 1, place everything early as possible
		if(order[i] == 1){
			for(int i2 = past; i2 <= i; i2++){
				for(int j = end; j <= N; j++){
					if(pos[j] == -1){
						pos[j] = order[i2];
						if(pos[j] == 1){
							fout << j << endl;
							return 0;
						}
						break;
					}
				}
			}
		}
		//if the cow already has a set index and is in order
		auto it = in.find(order[i]);
		if(it != in.end()){
			//mark its position
			int mark = res[order[i]];
			//going backwards in the order
			for(int i2 = i-1; i2 >= past; i2--){
				//iterate backwards until you find a valid position for order[i2]
				while(pos[mark] != -1 && pos[mark] != order[i2]) mark--;
				//once you've found open slot set its value
				pos[mark] = order[i2];
			}
			past = i+1; end = mark+1;
		}
	}
	for(int i = 1; i <= N; i++){
		if(pos[i] == -1){
			fout << i << endl;
			break;
		}
	}

}
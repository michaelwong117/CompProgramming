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

int fac[11];

void genfac(){
	fac[1] = 1;
	for(int i = 2; i <= 10; i++){
		fac[i] = i*fac[i-1];
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.in","r",stdin); //freopen("input.out","w",stdout);	
	string fin, beg; cin >> fin >> beg;
	int goal = 0, cur = 0, open = 0;
	for(int i = 0; i < fin.size(); i++){
		if(fin[i] == '+') goal++;
		else goal--;
	}
	for(int i = 0; i < beg.size(); i++){
		if(beg[i] == '+') cur++;
		else if(beg[i] == '-') cur--;
		else open++;
	}
	int total = pow(2, open);
	int diff = abs(goal-cur);
	if(open == 0){
		if(goal == cur) out(1);
		else out(0);
		return 0;
	}
	if(open < diff){
		out(0);
		return 0;
	}
	if(open == diff){
		//only possibility that works is all + or all -
		cout << setprecision(10) << 1 / (double) total << endl;
		return 0;
	}

	//open is now greater than diff

	int plus = 0, minus = 0;
	if(diff % 2 == 0 && open % 2 == 0){
		assert(open > diff);
		// the distance btwn open and abs((goal-cur)) is at least 2
		if(cur > goal){
			//you need to lower the pos of cur string
			minus += diff;
		}
		else if(goal > cur){
			//raise the pos of cur string
			plus += diff;
		}
		// if you have additional open slots
		// split them evenly between plus and minus so the value
		// isn't affected
		plus += (open - diff) / 2;
		minus += (open - diff) / 2;
		

	}
	else if(diff % 2 == 1 && open % 2 == 1){
		assert(open > diff);
		// the distance btwn open and abs((goal-cur)) is at least 1
		if(cur > goal){
			//you need to lower the pos of cur string
			minus += diff;
		}
		else if(goal > cur){
			//raise the pos of cur string
			plus += diff;
		}
		// if you have additional open slots
		// split them evenly between plus and minus so the value
		// isn't affected
		plus += (open - diff) / 2;
		minus += (open - diff) / 2;
	
	}
	else{
		out(0);
		return 0;
	}
	genfac();
	double possible = (fac[plus + minus]) / (double) (fac[plus] * fac[minus]);
	cout << setprecision(10) << possible / (double) total << endl;


}
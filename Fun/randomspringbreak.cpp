//g++ filename.cpp -std=c++14
#include <bits/stdc++.h>
using namespace std;
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

int main()
{
	//freopen("break.in","r",stdin); //freopen("teleport.out","w",stdout);	
	//before you start coding, think it through
	vector<string> ppl = {"Sam", "Rohan", "Ed"};
	vector<string> drivers = {"Michael", "Ryan"};

	shuffle(all(drivers), default_random_engine(30));

	for(int i = 1; i <= 2; i++){
		cout << i << "th driver is " << drivers[i-1] << endl;
	}

	shuffle(all(ppl), default_random_engine(30));

	cout << "first car is " << endl;
	for(int i = 0; i < 3; i++){
		if(i == 1) cout << "second car is " << endl;

		cout << ppl[i] << endl;
	}



}

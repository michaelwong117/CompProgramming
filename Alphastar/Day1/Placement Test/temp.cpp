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
#define endl '\n'
#define out(x) cout << x << endl
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll; typedef vector<int> vi; typedef vector<ll> vl;
typedef pair<int, int> pi; typedef vector<pi> vpi;
typedef pair<ll,ll> pl; typedef vector<array<int,3>> multiv;

struct JOB
{
	long long dead;
	long long prof;
	bool operator <(const JOB &o) const
	{
		return dead < o.dead;
	}
};

long long N;
JOB job[100001];

int main(void)
{
	freopen("input.in","r",stdin);
	cin >> N;
	for(long long i = 0 ; i < N ; i++){
		cin >> job[i].dead >> job[i].prof;
	}
	job[N].dead = 0;
	job[N].prof = 0;
	N++;
	
	sort(job, job + N);
	
	priority_queue<long long> pq;
	long long curTime = 2000000000LL;
	long long profit = 0;
	for(long long i = N - 1 ; i >= 0 ; i--)
	{
		cout << job[i].dead << " " << job[i].prof << " " << scurTime << endl;
		while(curTime > job[i].dead && pq.size())
		{
			curTime--;
			profit += pq.top();
			pq.pop();
		}
		
		curTime = job[i].dead;
		pq.push(job[i].prof);
	}
	cout << profit << endl;

	return 0;
}
//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif
using namespace std;
 
typedef long long ll;
typedef pair<int,int> i2;
typedef pair<ll,ll> ll2;
 
int dp[250001]; //maximize talent
 
int w[251];
int t[251];
 
int n, wReq;
 
int main()
{
    ifstream inf("talent.in");
    ofstream outf("talent.out");
    //outf << setprecision(10);
    ios_base::sync_with_stdio(0); inf.tie(0);
   
    inf >> n >> wReq;
   
    int mxTalent = 0;
   
    for (int i = 1; i <= n; i++)
    {
        inf >> w[i] >> t[i];
        mxTalent += t[i];
    }
   
    for (int i = 1; i <= 250000; i++) dp[i] = 1e9;
   
    for (int i = 1; i <= n; i++) //considering item i
    {
        for (int j = mxTalent; j >= 0; j--) //knapsack talent j
            if (j - t[i] >= 0) dp[j] = min(dp[j], dp[j-t[i]] + w[i]);
    }
   
    int ans = 0;
   
    for (int i = 1; i <= mxTalent; i++)
        if (dp[i] >= wReq) ans = max(ans, int(1000.0*i/dp[i]));
   
    outf << ans << '\n';
   
    return 0;
   
}
//min coins needed / min items needed for knapsack
//capcity i = val[i]
vector<int> val (n);
val[0] = 0;
for(int i = 1; i <= n; i++){
	val[i] = INF;
	for(auto c: coins){
		if(i-c >= 0){
			val[i] = min(val[i], val[i-c]+1);
		}
	}
}
//number of ways to fill knapsack / make sum using coins 
//capcity i = ways[i]
vector<int> ways (n);
ways[0] = 1;
for(int i = 0; i < n; i++){
	for(auto c: coins){
		if(i-c >= 0){
			ways[i] += ways[i-c];
			//take mod m if number of ways is too high
			ways[i] %= m;
		}
	}
}
//number of ways to form some sum w for dp[i]
for(int i = 1; i <= N; i++){
	for(int w = sum-i; w >= 0; w--){
		dp[w+a[i]] += dp[w];
	}
}
//how many different weights you can make with the items

vector<int> weights (N+1);
//w = sum of all the weights
//N is number of weights
bool pos[w+1][N+1];
pos[0][0] = 1;
//you are only using the first i weights
for(int i = 1; i <= N; i++){
	//i2 is whether the weight is possible
	for(int i2 = 0; i2 <= w; i2++){
		//using the ith weight
		if(i2-weights[i] >= 0){
			//you can form weight i2 with first i weights
			pos[i2][i] |= pos[i2-weights[i]][i-1];
		}
		//not using the ith weight
		pos[i2][i] |= pos[i2][i-1];
		
	}
}

//Revised

vector<int> weights (N+1);
//w is sum of all weights
//N is number of weights
bool pos[w+1];
pos[0] = 1;
for(int k = 1; k <= N; k++){
	//if a weight is possible, then you can make that weight + k weight possible
	for(int i = W-weights[k]; i >= 0; i--){
		if(pos[i]) pos[i+weights[k]] = 1;
	}
}

for(int i = 1; i <= n; i++){
  inf >> w[i] >> t[i];
  mxTalent += t[i];
}

for(int i = 1; i <= 250000; i++) dp[i] = 1e9;

for(int i = 1; i <= n; i++){ //considering item i
  for(int j = mxTalent; j >= 0; j--) //knapsack talent j
  	if(j - t[i] >= 0) dp[j] = min(dp[j], dp[j-t[i]] + w[i]);
}

int ans = 0;
//find the biggest one that's greater than some requirement
for(int i = 1; i <= mxTalent; i++)
  if(dp[i] >= wReq) ans = max(ans, int(1000.0*i/dp[i]));



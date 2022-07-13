
ll inv(ll a, ll b){
 return 1<a ? b - inv(b%a,a)*b/a : 1; //uses euclidean algorithm to simplify
}
int findDig(ll n){
	int c = 0;
	while(n > 0){
		n /= 10;
		c++;
	}
	return c;
}

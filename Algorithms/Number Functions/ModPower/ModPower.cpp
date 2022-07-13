//return x^y mod p
ll lpower(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1){

            res = (res*x) % p;
            y--;
        }
 
        // y must be even now
        y = y/2; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}
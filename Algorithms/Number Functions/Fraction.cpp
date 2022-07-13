//if (abs(a-b) < 1e-9) {
    // a and b are equal
//}
class Frac {

    public:
        long long numer, denom;

        Frac() {
            numer = 0;
            denom = 1;
        }

        Frac(long long n, long long d) {
            if (d==0) {
                cerr << "denom may not be 0." << endl;
                exit(0);
            } else if (n == 0) {
                numer = 0;
                denom = 1;
            } else {
                ll sign = 1;
                if (n < 0) {
                    sign *= -1;
                    n *= -1;
                }
                if (d < 0) {
                    sign *= -1;
                    d *= -1;
                }

                long long tmp = gcd(n, d);
                numer = n/tmp*sign;
                denom = d/tmp;
            }
        }

        operator ll() {return (numer)/denom;}
        operator float() {return ((float)numer)/denom;}
        operator double() {return ((double)numer)/denom;}
}; 

Frac operator+(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom
                +rhs.numer*lhs.denom) % MOD,
                (lhs.denom*rhs.denom) % MOD);
    return tmp;
}

Frac operator+=(Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom
                +rhs.numer*lhs.denom) % MOD,
                (lhs.denom*rhs.denom) % MOD);
    lhs = tmp;
    return lhs;
}

Frac operator-(const Frac& lhs, const Frac& rhs) {
    Frac tmp(lhs.numer*rhs.denom
                -rhs.numer*lhs.denom,
                lhs.denom*rhs.denom);
    return tmp;
}

Frac operator-=(Frac& lhs, const Frac& rhs) {
    Frac tmp(lhs.numer*rhs.denom
                -rhs.numer*lhs.denom,
                lhs.denom*rhs.denom);
    lhs = tmp;
    return lhs;
}

Frac operator*(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.numer)%MOD,
               (lhs.denom*rhs.denom)%MOD);
    return tmp;
}

Frac operator*=(Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.numer) % MOD,
               (lhs.denom*rhs.denom) % MOD);
    lhs = tmp;
    return lhs;
}

Frac operator*(ll lhs, const Frac& rhs) {
    Frac tmp((lhs*rhs.numer)% MOD,(rhs.denom) % MOD);
    return tmp;
}

Frac operator*(const Frac& rhs, ll lhs) {
    Frac tmp((lhs*rhs.numer) % MOD,(rhs.denom) % MOD);
    return tmp;
}

Frac operator/(const Frac& lhs, const Frac& rhs) {
    Frac tmp((lhs.numer*rhs.denom) % MOD,
                 (lhs.denom*rhs.numer) % MOD);
    return tmp;
}
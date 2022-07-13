string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
unsigned binary_to_decimal(unsigned num)
{
    unsigned res = 0;

    for(int i = 0; num > 0; ++i)
    {
        if((num % 10) == 1)
            res += (1 << i);

        num /= 10;
    }

    return res;
}
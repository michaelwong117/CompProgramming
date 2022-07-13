/*
ID: fatih
PROG: chain
LANG: C++
*/

#include <iostream>
#include <cmath>

using namespace std;

#define MAX 50              // maximum chain length

int opt[MAX],optn=1000000;  // optimum solution
int curr[MAX],currn;        // current solution

double log_n,log_2;         // optimization: precalc logarithms

// *** exhaustive search
// *** input: n - the number, x - current recursion dept
void rec(int n,int x)
{
    // upper bound: optimum
    if (x+1>=optn) return;
    // check if n is reachable in steps better than current best solution
    // lower bound: ceil(log_2{n/curr[x]}) < optn-x-1
    if (ceil((log_n-log((double)curr[x]))/log_2)>=optn-x-1) return;

    // exit condition
    if (curr[x]==n)
    {
        currn=x+1;
        if (optn>currn) optn=currn;
        return;
    }

    for (int i=x; i>=0; --i)
        if (curr[x]+curr[i]<=n)
        {
            curr[x+1]=curr[x]+curr[i];
            rec(n,x+1);
        }
}

// *** generic greedy function {(2-3-5),(2-3-6),(2-4-8)}
// *** input: x - second, y - third in the chain, n - the number
void greedy(int x,int y,int n)
{
    int i;

    curr[2]=x,curr[3]=y;

    // check special cases: 1-7
    switch (n)
    {
        case 1: currn=1; return;
        case 2: currn=2; return;
        case 3: currn=3,curr[2]=3; return;
        case 4: currn=3,curr[2]=4; return;
        case 5: currn=4,curr[3]=5; return;
        case 6: currn=4,curr[3]=6; return;
        case 7: currn=5,curr[4]=7; return;
    }

    for (i=4; curr[i-1]!=n; ++i)
        for (int j=i-1; j>=0; --j)
            if (curr[i-1]+curr[j]<=n)
            {
                curr[i]=curr[i-1]+curr[j];
                break;
            }

    currn=i;
}

int main()
{
    int n;
    cin >> n;

    curr[0]=1,curr[1]=2;
    log_2=log(2.0);
    log_n=log((double)n);

    greedy(3,5,n);
    optn=min(currn,optn);
    greedy(3,6,n);
    optn=min(currn,optn);
    greedy(4,8,n);
    optn=min(currn,optn);
    rec(n,0);

    cout << optn << endl;
}

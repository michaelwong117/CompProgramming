/*
ID: michaelwong11
PROG: frac1
LANG: C++14
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;



typedef struct Fraction Fraction;

struct Fraction {

    int numerator;
    int denominator;


};

int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0 || b == 0)
       return 0;
 
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

bool lessThan(int a, int b, int c, int d){
    if(b == d){
        return a < c;
    }
    else{
        
        return a*d < c*b;

    }
}

//end = size.()-1
int partition(vector<Fraction> &a, int start, int end){
    Fraction pivot = a[end];
    int pIndex = start;
    for(int i = start; i < end; i++){
        int num = a[i].numerator;
        int denom = a[i].denominator;
        // cout << denom << " " << pivot.denominator << endl;
        if(lessThan(num, denom, pivot.numerator, pivot.denominator)){  
            swap(a[pIndex], a[i]);
            pIndex++;
        }

    }
    swap(a[pIndex], a[end]);
    return pIndex;


}

void quickSort(vector<Fraction> &a, int start, int end){
    if(start < end){
        int pIndex = partition(a, start, end);
        quickSort(a, start, pIndex-1);
        quickSort(a, pIndex+1, end);
    }
}





int main(){

	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	int n;
	vector<Fraction> fractions;
	fin >> n;
	//generate a list of all possible fractions a / b where  0 <= a <= b and b (1....n)

    Fraction s;
    s.numerator = 0;
    s.denominator = 1;
    fractions.push_back(s);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= i; j++){
			Fraction a;
			a.numerator = j;
			a.denominator = i;
            if(gcd(j, i) == 1){
                fractions.push_back(a);
            }

			// cout << j << " " << i << endl;
			
		}
	}
    quickSort(fractions, 0, fractions.size()-1);
	for(auto f: fractions){
		fout << f.numerator << "/" << f.denominator << endl;
	}
	




}
/*
ID: michaelwong11
PROG: hamming
LANG: C++14     
*/

//g++ hammingcodes.cpp -std=c++14 -DH

#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()


const int MOD = 1000000007;

vector<string> v;

int N, B, D;

unsigned b2d(unsigned num)
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


void gen(string s){
	if(s.size() == B){
		v.push_back(s);
	}
	else{
		gen(s + "0");
		gen(s + "1");
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");
	fin >> N >> B >> D;
	vector<string> codes;
	gen("");
	for(int i = 0; i < v.size(); i++){
		bool valid = 1;
		for(int j = 0; j < codes.size(); j++){
			int diff = 0;
			for(int k = 0; k < B; k++){
				if(v[i][k] != codes[j][k]) diff++;
			}
			if(diff < D){
				valid = 0;
				break;
			}
		}
		if(valid) codes.push_back(v[i]);
		if(codes.size() == N) break;
	}
	for(int i = 1; i <= codes.size(); i++){
		if(i % 10 == 0 || i == codes.size()) fout << b2d(stoi(codes[i-1])) << endl;
		else fout << b2d(stoi(codes[i-1])) << " ";
	}

	
	
}
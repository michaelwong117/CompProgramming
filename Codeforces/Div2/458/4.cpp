#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>


#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3
int gcd(int a, int b){
    if (a == 0) return b;
    return gcd(b%a, a);
}
 
// Function to find gcd of array of
// numbers
int GCD(vector<int> v, int N){

    int res = v[0];
    for (int i = 1; i < N; i++){
        res = gcd(arr[i], res);
    }
 
    return res;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	fin >> n;
	vector<int> v (n);
	for(int i = 0; i < n; i++){
		fin >> v[i];
	}
	int q;
	fin >> q;
	for(int i = 0; i < q; i++){
		int a;
		fin >> a;
		if(a == 1){
			int l, r, x;
			fin >> l >> r >> x;
		}
		else{
			int i, y;
			fin >> i >> y;
			v[i] = y;
		}
	}

	
}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <cmath>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

bool is_perfect(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	cin >> n;
	vector<int> v (n);
	int max = -99999999;
	for(int i = 0; i < n; i++){
		cin >> v[i];
		if(!is_perfect(v[i])){
			if(v[i] > max){
				max = v[i];
			}
		}
	}
	cout << max << endl;
	
}
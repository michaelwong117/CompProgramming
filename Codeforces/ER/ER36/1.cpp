#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n, k;
	cin >> n >> k;
	int max = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		if(a > max && k % a == 0){
			max = a;
		}
		
	}
	cout << k / max << endl;

	
	
}
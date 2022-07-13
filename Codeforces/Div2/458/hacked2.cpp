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

map<int, int> used;

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	int n;
	fin >> n;
	int arr[n];
	for (int i = 0; i < n; i++){
		int x;
		fin >> x;
		arr[i] = x;
		used[x]++;
	}
	bool ok = 1;
	for(int i = 0; i < n; i++){
		ok &= (used[arr[i]] % 2 == 0);
	}
	if(ok){
		cout << "Agasa" << endl;
	}
	else{
		cout << "C" << endl;
	}
	
	
}
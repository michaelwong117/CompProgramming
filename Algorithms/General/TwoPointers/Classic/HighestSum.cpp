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
#include <cmath>

#define ll long long
#define fir first
#define sec second
#define MOD 1e9 + 7


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
	vector<int> v = {1, 3, 7, 11, 14, 16, 24};
	int key = 40;
	int i = 0, j = v.size()-1;
	while(i != j){
		if(v[i] + v[j] < key){
			i++;
		}
		else if(v[i] + v[j] > key){
			j--;
		}
		else{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
}
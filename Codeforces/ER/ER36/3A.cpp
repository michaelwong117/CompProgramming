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

int findS(string copy, char b, bool leading){
	for(int i = 0; i < copy.length(); i++){
		if(copy[i] - '0' <= b - '0'){
			if(!leading && copy[i] == '0'){
				continue;
			}
			else{
				return i;
			}
		}
	}
	return 0;
	
}
int maxPerm(int num){
	int count[10] = {0};

	string str = to_string(num);

	for (int i=0; i<str.length(); i++)
	 count[str[i]-'0']++;

	int result = 0, multi = 1;

	for (int i = 0; i <= 9; i++)
	{
	 while (count[i] > 0)
	 {
	     result = result + (i * multi);
	     count[i]--;
	     multi = multi * 10;
	 }
	}

	return result;
}



int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	string a, b;
	fin >> a >> b;
	// cout << maxPerm(stoi("58920231")) << endl;
	if(b.size() > a.size()){
		cout << maxPerm(stoi(a)) << endl;
		return 0;
	}
	string copy = a;
	bool leading = 0;
	for(int i = 0; i < a.length(); i++){
		if(a[i] > b[i]){
			//find anything equal to or lower b
			int found = findS(copy, b[i], leading);
			copy.erase(copy.begin()+found);
			a[i] = copy[found];
			if(found != '0'){
				leading = 1;
			}
		}
		else if(a[i] < b[i]){
			int found = findS(copy, b[i], leading);
			copy.erase(copy.begin()+found);
			a[i] = copy[found];
			if(found != '0'){
				leading = 1;
			}

		}
		else{
			copy.erase(copy.begin()+i);
		}
	}
	cout << a << endl;

	
}
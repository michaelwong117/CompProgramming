
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	int n, count = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		char check = s[i];
		for(int j = i+1; j < n; j++){
			if(s[j] == check){
				i++;
				count++;

			}
			else{
				break;
			}
		}
	}
	cout << count << endl;


}
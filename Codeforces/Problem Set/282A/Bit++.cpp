#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 

	int n, x = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s[0] == 'X'){
			if(s.substr(1, 2) == "--"){
				x--;
			}
			else{
				x++;
			}

		}
		else{
			if(s.substr(0, 2) == "--"){
				x--;
			}
			else{
				x++;
			}
		}
	}
	cout << x << endl;
	


}
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 

	int n, count = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		if((a == 1)&&(b == 1)){
			count++;
		}
		else if((a == 1)&&(c == 1)){
			count++;
		}
		else if((b == 1)&&(c == 1)){
			count++;
		}
		

	}
	cout << count << endl;


}
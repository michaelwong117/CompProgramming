#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 

	string a, b;
	bool found = false;
		
	cin >> a >> b;

	for(int i = 0; i < a.length(); i++){
		if(tolower(a[i]) - '0' > tolower(b[i]) - '0'){
			cout << 1 << endl;
			found = true;
			break;
		}
		else if(tolower(a[i]) - '0' < tolower(b[i]) - '0'){
			cout << -1 << endl;
			found = true;
			break;
		}
	}
	if(!found){
		cout << 0 << endl;
	}


}
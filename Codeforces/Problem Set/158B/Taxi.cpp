#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){ 

	int n, count = 0, threes = 0, twos = 0, ones = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;

		if(a == 4){
			count++;
		}
		else if(a == 3){
			threes++;
		}
		else if(a == 2){
			twos++;
		}
		else{
			ones++;
		}

		
	}
	//put three and one together 
	//put two and two ones together
	//put two and two together
	//put two and one together
	//put one four times, one three times, etc.
	while((threes > 0)&&(ones > 0)){
		threes--;
		ones--;
		count++;
	}
	while((twos > 1)){
		twos -= 2;
		count++;
	}
	while((twos > 0)&&(ones > 1)){
		twos--;
		ones -= 2;
		count++;
	}
	while((twos > 0)&&(ones > 0)){
		twos--;
		ones--;
		count++;
	}
	if(ones < 4){
		if(ones > 0){
			count++;
		}
	}
	else if(ones % 4 == 0){
		count += ones / 4;
	}
	else{
		count += ones / 4 + 1;
	}

	cout << count+threes+twos << endl;
	

}
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
#include <bitset>

using namespace std;

bool isbeautiful(int n){
	int k;
	string binary = bitset<128>(n).to_string();
	// cout << binary << endl;
	int start = binary.find_first_of('1');
	binary = binary.substr(start, binary.length()-start);
	// cout << binary << endl;
	if(binary.length() & 1){
		k = (binary.length()-1) / 2;
		// cout << k << endl;
		for(int i = 0; i <= k; i++){
			// cout << "fir = " << binary[i] << endl;
			if(binary[i] != '1'){
				return false;
			}
		}
		for(int i = k+1; i <= 2*k; i++){
			// cout << "sec = " << binary[i] << endl;
			if(binary[i] != '0'){
				return false;
			}
		}
	}
	else{
		return false;
	}
	return true;

}

vector<int> getDivisors(int n)
{
	vector<int> out;
    // Note that this loop runs till square root
    for (int i=1; i<=sqrt(n)+1; i++)
    {
        if (n%i==0)
        {
            // If divisors are equal, print only one
            if (n/i == i)
                out.push_back(i);
 
            else // Otherwise print both
            	out.push_back(i);
            	out.push_back(n/i);
        }
    }
    return out;
}


int main(){
	int num;
	cin >> num;
	// num = 258;
 
	vector<int> divisors;
	divisors = getDivisors(num);
	// for(auto a: divisors){
		// cout << a << endl;
	// }
	int max = 0;
	for(int i = 0; i < divisors.size(); i++){
		int test = divisors[i];
		// cout << test << endl;
		if(isbeautiful(test)){
			if(test > max){
				max = test;
			}
		}
	}
	cout << max << endl;
	// cout << isbeautiful(1) << endl;



	
}
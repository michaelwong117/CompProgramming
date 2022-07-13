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

using namespace std;

class SmartWordToy {
	public:
   		int minPresses(string &s, string &f, vector<string> &con);
        
};

int SmartWordToy::minPresses(string &s, string &f, vector<string> &con) {
    // return the answer
    //either go forward until you reach state or backwards and take min
	//if you can't go either forward or backward than return -1
	string org = s;
	int c, total = 0;
	bool dir = 1;
	//if it is 96 convert it to 122
	//add or subtract from ascii values and convert to check
	for(int i = 0; i < 4; i++){
		bool v1 = 1, v2 = 1;
		int min = 999999999;
		for(int j = 0; j < 2; j++){
			c = 0;
			s = org;
			if(j == 1){
				dir = 0;
			}
			if(con[i].find(f[i]) != string::npos){	
				return -1;
			}
			if(dir){
				while(s[i] != f[i]){
					if(con[i].find(s[i]) != string::npos){	
						v1 = 0;
						break;
					}
					c++;
					if((int) s[i] + 1 > 122){
						s[i] = 'a';
					}
					else{
						s[i] = ((int) s[i]) + 1;
					}
					
					
				}
			
			}
			else{
				while(s[i] != f[i]){
					if(con[i].find(s[i]) != string::npos){	
						v2 = 0;
						break;
					}
					c++;
					if((int) s[i] - 1 < 97){
						s[i] = 'z';
					}
					else{
						s[i] = ((int) s[i]) - 1;
					}
					
				}


			}
			if(c < min){
				min = c;
			}
			

		}
		if(!v1 && !v2){
			return -1;
		}
		total += min;
		
		
	}
	

	return total;
}


int main(){
	SmartWordToy S;
	vector<string> = {"a a a z", "a a z a", "a z a a", "z a a a", "a z z z", "z a z z", "z z a z", "z z z a"}

	
	cout << (char) 122 << endl;
	cout << (int) 'a' << endl;


}
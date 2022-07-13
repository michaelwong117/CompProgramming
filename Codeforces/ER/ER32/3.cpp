#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>

using namespace std;


int main(){

	string s;
	
	cin >> s;
	// s = "abcde";
	string a = "abcdefghijklmnopqrstuvwxyz";
	set<int> maxes;
	for(int i = 0; i < a.length(); i++){
		if(s.find(a[i]) == string::npos){
			continue;
		}
		else{
			int max = 0;
			int first = -1, current = -1, next = -1, last = -1;
			for(int j = 0; j < s.length(); j++){
	
				if(s[j] == a[i]){

					last = j;


					if(first == -1){
						first = j;
						current = first;
					}

					else if(next == -1){
						next = j;
					}
				
					if(next - current - 1 > max && current != -1 && next != -1){
						// cout << a[i] << " " << current << " " << next << " " << next - current - 1 << endl;
						max = next - current - 1;
					}

					if(first != -1 && next != -1){
						current = next;
						next = -1;
					}
					

				}


			}
			// cout << a[i] << " from first " << first << endl;
			// cout << a[i] << " from last " << (s.length()-1) - last << endl;
			if(first > max){
				max = first;
				// cout << max << endl;
				// cout << a[i] << " " << max << endl;
			}

			if((s.length()-1) - last > max){
				max = (s.length()-1) - last;
				// cout << a[i] << " " << max << endl;
			}
			maxes.insert(max+1);
		}

	}
	for(auto m: maxes){
		cout << m << endl;
		break;
	}

	


	
}
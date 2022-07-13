#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <map>

using namespace std;

map<int, vector<int>> final;

int findGCD(vector<int> &v)
{
    int result = v[0];
    for (int i=1; i<v.size(); i++)
        result = __gcd(v[i], result);
 
    return result;
}

void getSubsequences(vector<int> &v){
	

	for(int i = 0; i < v.size(); i++){


		for(j = i; j < v.size(); j++){

			vector<int> sum;

			for(int k = i; k <= j; k++){


				sum.push_back(v[k]);

			}
			int a = findGCD(sum);
			if(final.count(a) == 0){
				final[a] = sum;
			}
			else{
				for(auto s: sum){
					final[a].push_back(s);
				}
			}
			
			


		}
	}
	
}


int main(){
	int n;
	cin >> n;
	vector<int> gcd, output;
	int a[n];
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		gcd.push_back(a);
	}
	vector<int> ss = getSubsequencesGCD(gcd);
	for(auto a: gcd){
		int count = 0;
		for(auto x: final){
			if(find(x.second.begin(), x.second.end(), a) != x.second.end()){
				count++;
			}
		}
		if(count > 1){
			output.push_back(a);
		}
	}









	
}
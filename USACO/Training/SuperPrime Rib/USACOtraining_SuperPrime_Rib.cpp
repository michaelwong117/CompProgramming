/*

ID: michaelwong11
PROG: sprime
LANG: C++14

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

bool isPrime(int num) {
    if (num <= 3) {
        return num > 1;
    } else if (num % 2 == 0 || num % 3 == 0) {
        return false;
    } else {
        for (int i = 5; i * i <= num; i += 6) {
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}


vector<int> generateSuperPrimes(int n){
	//generate all one digit primes, then two, then three, etc.
	//until you finally reach all n digit primes
	//build two digit primes using one digit, three digit primes using two digit, etc.

	//base case
	if(n == 0){
		return {0};
	}
	vector<int> primeRib, newPrimeRib;
	primeRib = generateSuperPrimes(n-1);
	for(int i = 0; i < primeRib.size(); i++){
		for(int j = 1; j <= 9; j++){
			//handle base case
			if(primeRib[i] == 0){
				if(isPrime(stoi(to_string(j)))){
					newPrimeRib.push_back(j);
				}
			}
			//if not base case previous, append odd numbers to existing primeribs inside
			//primeRib. If prime, add the new number.
			else{
				if(isPrime(stoi(to_string(primeRib[i])+to_string(j)))){
					newPrimeRib.push_back(stoi(to_string(primeRib[i])+to_string(j)));
				}
			}
		}
	}
	return newPrimeRib;


}



int main(){

	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int n;
	fin >> n;
	vector<int> superPrimeRibs = generateSuperPrimes(n);
	for(auto primeRib: superPrimeRibs){
		fout << primeRib << endl;
	}

}
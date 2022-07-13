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

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}


int productOfSubsetSums(vector<int> v, int n)
{
    int ans = 1;
    for (int i = 0; i < size; ++i )
        ans = ans * (v[i] + 1);
    return ans-1;
}
 


int main(){

	ifstream fin("input.in");
	int n;
	fin >> n;
	vector<int> v (n);
	for(int i = 0; i < n; i++){
		fin >> v[i];
	}
	getsubSets(v);

}
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
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;

//set tab size to 3

vector<pll> price;
vector<pll> temp;

ll milk(ll quant){
	temp = price;
	ll i = 0;
	ll sum = 0;
	// cout << quant << " " << price.size() << endl;
	while(quant != 0 && i < temp.size()){
		//sell as many as possible at highest price
		ll q = min(quant, temp[i].sec);
		//adding the max quantitiy possible * price
		sum += q * temp[i].fir;
		//quantity decreases
		temp[i].sec -= q;
		quant -= q;
		//if there is no more left to sell, move to next
		if(temp[i].sec == 0){
			i++;
		}
	}
	return sum;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("rental.in");
	ofstream fout("rental.out");
	ll N, M, R;
	fin >> N >> M >> R;
	vector<ll> cows (N);
	price.resize(M);
	vector<ll> rent (R);
	vector<ll> pcows (N);
	vector<ll> prent (R);
	for(ll i = 0; i < N; i++){
		fin >> cows[i];
		if(i == 0){
			pcows[i] = cows[i];
		}
		else{
			pcows[i] += cows[i-1] + cows[i];
		}
	}
	for(ll i = 0; i < M; i++){
		ll q, p;
		fin >> q >> p;
		price[i] = pll(p, q);
	}
	for(ll i = 0; i < R; i++){
		fin >> rent[i];
		if(i == 0){
			prent[i] = rent[i];
		}
		else{
			prent[i] += rent[i-1] + rent[i];
		}
	}
	sort(rent.begin(), rent.end(), greater<ll>());
	sort(price.begin(), price.end(), greater<pll>());
	sort(cows.begin(), cows.end(), greater<ll>());
	for(ll i = 0; i < N; i++){
		if(i == 0){
			pcows[i] = cows[i];
			// cout << pcows[i] << endl;
		}
		else{
			pcows[i] = pcows[i-1] + cows[i];
			// cout << cows[i-1] << " " << cows[i] << endl;
		}
	}
	for(ll i = 0; i < R; i++){
		if(i == 0){
			prent[i] = rent[i];
		}
		else{
			prent[i] = prent[i-1] + rent[i];
		}
	}
	// for(auto a: price){
	// 	cout << a.fir << " " << a.sec << endl;
	// }
	// for(auto a: pcows){
	// 	cout << "pcows " << a  << endl;
	// }
	// for(auto a: prent){
	// 	cout << "prent " << a << endl;
	// }
	//pcows prefix sum of cows to milk
	//prent prefix sum of cows to rent
	//run a for loop through all possibilties
	//milk zero, rent all, milk one, rent else, milk two, rent else... milk all
	//Linear Time
	//milk as many cows as possible
	//if there are cows > M, milk M
	//if there are cows <= M, milk cows
	// // cout << "iCow " << iCow << " store " << store << " iRent " << iRent << endl;
	// // cout << all << endl;
	ll max = 0;
	ll iCow = pcows.size()-1, store = M-1, iRent = prent.size()-1;
	ll all = milk(pcows[iCow]);
	if(all > max){
		max = all; 
	}
	//rent as many cows as possible
	//if there are cows > R, rent R
	//if there are cows <= R rent all
	// cout << prent[min(iRent, iCow)] << endl;
	if(prent[min(iRent, iCow)] > max){
		max = prent[min(iRent, iCow)];
	}
	for(ll i = 0; i < pcows.size(); i++){
		ll rest = iCow-i-1;
		// cout << "milking " << pcows[i] << " amount ";
		// cout << milk(pcows[i]) << " renting ";
		// cout << prent[min(iRent, rest)] << " all rents ";
		// cout << iRent << " availible " << rest << " " << endl;
		ll cur = milk(pcows[i]) + prent[min(iRent, rest)];
		if(cur > max){
			max = cur;
		}
	}
	

	fout << max << endl;

	
}
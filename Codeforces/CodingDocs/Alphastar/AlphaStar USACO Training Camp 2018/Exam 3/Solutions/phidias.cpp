#include <algorithm>
#include <iostream>
#define optimizar_io ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m;
int DP[602][602];
int C[602][602];
int k, x, y;

int main(){

	optimizar_io
	cin >> n >> m >> k;
	for( int i = 1; i <= k; i++ ){
		cin >> x >> y;
		C[x][y] = 1;
	}

	int x, y, x1, y1, lim;
	for( x = 1; x <= n; x++ ){
		for(  y = 1;  y <= m; y++ ){

			if( C[x][y] ) continue;
			DP[x][y] = x * y;

			lim = x / 2;
			for( x1 = 1; x1 <= lim; x1++ )
				DP[x][y] = min( DP[x][y], DP[x1][y] + DP[x - x1][y] );

			lim = y / 2;
			for( y1 = 1; y1 <= lim; y1++ )
				DP[x][y] = min( DP[x][y], DP[x][y1] + DP[x][y - y1] );

		}
	}
	cout << DP[n][m] << "\n";

	return 0;

}

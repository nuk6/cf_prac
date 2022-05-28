
// Prob : https://codeforces.com/contest/1681/problem/B
#include<bits/stdc++.h>
using namespace std;
 
const int MX = 210000;
long a[MX];
long long b,x,ans;
 
int main() {
	int t,n,m;
	cin >> t;
	while(t--) {
		ans = 0;
		cin >> n;
		for(int i = 0; i < n; ++i) cin >> a[i];
		cin >> m;
		for(int i = 0; i < m; ++i) cin >> x, ans += x; ans %= n;
		cout << a[ans] << endl;
	}
	return 0;
}

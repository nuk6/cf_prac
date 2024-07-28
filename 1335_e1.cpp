#include <bits/stdc++.h>
using namespace std;
int cnt[201][200001];
int a[200001];

int g(int l, int r) {
	int mx = 0;
	for(int i = 1; i <= 200; ++i) {
		mx = max(mx, cnt[i][r] - cnt[i][l-1]);
	}
	return mx;
}

void fix(int (&cnt)[201][200001], int n) {
	for(int i = 1; i <= 200; ++i) {
		for(int j = 0; j < n; ++j) {
			cnt[i][j] = 0;
		}
	}
}

int main() 
{
    int t, n, x, mv = -1;
    cin >> t;
    while(t--) {
    	vector<int> f[201];
    	cin >> n;
    	fix(cnt, n);
    	for(int i = 0; i < n; ++i) {
    		cin >> x;
    		a[i] = x;
    		f[x].push_back(i);
    		for(int j = 1; j <= 200; ++j) 
    			cnt[j][i] += cnt[j][i-1] + (a[i] == j), mv = max(mv, cnt[j][i]);
    	}
    	int ans = 1;
    	for(int i = 1; i <= 200; ++i) {
    		int lo = 0, hi = f[i].size() - 1;
    		while(lo < hi) {
    			int pl = f[i][lo];
    			int ph = f[i][hi];
    			int o1 = g(pl + 1, ph - 1);
    			ans = max(ans, 2*(lo+1) + o1);
    			lo++, hi--;
    		}
    	}
    	cout << ans << endl;
    }
    return 0;
}

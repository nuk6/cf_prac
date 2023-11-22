#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char const *argv[])
{
	int t,n,x,y;
	ll m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		map<ll, vector<ll>> mp;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			mp[x].push_back(y);
		}
		priority_queue<ll, vector<ll>, greater<int>> pq;
		int mx, mn;
		mx = 0;
		mn = INT_MAX;
		for(auto [k,v]: mp){
		   for(auto it: v) {
		   		while(!pq.empty() && k > pq.top()) {
		   			pq.pop();
	   			}
		   		pq.push(it);
		   }
		   mx = max(mx, (int) pq.size());
		   mn = min(mn, (int) pq.size());
		}
		while(!pq.empty() && m > pq.top()) pq.pop();
		mn = min(mn, (int) pq.size());
		//cout << "Mx =" << mx << "Mn = " << mn << endl;
		cout << "Ans = ::: "<< mx-mn << endl;
	}
    return 0;
}

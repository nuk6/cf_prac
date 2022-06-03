#include<bits/stdc++.h>
using namespace std;
using cvi = const vector<int>&;
using pii = pair<int,int>;
 
const int MX = (int)(2*10e5+1);
const int MN = -1*MX;
long long a[MX], l[MX], r[MX], b[MX];
 
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	l[0] = -1;
	stack<long long> stk;
	stk.push(-1);
	for(int i = 0; i < n; ++i) {
		while(stk.top() != -1 && a[stk.top()] >= a[i]) {
			stk.pop();
		}
		l[i] = stk.top();
		stk.push(i);
	}
	while(!stk.empty()) stk.pop();
	stk.push(n);
	for(int i = n-1; i >= 0; --i) {
		while(stk.top() != n && a[stk.top()] >= a[i]) {
			stk.pop();
		}
		r[i] = stk.top();
		stk.push(i);
	}
	fill(b,b+MX, MN);
	for(int i = 0; i < n; ++i) {
		//cout << r[i]-l[i]-1 << " ";
		b[r[i]-l[i]-1] = max(b[r[i]-l[i]-1], a[i]);
	}
	for(int i = n; i >= 1; --i) {
		b[i] = max(b[i], b[i+1]);
	}
	for(int i = 1; i <= n; ++i) {
		cout << b[i] << " ";
	}

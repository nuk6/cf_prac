#include<bits/stdc++.h>
using namespace std;

using cvi = const vector<int>&;
using vs = vector<string>;
using vvs = vector<vs>;
using vi = vector<int>;
using pii = pair<int,int>;
using umii = unordered_map<int,int>; 

long long dp[10][50];
string s;
int n;

bool own_num = false;

long long f(int d, int l, bool h) {
	if(d == 3) {
			cout << "l = " << l << " d = " << d << " h = " << h <<endl;
	}
	if(l == n-1) {
		//cout << "l = " << l << " d = " << d << " h && s[l] == d = " << (h)<<endl;
		if(h) {
			own_num = true;
		}
		return 1;
	}
	if(dp[d][l] != -1) {
		return dp[d][l];
	}
	int next = s[l+1] - '0';
	int next_digit;
	if((d+next)%2 == 1) {
		next_digit = (d+next)/2;
		dp[d][l] = f(next_digit, l+1, (h && (next == next_digit)));
		dp[d][l] += f(next_digit+1, l+1, (h && (next == next_digit+1)));
	} else {
		next_digit = (d+next)/2;
		dp[d][l] = f(next_digit, l+1, (h && (next == next_digit)));
	}
	return dp[d][l];
}

long long get(string s) {
	long long ans = 0;
	for(int i = 0; i <= 9; ++i) {
		ans += f(i,0, (i == s[0]-'0'));
	}
	cout << "Own" << own_num;
	return ans - own_num;
}

int main() {
	memset(dp, -1, sizeof dp);
	cin >> s;
	n = s.size();
	cout << get(s) << endl;
	return 0;
}

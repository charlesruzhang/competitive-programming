#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<int> P(N);
	for(int i = 0; i < N; i++){
		cin >> P[i];
		P[i]--;
	}
	vector<int> invP(N);
	for(int i = 0; i < N; i++){
		invP[P[i]] = i;
	}
	for(int a = 0; a < N; a++){
		int i = a;
		while(i >= 2){
			if(invP[i] < min(invP[i-1], invP[i-2])){
				swap(invP[i], invP[i-1]);
				swap(invP[i-1], invP[i-2]);
				i -= 2;
			} else break;
		}
	}
	for(int i = 0; i < N; i++){
		P[invP[i]] = i;
	}
	for(int i = 0; i < N; i++){
		cout << (1+P[i]) << " \n"[i+1 == N];
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}

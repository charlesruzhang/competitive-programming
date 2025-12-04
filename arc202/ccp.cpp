#include <bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll N=200010,mxV=200000;
constexpr ll mod=998244353;
ll n,a[N],mu[N],cnt[N],s[N],is[N],scnt[N],vs[N];
vector<ll> fact[N];
ll qpow(ll a,ll b=mod-2){
	ll ans=1;
	for(;b;b/=2,(a*=a)%=mod){
		if(b%2){
			(ans*=a)%=mod;
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	s[0]=0;
	for(ll i=1;i<=mxV;i++){
		s[i]=(s[i-1]*10+1)%mod;
		is[i]=qpow(s[i]);
		for(ll j=i;j<=mxV;j+=i){
			fact[j].push_back(i);
		}
	}
	mu[1]=1;
	for(ll i=2;i<=mxV;i++){
		for(ll j:fact[i]){
			if(j<i){
				mu[i]+=mu[j];
			}
		}
		mu[i]=-mu[i];
	}
	cin>>n;
	ll ans=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(!vs[a[i]]){
			vs[a[i]]=1;
			for(ll j:fact[a[i]]){
				cnt[j]++;
				if(cnt[j]==1){
					for(ll k:fact[j]){
						if(mu[j/k]==1){
							(ans*=s[k])%=mod;
						}
						if(mu[j/k]==-1){
							(ans*=is[k])%=mod;
						}
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
#include<cstdio>
#define LL long long
const int N=100050;
int prime[N],cnt=0,phi[N];
LL n,sum[N],ans=0;
void init()
{
    phi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if (!phi[i]) prime[++cnt]=i,phi[i]=i-1;
        for(int j=1;j<=cnt;j++)
        {
            if (prime[j]*i>n) break;
            if (i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }		
    }
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+phi[i];
}
int main()
{
    scanf("%lld",&n);
    init();
    for(LL i=1;i<=n;i++) 
        ans+=(sum[n/i]*2-1)*i;
    printf("%lld",ans);
    return 0;
}

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


long long dp[20][2][2][2][2];
long long dfs(string&s,int indx,bool prevsame,bool ok4,bool ok9,bool ok5)
{
    if(indx==s.size())
    {
        if(ok4&&ok9&&ok5)return 1;
        return 0;
    }
    if(dp[indx][prevsame][ok4][ok9][ok5]!=-1) return dp[indx][prevsame][ok4][ok9][ok5];
    long long ans=0;
    long long currval=s[indx]-'0';
    if(!prevsame) currval=9;
    for(int i=0;i<=currval;i++)
    {
        if(i==0&&indx==0) continue;
        if(prevsame&&i==currval)
        {
            if(i==4)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,1,1,1,1);
                else ans+=dfs(s,1+indx,1,1,0,0);
            }
            else if(i==9)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,1,1,1,1);
                else if(ok4&&!ok9&&!ok5) ans+=dfs(s,1+indx,1,1,1,0);
                else ans+=dfs(s,1+indx,1,0,0,0);
            }
            else if(i==5)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,1,1,1,1);
                else if(ok4&&ok9&&!ok5) ans+=dfs(s,1+indx,1,1,1,1);
                else ans+=dfs(s,1+indx,1,0,0,0);
            }
            else
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,1,1,1,1);
                else ans+=dfs(s,1+indx,1,0,0,0);
            }
        }
        else
        {
            if(i==4)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,0,1,1,1);
                else ans+=dfs(s,1+indx,0,1,0,0);
            }
            else if(i==9)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,0,1,1,1);
                else if(ok4&&!ok9&&!ok5) ans+=dfs(s,1+indx,0,1,1,0);
                else ans+=dfs(s,1+indx,0,0,0,0);
            }
            else if(i==5)
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,0,1,1,1);
                else if(ok4&&ok9&&!ok5) ans+=dfs(s,1+indx,0,1,1,1);
                else ans+=dfs(s,1+indx,0,0,0,0);
            }
            else
            {
                if(ok4&&ok9&&ok5) ans+=dfs(s,1+indx,0,1,1,1);
                else ans+=dfs(s,1+indx,0,0,0,0);
            }
        }
    }
    return dp[indx][prevsame][ok4][ok9][ok5]=ans;
}





long long getans(string&s)
{
    if(s.size()<3) return 0;
    int diff=s.size()-4;
    long long ans=0;
    if(diff!=-1) ans=1;
    for(int i=1;i<=diff;i++)
    {
        ans+=(long long)i*(long long)9*(long long)pow(10,i-1);
        ans+=(long long)pow(10,i);
    }
    memset(dp,-1,sizeof(dp));
    long long temp=dfs(s,0,1,0,0,0);
    //cout<<s<<" ans is: "<<ans<<" dfs res: "<<temp<<endl;
    return temp+ans;
}



int main()
{
    long long left,right;
    cin>>left>>right;
    left--;
    string l=to_string(left);
    string r=to_string(right);
    cout<<getans(r)-getans(l);
    return 0;
}
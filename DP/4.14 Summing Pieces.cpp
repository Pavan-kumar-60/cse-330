 #include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define inf 1000000000000
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define S second
#define F first
#define boost1 ios::sync_with_stdio(false);
#define boost2 cin.tie(0);
#define mem(a,val) memset(a,val,sizeof a)
#define endl "\n"
#define maxn 1000001

ll power[maxn],sub[maxn],pre[maxn],suff[maxn],a[maxn];

ll ways(ll x)
{
    if(x==0)
    return 1;
    return power[x-1];
}
int main()
{
    boost1;boost2;    
    ll i,j,n,q,x,y,sum=0,ans=0;
    power[0]=1;
    for(i=1;i<=1000000;i++)
    power[i]=(2*power[i-1])%mod;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        sum%=mod;
    }    
    for(i=1;i<=n;i++)
    pre[i]=(pre[i-1]+a[i])%mod;
    for(i=n;i>=1;i--)
    suff[i]=(suff[i+1]+a[i])%mod;
    
    sub[1]=sum;
    for(i=2;i<=n;i++)
    {
        sub[i]=sub[i-1];
        sub[i]=(sub[i]+suff[i])%mod;
        sub[i]=(sub[i]-suff[n-i+2]+mod)%mod;
    }    

    for(i=1;i<=n-2;i++)
    {
        x=sub[i];
        x=(x-pre[i]+mod)%mod;
        x=(x-suff[n-i+1]+mod)%mod;
        ans=(ans+(((i*power[n-i-2])%mod)*x)%mod)%mod;
    }
    for(i=1;i<=n;i++)
    ans=(ans+(((i*pre[i])%mod)*ways(n-i))%mod)%mod;
    for(i=n;i>1;i--)
    ans=(ans+((((n-i+1)*suff[i])%mod)*ways(i-1))%mod)%mod;
    cout<<ans;
    return 0;
}


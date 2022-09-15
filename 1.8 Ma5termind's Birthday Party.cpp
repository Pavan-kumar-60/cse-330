#include<bits/stdc++.h> 
using namespace std;
int prime[1000001];
int f[1000001];
void sieve()
{
    for(int i=0;i<=1000001;i++)
    prime[i]=1;
    prime[0]=0,prime[1]=0;
    for(int i=2;i*i<=1000001;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=1000001;j+=i)
            prime[j]=0;
        }
    }prime[4]=1,prime[1]=0;
    for(int i=1;i<=1000001;i++)
    {
        if(prime[i]==0)
        f[i]=f[i-1]+1;
        else
        f[i]=f[i-1];
    }
}
int main()
{
     ios_base::sync_with_stdio(false);cin.tie(0);
    sieve();
    //cout<<f[15]<<" "<<f[10];
    int t;
    cin>>t;
    while(t--)
    {
    int l,r;
    cin>>l>>r;
    if(l==1)
    cout<<f[r];
    else
    cout<<f[r]-f[l-1];
    cout<<"\n";
    }
}

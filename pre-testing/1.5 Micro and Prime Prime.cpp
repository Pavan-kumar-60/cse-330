#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define pb push_back
#define Mp make_pair
#define e '\n'
#define fl(x,n) for(ll i{x};i<n;i++)
#define fl2(x,n) for(ll i{x};i>=n;i--)
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007;
#define PI acos(-1)
using namespace std;
template<class X>
void print(const X a)
{
    for(auto it:a)
    cout << it << " ";
    cout << e;
}
bool prime[1000001];
bool cc[1000001];
int pre[1000001];
void seive()
{
    int c=0;
    prime[0]=prime[1]=true;
    
    for(int i=2;i*i<=1000001;i++)
    {
        if(!prime[i]){
            for(int j=i*i;j<=1000001;j+=i)
                prime[j]=true;
        }
    }
    for(int i=1;i<=1000001;i++){
        if(!prime[i])c++;
        if(!prime[c])cc[i]=true;
    }
    for(int i=1;i<=1000001;i++)
    {
        if(cc[i])
        pre[i]=pre[i-1]+1;
        else
        pre[i]=pre[i-1];
    }
 
}
void solve()
{
   
    
    int l,r,c=0;
    cin >> l >>r;
    //for(int i=l;i<=r;i++)
    //cout << pre[i]
    cout << pre[r]-pre[l-1] << e;
    
 
 
}
int main()
{
    
    seive();
    FIO;
    int t;
    cin >> t;
    while(t--)
    solve();
 
    return 0;
}

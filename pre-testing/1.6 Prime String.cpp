#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define pii pair < int , int >
#define LS pair < ll , string >
 
typedef unsigned long long ull;
typedef long double ldbl;
typedef long long ll;
typedef double dbl;
 
const ldbl E = 2.71828182845904523536;
const ldbl pi = acos(-1);
const dbl eps = 1e-9;
const ll m = 1000000007;
const ll N=1e5+100;
bool prime[N];
 
void seive(){
 
 for(int i=2 ; i<N ; i++) prime[i]=1;
 prime[0]=prime[1]=0;
 
 for(int i=2 ; i*i<N ; i++)
 if( prime[i] )
 for(int j=i*i ; j<N ; j+=i)
 prime[j]=0;
 
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    seive();
 
    int t,dif=0,ans=1,alpha[30]={0},sz;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>s;
        sz = s.size();
        for(int i=0; i<sz; i++)
        {
            alpha[s[i]-'a']++;
        }
//        cout<<alpha[0]<<" "<<alpha[1]<<endl;
 
 
        for(int i=0; i<26; i++)
        {
            if(alpha[i])
            {
                dif++;
                if(!prime[alpha[i]]) ans=0;
                alpha[i]=0;
            }
        }
        if(!prime[dif]) ans=0;
        dif =0;
 
        if(ans==0) cout<<"NO\n";
        else cout<<"YES\n";
        ans=1;
    }
    return 0;
}

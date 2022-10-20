#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

const ll INF = 1e17;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m;
    cin >> n >> m;
    ll a[m];
    vector<vector<ll> > anss;
    for(ll i=0; i<m; i++)
        cin >> a[i];
    for(ll i=0; i<(1<<m); i++){
        vector<ll> v;
        vector<ll> vc;
        for(ll j=0; j<m; j++){
            if(i&(1<<j))
                v.emplace_back(a[j]);
        }
        ll q = n;
        bool ns = true;
        for(auto &x : v){
            if(q%x != 0)
                ns = false;
            else{
                while(q%x == 0){
                    q /= x;
                    vc.emplace_back(x);
                }
            }
        }
        if(q == 1)
            anss.emplace_back(vc);
    }
    if(anss.size() == 0)
        cout << "-1";
    else{
        sort(begin(anss), end(anss));
        ll mn = INF;
        for(auto x : anss)
            mn = min(mn, (ll)x.size());
        for(auto x : anss){
            if(mn == (ll)x.size()){
                ll cur = 1;
                cout << cur << " ";
                for(auto y : x){
                    cout << cur*y << " ";
                    cur *= y;
                }
                return 0;
            }
        }
    }
    return 0;
}

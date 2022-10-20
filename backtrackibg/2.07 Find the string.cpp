//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> F; string R; int p, k;
bool dfs(int v, int c) {
    if (!c) return true;
    for (int d = 0; d < k; d++) {
        int vn = v%p*k + d;
        if (!F[vn]) {
            F[vn] = 1; R.push_back('0'+d);
            if (dfs(vn, c-1)) return true;
            F[vn] = 0; R.pop_back();
        }
    }
    return false;
}
string findString(int n, int k) {
    int N=(int)pow(k, n); this->k=k, p=(int)pow(k, n-1);
    F.resize(N); F[0]=1; R.assign(n, '0');
    dfs(0, N - 1);
    return R;
}
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        cin>>N>>K;
        Solution ob;
        string ans = ob.findString(N, K);
        int ok=1;
        for(auto i:ans){
            if(i<'0'||i>K-1+'0')
                ok=0;
        }
        if(!ok){
            cout<<-1<<endl;
            continue;
        }
        unordered_set<string> st;
        for(int i=0;i+N-1<ans.size();i++){
            st.insert(ans.substr(i,N));
        }
        int tot=1;
        for(int i=1;i<=N;i++)
            tot*=K;
        if(st.size()==tot)
        {
            cout<<ans.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
} 
// } Driver Code Ends

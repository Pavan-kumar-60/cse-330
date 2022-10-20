//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col, vector<bool> &leftRow, vector<bool> &upperDiagonal, vector<bool> &lowerDiagonal, vector<int> &arr, vector<vector<int>> &res) {

        if(col == leftRow.size()) {

            res.push_back(arr);

            return;

        }

        

        for(int row = 0; row < leftRow.size(); row++) {

            if(!leftRow[row] && !upperDiagonal[row+col] && !lowerDiagonal[leftRow.size()-1+col-row]) {

                leftRow[row] = upperDiagonal[row+col] = lowerDiagonal[leftRow.size()-1+col-row] = true;

                arr.push_back(row+1);

                solve(col+1, leftRow, upperDiagonal, lowerDiagonal, arr, res);

                arr.pop_back();

                leftRow[row] = upperDiagonal[row+col] = lowerDiagonal[leftRow.size()-1+col-row] = false;

            }

        }

    }

    vector<vector<int>> nQueen(int n) {

        vector<vector<int>> res;

        vector<int> arr;

        vector<bool> leftRow(n);

        vector<bool> upperDiagonal(2*n-1);

        vector<bool> lowerDiagonal(2*n-1);

        

        solve(0, leftRow, upperDiagonal, lowerDiagonal, arr, res);

        return res;

    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends

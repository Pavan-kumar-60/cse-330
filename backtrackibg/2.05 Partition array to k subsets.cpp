//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
   bool solve(int a[],int n,int k,vector<int>&part,vector<int>&subsetsum,int indx,int ssf){
     if(indx==n){
         if(ssf==k){
             bool flag=true;
             for(int i=0;i<subsetsum.size()-1;i++){
                 if(subsetsum[i]!=subsetsum[i+1]){
                     flag=false;
                     break;
                 }
             }
             if(flag){
                 return true;
             }
         }
         return false;
     }
     for(int i=0;i<k;i++){
         if(part[i]!=-1){
             subsetsum[i]+=a[indx];
             if(solve(a,n,k,part,subsetsum,indx+1,ssf))return true;
             subsetsum[i]-=a[indx];
         }
         else{
             part[i]=1;
             subsetsum[i]+=a[indx];
             if(solve(a,n,k,part,subsetsum,indx+1,ssf+1))return true;
             subsetsum[i]-=a[indx];
             part[i]=-1;
             break;
         }
     }
     return false;
 }
   bool isKPartitionPossible(int a[], int n, int k)
   {
        //Your code here
        //if(n<k)return false;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        if(sum%k!=0)return false;
        vector<int>part(k,-1);
        vector<int>subsetsum(k,0);
        if(solve(a,n,k,part,subsetsum,0,0)){
            return true;
        }
        return false;
   }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends

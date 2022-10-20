class Solution
{
	public:
		void createPermutation(string &s, string &t,vector<string> &ans,vector<bool> &freq){
	        if(s.size()==t.size()){
	            ans.emplace_back(t);
	            return;
	        }
	        
	        for(int i=0;i<s.size();i++){
	            if(!freq[i]){
	                t+=s[i];
	                freq[i]=1;
	                createPermutation(s,t,ans,freq);
	                freq[i]=0;
	                t.pop_back();
	            }
	        }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    string t="";
		    vector<bool> freq(S.size(),0);
		    createPermutation(S,t,ans,freq);
		    
		    sort(ans.begin(),ans.end());
		    for(int i=0;i<ans.size()-1;i++){
		        if(ans[i]==ans[i+1]) ans.erase(ans.begin()+i);
		    }
		    return ans;
		}
};

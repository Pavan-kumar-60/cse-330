void func(string str,int idx,string ans,vector<string> &res){
       if(idx==str.length()-1)
       {
           ans+=str[idx];
           res.push_back(ans);
           return;
       }
       func(str,idx+1,ans+str[idx],res);
       func(str,idx+1,ans+str[idx]+" ",res);
    }
    vector<string> permutation(string S){
        vector<string> res;
       func(S,0,"",res);
       sort(res.begin(),res.end());
       return res;
    }

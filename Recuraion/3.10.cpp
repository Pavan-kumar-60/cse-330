#include<iostream>
#include<vector>

using namespace std;


long long divisor(long long DI, vector<long long> S)
{
    for(long long i=0;i<S.size();i++)
    {
        if(DI%S[i]==0 && S[i]!=DI)
            return(S[i]);
    }
    return(-1);
}
long long findmem(vector<vector<long long>> mem,long long search)
{
    for(long long i=0;i<mem.size();i++)
    {
        if(mem[i][0]==search)
            return(i);
    }
        return(-1);
}

vector<long long> makevec(long long n, long long SI)
{
    long long res= n/SI;
    vector<long long> newvec(res,SI);
    return(newvec);
}

long long StoneDiv(long long n, vector<long long> S,vector<vector<long long>> &mem)
{
    if(divisor(n,S)==-1)
    {
        long long depth=0;
        return(depth);
    }
    else
    {
        long long depth=-1;
        //if(arr[n]!=-1)
        long long index=findmem(mem,n);
        if(index!=-1)
        {
            depth=mem[index][1];
            return(depth+1);
        }
        else
        {
            
            for(long long i=0;i<S.size();i++)
            {
                if(n%S[i]==0 && n!=S[i])
                {
                    long long res=n/S[i];
                   long long newDepth=res*StoneDiv(S[i],S,mem);
                   if(depth<newDepth)
                    depth=newDepth;
                }
            }
            //arr[n]=depth;
            vector<long long> newmem={n,depth};
            mem.push_back(newmem);   
        }
        return(depth+1);
    }
}
long long stoneDivision(long long n, vector<long long> S)
{
    vector<vector<long long>> mem;
   
    return(StoneDiv(n,S,mem));
}



int main()
{
   

   int nquery=0;
   cin>>nquery;
   vector<long long> result;
   for(int i=0;i<nquery;i++)
   {
       long long n=0;
       vector<long long>S;
       int vecsize=0;
       cin>>n;
       cin>>vecsize;
       for(int j=0;j<vecsize;j++)
       {
            long long temp;
            cin>>temp;
            S.push_back(temp);
       }
       long long restemp=stoneDivision(n,S);
       result.push_back(restemp);
   }
   for(int i=0;i<result.size()-1;i++)
   {
       cout<<result[i]<<endl;
   }
   cout<<result[result.size()-1];

}

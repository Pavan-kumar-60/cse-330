#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define mod 1000000007;
typedef long long ll;
int func(int n){
    int sum=0;
    while(n){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43};
int main(){
    bool num3[1000],num4[10000];
    int num5[100000];
    for(int i=0;i<1000;i++){
        num3[i]=false;
    }
    for(int i=0;i<10000;i++){
        num4[i]=false;
    }
    for(int i=0;i<100000;i++){
        num5[i]=-1;
    }
    int a=0,b=0,d=0;
    int count1=0;
    for(int i=0;i<1000;i++){
        for(int j=0;j<14;j++){
            if(func(i)==p[j]){
                num3[i]=true;
                //cout<<i<<endl;
                count1++;
                if(i>=100)
                    a++;
            }
        }
    }
    ////cout<<" count of 3 "<<count1<<endl;
    int count2=0;
    for(int i=0;i<10000;i++){
        if(num3[i%1000]&&num3[i/10]){
            for(int j=0;j<14;j++){
                if(func(i)==p[j]){
                    num4[i]=true;
                    //cout<<i<<endl;
                    count2++;
                    if(i>=1000)
                        b++;
                }
            }
        }
    }
    //cout<<"Count of 4 "<<count2<<endl;
    int count=0;
    vector<int> num;
    for(int i=0;i<100000;i++){
        if(num4[i%10000]&&num4[i/10]){
            for(int j=0;j<14;j++){
                if(func(i)==p[j]){
                    num5[i]=count;
                    //cout<<i<<endl;
                    count++;
                    num.push_back(i);
                    if(i>=10000)
                        d++;
                }
            }
        }
    }
    //cout<<"count of 5 "<<count<<endl;
    // cout<<count<<endl;
    vector<int> gr[count];
    int count3=0;
    for(int i=0;i<count;i++){
        int temp=num[i];
        temp/=10;
        for(int j=0;j<count;j++){
            if(temp==num[j]%10000){
                gr[i].push_back(j);
                //cout<<i<<" "<<j<<" "<<num[i]<< " "<<num[j]<<endl;
                count3++;
            }
        }
    }
    //cout<<count3<<endl;
    ll dp[2][count];
    for(int i=0;i<count;i++){
        
        dp[0][i]=1;
        if(num[i]<10000){
            dp[0][i]=0;
        }
    }
    ll res[400007];
    res[1]=9;
    res[2]=90;
    res[3]=a;
    res[4]=b;
    res[5]=d;
    int r=1,c=0;

    for(int i=6;i<400001;i++){
        res[i]=0;
        for(int j=0;j<count;j++){
            dp[r][j]=0;
            for(int k=0;k<gr[j].size();k++){
                dp[r][j]+=dp[c][gr[j][k]];
                
            }
            dp[r][j]%=mod;
            res[i]+=dp[r][j];
        }
        res[i]%=mod;
        r=1-r;
        c=1-c;
    }
    int q;
    scanf("%d",&q);
    for(int a0 = 0; a0 < q; a0++){
        int n;
        scanf("%d",&n);
        cout<<res[n]<<endl;
        
        //cout<<count<<endl;
        
    }
    return 0;
}


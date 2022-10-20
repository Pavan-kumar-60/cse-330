#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int m,n,c=0;
    cin>>m>>n;
    char A[500][500];
    int col[500][500]={0,0},row[500][500]={0,0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>A[i][j];
        }
    }
    for(int j=0;j<n;j++)
    {
        c=0;
        for(int i=m-1;i>=0;i--)
        {
            if(A[i][j]=='x')
            {
                c=0;
                col[i][j]=c;
            }
            else
            {
                col[i][j]=c;
                c++;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        c=0;
        for(int j=n-1;j>=0;j--)
        {
            if(A[i][j]=='x')
            {
                c=0;
                row[i][j]=c;
            }
            else
            {
                row[i][j]=c;
                c++;
            }
        }
    }
    /*for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<row[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<col[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    int ans=0;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            int k,l,lim=row[i][j],mincol;
            for(k=1;k<=lim;k++)
            {
                mincol=min(col[i][j],col[i][j+k]);
                for(l=mincol;l>=1;l--)
                {
                    if(row[i+l][j]>=k)
                        break;
                }
                if(l>0)
                    ans=max(ans,2*(l+k));
            }
        }
    }
    if(ans>0)
        cout<<ans;
    else
        cout<<"impossible";
    return 0;
}


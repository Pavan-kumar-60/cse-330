


#include<iostream>

using namespace std;

bool divisible(int n)

{

if(n==1)

return true;

if(n==2)

return false;

for(int i=2;i*i<=n;i++)

{

if(n%i==0)

return false;




}

return true;

}




int main()

{

int t;

cin>>t;

while(t--)

{

int n;

cin>>n;



if(n!=1&&divisible(n+1))

cout<<"NO"<<endl;

else

cout<<"YES"<<endl;

}

}

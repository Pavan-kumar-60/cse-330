#include <iostream>

#include <set>

#include <algorithm>

using namespace std;

const int N = 1e6+7;

int Isprime[N];

void sieve()

{

    for(int i = 0;i <= N;i++)

    {

        Isprime[i] = true;

    }

    Isprime[0] = false;

    Isprime[1] = false;


 

    for(int i = 2;i * i <= N;i++)

    {

        if(Isprime[i] == true)

        for(int j = i * i;j <= N;j += i)

        {

            if(Isprime[j] == true)

            Isprime[j] = false;

        }

    }

}

int main()

{

    sieve();

    int t;

    cin >> t;

    set<int> vec;

    while(t--)

    {

        int n;

        cin >> n;

        if(Isprime[n] == true)

        {

            //cout << n << endl;

            vec.insert(n);

        }

       

    }

   

    int cnt = 1;

    int x = 0,y = 0;

    for(auto i : vec)

    {

        if(cnt == 1)

        x = i;

        y = i;

        //cout << y << endl;

        cnt++;

    }

    if(vec.size() > 0)

    cout << y - x << endl;

    else cout << -1 << endl;

}

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void nextNumber(vector<int> &A, vector<int> &B, int &base){
    int N = B.size();
    vector<int> nB(2*N, 0);
    // Get B*B
    for(int ia=0; ia<N; ++ia){
        int carry = 0, pos = ia;
        for(int ib=0; ib<N; ++ib){
            int val = B[ia]*B[ib] + nB[pos] + carry;
            nB[pos] = val%base;
            carry = val/base;
            ++pos;
            /* while(pos+1<nB.size() && carry>0){
                carry += nB[pos+1];
                nB[pos+1] = carry%10;
                carry /= 10;
                ++pos;
            }*/
        }
        while(carry>0){
            nB[pos] = carry%base;
            carry /= base;
            ++pos;
        }
    }
    int carry = 0;
    for(int ia=0; ia<A.size(); ++ia){
        int val = A[ia] + nB[ia] + carry;
        nB[ia] = val%base;
        carry = val/base;
    }
    for(int ia=A.size(); ia<nB.size() && carry>0; ++ia){
        int val = nB[ia] + carry;
        nB[ia] = val%base;
        carry = val/base;
    }
    if(nB.back()==0)    nB.pop_back();
    
    A = B;
    B = nB;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    long long A, B;
    cin >> A >> B >> N;
    while(B < 1E9 && N-- > 2){
        long long tmp = B;
        B = B*B + A;
        A = tmp;
    }
    if(N==2){
        cout << B << endl;
    } else {
        vector<int> vA, vB;
        int base = 1E4;
        while(A>0){ vA.push_back(A%base); A=A/base; }
        while(B>0){ vB.push_back(B%base); B=B/base; }
        while(N-- > 2)  nextNumber(vA, vB, base);
        cout << vB.back();
        for(int ia=vB.size()-2; ia>=0; --ia){
            if(vB[ia]<10)   cout << "000";
            else if(vB[ia]<100) cout << "00";
            else if(vB[ia]<1000)    cout << "0";
            cout << vB[ia];
        }
        cout << endl;
    }
    
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define mm 3000000
vector<int>sont;
vector<int>sodb;
void sang() {
    bool *A=new bool [mm+5];
    for(long long i=3;i<=mm;i+=2)A[i]=true;
    sont.push_back(2);
    for(long long i=3;i*i<=mm;i+=2)
    if(A[i]==true)
        for(long long j=i*i;j<=mm;j+=i) A[j]=false;
    for(long long i=3;i<=mm;i+=2)
        if(A[i]==true)
            sont.push_back(i);
    delete []A;
}
void sanglai() {
    for (int i=0;i<sont.size();i++) {
        int temp=sont[i];
        int tong=0;
        while (temp!=0) {
            tong+=temp%10;
            temp/=10;
        }
        if (tong%5==0) {
            sodb.push_back(sont[i]);
        }
    }
}
int main() {
    ifstream inp("sprime.inp");
    ofstream out("sprime.out");
    sang();
    sanglai();
    int t;
    inp>>t;
    for (int i=0;i<t;i++) {
        int l,r;
        inp>>l>>r;
        int dem=0;
        for (int j=0;j<sodb.size();j++) {
            if (sodb[j]>=l&&sodb[j]<=r)
                dem++;
        }
        out<<dem<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
vector <unsigned long long> nt;
unsigned long long mm=1000000;
bool checknt (unsigned long long a) {
    for (unsigned long long i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
unsigned long long tim(unsigned long long n) {
    int i=0;
    while (nt[i]*nt[i+1]*nt[i+2]<=n) {
        i++;
    }
    return nt[i-1]*nt[i]*nt[i+1];
}
int main() {
    int t;
    cin>>t;
    unsigned long long n[t];
    unsigned long long mx=0;
    for (int i=0;i<t;i++) {
        cin>>n[i];
        mx=max(mx,n[i]);
    }
    unsigned long long demnt=0;
    bool a[mm];
    for (int i=2;i<mm;i++) {
        a[i]=true;
    }
    for (int i=2;i<mm;i++) {
        if (checknt(a[i])==true) {
            for (int j=i*2;j<mm;j+=i) {
                a[j]=false;
            }
        }
    }
    for (int i=2;i<mm;i++) {
        if (a[i]==true) {
            nt.push_back(i);
            demnt++;
        }
    }
    long long kq[t];
    for (int i=0;i<t;i++) {
        if (n[i]<30) {
            kq[i]=-1;
        } else {
            kq[i]=tim(n[i]);
        }

    }
    for (int i=0;i<t;i++) {
        cout<<kq[i]<<endl;
    }
}

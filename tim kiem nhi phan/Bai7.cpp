#include<bits/stdc++.h>
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
unsigned long long tim(unsigned long long n, int k) {
    unsigned long long tich=1;
    for (int i=0;i<k;i++) {
        tich*=nt[i];
    }
    int i=0;
    if (tich>n) {
        return 0;
    }
    while (tich<=n) {
        tich/=nt[i];
        tich*=nt[i+k];
        i++;
    }
    i--;
    tich/=nt[i+k];
    tich*=nt[i];
    return tich;
}
int main() {
    unsigned long long n;
    int k;
    cin>>n>>k;
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
    if (tim(n,k)==0) {
        cout<<"-1";
    } else {
        cout<<tim(n,k);
    }
}


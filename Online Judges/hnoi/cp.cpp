#include<bits/stdc++.h>
using namespace std;
bool check(int a) {
    for (int i=2;i<=sqrt(a);i++) {
        if (a%i==0)
            return false;
    }
    return true;
}
int main() {
    vector<int>nguyento;
    long long a,b;
    cin>>a>>b;
    int n=sqrt(b);
    bool nt[n+1];
    for (int i=2;i<=n;i++) {
        nt[i]=true;
    }
    for (int i=2;i<=n;i++) {
        if (check(i)==true) {
            for (int j=i*2;j<=n;j+=i) {
                nt[j]=false;
            }
        }
    }
    int demnt=0, dem=0;
    for (int i=2;i<=n;i++) {
        if (nt[i]==true) {
            nguyento.push_back(i);
            demnt++;
        }
    }
    for (int i=0;i<demnt;i++) {
        if (nguyento[i]*nguyento[i]>=a&&nguyento[i]*nguyento[i]<=b) {
            dem++;
        }
    }
    cout<<dem;
}

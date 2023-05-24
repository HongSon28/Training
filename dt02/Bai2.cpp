#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("Timuoc.inp");
    ofstream out("Timuoc.out");
    int t;
    inp>>t;
    for (int i=0;i<t;i++) {
        int n,p;
        inp>>n>>p;
        int d=0;
        for (int j=p;j<=n;j++) {
            int m=j;
            while (m%p==0) {
                d++;
                m/=p;
            }
        }
        out<<d<<endl;
    }
}

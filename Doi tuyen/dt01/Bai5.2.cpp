#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("uocso.inp");
    ofstream out("uocso.out");
    int a,b;
    inp>>a>>b;
    int s[b-a+1]={ };
    for (int i=1;i*i<=b;i++) {
        int first;
        int bp=i*i;
        if ((a/i)*i>=a) {
            first=(a/i)*i;
        } else {
            first=(a/i+1)*i;
        }
        for (int j=first;j<=b;j+=i) {
            if (j==bp) {
                s[j-a]++;
            } else if (j>bp) {
                s[j-a]+=2;
            }
        }
    }
    int mn;
    int sl=1;
    for (int i=a;i<=b;i++) {
        if (sl<s[i-a]){
            sl=s[i-a];
            mn=i;
        }
    }
    int dem=0;
    for (int i=a;i<=b;i++) {
        if (s[i-a]==sl)
            dem++;
    }
    out<<mn<<" "<<sl<<" "<<dem;
}

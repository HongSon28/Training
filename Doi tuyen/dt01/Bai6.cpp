#include<bits/stdc++.h>
using namespace std;
bool comp(int a, int b) {
    return a>b;
}
int main() {
    ifstream inp;
    ofstream out;
    inp.open("Frog.inp");
    out.open("Frog.out");
    int m,n,k;
    inp>>m>>n>>k;
    int a[m][n];
    int sl[m*n+1]={};
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            inp>>a[i][j];
            sl[a[i][j]]++;
        }
    }
    sort(sl,sl+n*m+1,comp);
    int tong=0;
    for (int i=0;i<k;i++)
        tong+=sl[i];
    out<<tong;
    inp.close();
    out.close();
}

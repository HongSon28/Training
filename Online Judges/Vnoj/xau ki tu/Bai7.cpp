#include<bits/stdc++.h>
using namespace std;
int main() {
    string s;
    getline(cin,s);
    int dem=1;
    int check[50];
    check[0]=(int)s[0];
    int n=s.length();
    for (int i=1;i<n;i++) {
        int demcheck=0;
        for (int j=0;j<dem;j++) {
            if (((int)s[i]==check[j])||((int)s[i]==check[j]+32)||((int)s[i]==check[j]-32)) {
                demcheck+=1;
            }
        }
        if (demcheck==0) {
            check[dem]=(int)s[i];
            dem+=1;
        }
    }
    for (int i=1;i<n;i++) {
        if (s[i]==' ') {
            dem-=1;
            break;
        }
    }
    cout<<dem;
}

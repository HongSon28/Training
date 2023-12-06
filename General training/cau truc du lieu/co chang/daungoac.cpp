#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    cin.ignore();
    string a;
    getline(cin,a);
    int dem=0;
    for (int i=0;i<n;i++) {
        if (a[i]=='(')
            dem++;
        else
            dem--;
        if (dem<0) {
            cout<<"NO";
            return 0;
        }
    }
    if (dem==0)
        cout<<"YES";
    else
        cout<<"NO";
}


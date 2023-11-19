#include<bits/stdc++.h>
using namespace std;
int main() {
    string a;
    getline(cin,a);
    int dem=0;
    int n=a.length();
    for (int i=1;i<=n/2;i++) {
        if (n%i==0) {
            string x=a.substr(0,i);
            string temp=x;
            int k=n/i;
            for (int j=0;j<k-1;j++) {
                x+=temp;
            }
            if (x==a) {
                dem+=1;
                cout<<temp;
                break;
            }
        }
    }
    if (dem==0) {
        cout<<a;
    }
}


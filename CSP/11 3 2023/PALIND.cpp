#include<bits/stdc++.h>
using namespace std;
int comp(string a,string b) {
    if (a==b) return 0;
    for (int i=0;i<a.size();i++) {
        if (a[i]>b[i]) return 1;
        else if (a[i]<b[i]) return -1;
    }
}
int main() {
    freopen("PALIND.INP","r",stdin);
    freopen("PALIND.OUT","w",stdout);
    string a;
    cin>>a;
    int n=a.length();
    string b=a;
    for (int i=0;i<n/2;i++) {
        int j=n-i-1;
        b[j]=b[i];
    }
    if (comp(a,b)<=0) {
        cout<<b;
    } else {
        int i,j;
        if (n%2==0) {
            i=n/2-1;
            j=n/2;
        } else {
            i=n/2;
            j=n/2;
        }
        //cout<<b<<endl;
        //cout<<i<<' '<<j<<endl;
        while (b[i]=='9') {
            b[i]='0';
            b[j]='0';
            i--;
            j++;
        }
        //cout<<i<<' '<<j<<endl;
        if (b[i]=='0') b[i]='1';
        else if (b[i]=='1') b[i]='2';
        else if (b[i]=='2') b[i]='3';
        else if (b[i]=='3') b[i]='4';
        else if (b[i]=='4') b[i]='5';
        else if (b[i]=='5') b[i]='6';
        else if (b[i]=='6') b[i]='7';
        else if (b[i]=='7') b[i]='8';
        else if (b[i]=='8') b[i]='9';
        b[j]=b[i];
        cout<<b;
    }
}

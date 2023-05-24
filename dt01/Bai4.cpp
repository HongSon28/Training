#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream inp("nenxau.inp");
    ofstream out("nenxau.out");
    string a,b;
    inp>>a>>b;
    int n=b.length();
    int i=0;
    while (i<n) {
        if (b[i]>='1'&&b[i]<='9') {
            int temp=b[i]-48;
            int start=i;
            int dem=1;
            i++;
            while (b[i]>='0'&&b[i]<='9') {
                temp*=10;
                temp+=b[i]-48;
                i++;
                dem++;
            }
            string s=b.substr(i,1);
            b.erase(start,dem);
            i-=dem;
            n-=dem;
            for (int j=0;j<temp-1;j++) {
                b.insert(start,s);
                n++;
            }
        }
        i++;
    }
    n=b.length();
    for (int j=0;j<n;j++) {
        if (b[j]>=65&&b[j]<=90)
            b[j]+=32;
    }
    n=a.length();
    for (int j=0;j<n;j++) {
        if (a[j]>=65&&a[j]<=90)
            a[j]+=32;
    }
    for (int j=0;j<n;j++) {
        int dem=1;
        while (j<n-1&&a[j]==a[j+1]) {
            dem++;
            j++;
        }
        if (dem==1) {
            out<<a[j];
        } else if (dem==2) {
            out<<a[j]<<a[j];
        } else {
            out<<dem<<a[j];
        }
    }
    out<<endl<<b;
    inp.close();
    out.close();
}

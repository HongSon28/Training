#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>b;
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
    cout<<b;
}


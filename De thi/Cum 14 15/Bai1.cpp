#include<bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    int res=0;
    cin>>a>>b;
    while (a.size()<b.size()) {
        a="0"+a;
    }
    while (a.size()>b.size()) {
        b="0"+b;
    }
    for (int i=0;i<a.size();i++) {
        int ta=(int)a[i]-48;
        int tb=(int)b[i]-48;
        res+=abs(ta-tb);
    }
    cout<<res;
}

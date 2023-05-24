#include<bits/stdc++.h>
using namespace std;
int main() {
    int h,m,a,b;
    cin>>h>>m>>a>>b;
    if (a>b) {
        int c=a-b;
        h-=c;
    } else {
        int c=b-a;
        h+=c;
    }
    if (h>=24) {
        h-=24;
    }
    cout<<h<<" "<<m;
}

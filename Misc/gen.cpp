#include<bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long h) {
    return l+rd()%(h-l+1);
}
int main() {
    long long a=rand(1,1e6),b=a;
    int t=rand(1,3);
    if (t==1) b+=a;
    else if (t==2) b*=a;
    else b-=a;
    t=rand(1,3);
    if (t==1) b+=a;
    else if (t==2) b*=a;
    else if (t==3&&b>a) b-=a;
    else b+=a;
    cout<<a<<'\n'<<b;
}

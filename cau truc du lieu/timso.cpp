#include<bits/stdc++.h>
using namespace std;
int conv(int n) {
    int res=0;
    while (n!=0) {
        res+=pow(n%10,2);
        n/=10;
    }
    return res;
}
int main() {
    ifstream inp("timso.inp");
    ofstream out("timso.out");
    int a,b;
    inp>>a>>b;
    int res=0,resx=a;
    for (int i=a;i<=b;i++) {
        int cnt[100000]={};
        int temp=i;
        cnt[temp]++;
        int dem=1;
        do {
            cnt[conv(temp)]++;
            temp=conv(temp);
            dem++;
            if (res<dem) {
                res=dem;
                resx=i;
            }
        } while (cnt[temp]<2);
    }
    out<<resx<<" "<<res<<endl<<resx<<" ";
    int cnt[1000]={};
    int temp=resx;
    cnt[temp]++;
    do {
        cnt[conv(temp)]++;
        temp=conv(temp);
        out<<temp<<" ";
    } while (cnt[temp]<2);
}


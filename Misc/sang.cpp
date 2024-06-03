#include<bits/stdc++.h>
using namespace std;
long long n,dem=0;
vector <int>nt;
void sang() {
    bool ck[100001];
    memset(ck,true,sizeof(ck));
    for (long long i=2;i*i<=n;i++) {
        if (ck[i]==true) {
            for (long long j=i*2;j*j<=n;j+=i) {
                ck[j]=false;
            }
        }
    }
    for (int i=2;i*i<=n;i++) {
        if (ck[i]==true) {
            nt.push_back(i);
            dem++;
        }
    }
}
bool check(long long m) {
    if (m<2||m>n)
        return false;
    for (int i=2;i*i<=m;i++) {
        if (m%i==0)
            return false;
    }
    return true;
}
int main() {
    cin>>n;
    sang();
    int res=0;
    for (int i=0;i<dem-1;i++) {
        for (int j=1;j<dem;j++) {
            long long temp=nt[i]*nt[i]+nt[j]*nt[j];
            if (check(temp)==true) {
                cout<<nt[i]<<" "<<nt[j]<<" "<<temp<<endl;
                res++;
            }
        }
    }
    if (res==0)
        cout<<"-1";
}

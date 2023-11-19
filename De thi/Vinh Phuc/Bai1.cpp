#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int t;
int a,b,c,d;
vector<int>prime;
bool p[N+5];
void seive() {
    memset(p,true,sizeof(p));
    for (int i=2;i<=N;i++) {
        if (p[i]) {
            prime.push_back(i);
            for (int j=i*i;j<=N;j+=i) p[j]=false;
        }
    }
}
int main() {
    seive();
    cin>>t;
    while (t--) {
        bool flag=false;
        cin>>a>>b>>c>>d;
        for (int x=a;x<=b;x++) {
            bool cnf=false;
            for (auto i:prime) {
                if (i-x>=c&&i-x<=d) {
                    cnf=true;
                    break;
                }
            }
            //cout<<x<<' '<<cnf<<endl;
            if (!cnf) {
                flag=true;
                break;
            }
        }
        if (flag) cout<<"Tam"<<'\n';
        else cout<<"Cam"<<'\n';
    }
}

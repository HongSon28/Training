#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n;
int cnt;
bool p[50];
bool used[50];
int a[50];
vector<vector<int>>v(N+5);
void rec(int k) {
    for (int i=2;i<=2*n;i++) {
        if (!used[i]&&p[i+a[k-1]]) {
            used[i]=true;
            a[k]=i;
            if (k==2*n&&p[a[2*n]+1]) {
                cnt++;
                if (cnt<=N) {
                    for (int j=1;j<=2*n;j++) v[cnt].push_back(a[j]);
                }
            } else if (k<2*n) rec(k+1);
            used[i]=false;
        }
    }
}
int main() {
    cin>>n;
    p[2]=p[3]=p[5]=p[7]=p[11]=p[13]=p[17]=p[19]=p[23]=p[29]=p[31]=p[37]=p[41]=p[43]=p[47]=true;
    a[1]=1;
    rec(2);
    cout<<cnt<<endl;
    for (int i=1;i<=min(cnt,N);i++) {
        for (auto j:v[i]) cout<<j<<' ';
        cout<<endl;
    }
}

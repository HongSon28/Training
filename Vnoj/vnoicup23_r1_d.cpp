#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,k,cnt;
string s,t;
long long a[N+5];
int cnt1[N+5][100];
int cnt2[N+5][100];
int res=0;
vector<pair<int,int>>v;
long long sum[N+5];
bool check(int i,int j) {
    for (int m=0;m<26;m++) {
//        cout<<m<<' '<<cnt1[j][m]-cnt1[i-1][m]<<' '<<cnt2[j][m]-cnt2[i-1][m]<<endl;
        if ((cnt1[j][m]-cnt1[i-1][m])!=(cnt2[j][m]-cnt2[i-1][m])) return false;
    }
    return true;
}
int main() {
    cin>>n>>k;
    cin>>s>>t;
    s=' '+s;
    t=' '+t;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        int temp1=(int)s[i];
        int temp2=(int)t[i];
        for (int j=0;j<26;j++) {
            cnt1[i][j]=cnt1[i-1][j];
            cnt2[i][j]=cnt2[i-1][j];
        }
        cnt1[i][temp1-97]++;
        cnt2[i][temp2-97]++;
    }
    int i=1;
    while (i<=n) {
        if (s[i]!=t[i]) {
            cnt++;
            int start=i;
            while (check(start,i)==false) {
                i++;
            }
            int endd=i;
            res+=sum[endd]-sum[start-1];
            v.push_back(make_pair(start,endd));
            //cout<<start<<' '<<endd<<endl;
        }
        i++;
    }
    priority_queue<int,vector<int>,greater<int>>q;
    for (int i=0;i<v.size()-1;i++) {
        int f=v[i].second+1,s=v[i+1].first-1;
        if (f<=s) q.push(sum[s]-sum[f-1]);
    }
    while (cnt>k) {
        res+=q.top();
        q.pop();
        cnt--;
    }
    cout<<res;
}

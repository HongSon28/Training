#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
string x,s,t1,t2,y,ss;
int res,n,l1,r1,l2,r2,l3,r3,mx;
int dp[N+5][N+5];
bool check(char x,char y) {
    return ((x=='A'&&y=='a')||(x=='a'&&y=='A')||(x=='B'&&y=='b')||(x=='b'&&y=='B'));
}
void del(string &x) {
    string ans;
    for (auto i:x) {
        ans+=i;
        while (ans.size()>=2&&check(ans[ans.size()-2],ans.back())) {
            ans.pop_back();
            ans.pop_back();
        }
    }
    x=ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>s;
    del(x);
    ss=s;
    del(ss);
    if (ss==x) {
        cout<<s;
        return 0;
    }
    for (int i=0;i<(int)x.size();i++) {
        for (int j=0;j<(int)ss.size();j++) {
            if (x[i]==ss[j]) {
                if (i==0||j==0) dp[i][j]=1;
                else dp[i][j]=dp[i-1][j-1]+1;
            }
            else dp[i][j]=0;
            if (dp[i][j]>mx) {
                r1=i;
                r2=j;
                mx=dp[i][j];
            }
        }
    }
    //cout<<r1<<' '<<r2<<' '<<mx<<endl;
    l1=r1-mx+1;
    l2=r2-mx+1;
    //cout<<x<<' '<<s<<' '<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
    int l=l2-1;
    while (l>=0) {
        if (ss[l]=='a') t1+='A';
        else if (ss[l]=='A') t1+='a';
        else if (ss[l]=='b') t1+='B';
        else t1+='b';
        l--;
    }
    int r=r2+1;
    while (r<(int)ss.size()) {
        if (ss[r]=='a') t2+='A';
        else if (ss[r]=='A') t2+='a';
        else if (ss[r]=='b') t2+='B';
        else t2+='b';
        r++;
    }
    reverse(t2.begin(),t2.end());
    y=t1+s+t2;
    //cout<<t1<<' '<<s<<' '<<t2<<endl;
    if (l1!=0) y=x.substr(0,l1)+y;
    if (r1<(int)x.size()-1) y+=x.substr(r1+1,x.size()-1-r1);
    cout<<y;
}

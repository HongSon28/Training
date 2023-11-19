#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
string x,s,t1,t2,y;
vector<pair<char,int>>ss;
int res,n,l1,r1,l2,r2,mx;
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
void del2(){
    for (int i=0;i<(int)s.size();i++) {
        ss.push_back({s[i],i});
        while (ss.size()>=2&&check(ss[ss.size()-2].first,ss.back().first)) {
            ss.pop_back();
            ss.pop_back();
        }
    }
}
int main() {
    freopen("subword.inp","r",stdin);
    freopen("subword.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>x>>s;
    del(x);
    del2();
    for (int i=0;i<(int)x.size();i++) {
        for (int j=0;j<(int)ss.size();j++) {
            if (x[i]==ss[j].first) {
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
    l2=ss[l2].second;
    r2=ss[r2].second;
    //cout<<x<<' '<<s<<' '<<l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
    int l=l2-1;
    while (l>=0) {
        if (l>=1&&check(s[l-1],s[l])) {
            l-=2;
        } else {
            if (s[l]=='a') t1+='A';
            else if (s[l]=='A') t1+='a';
            else if (s[l]=='b') t1+='B';
            else t1+='b';
            l--;
        }
    }
    int r=r2+1;
    while (r<(int)s.size()) {
        if (r+1<(int)s.size()&&check(s[r],s[r+1])) {
            r+=2;
        } else {
            if (s[r]=='a') t2+='A';
            else if (s[r]=='A') t2+='a';
            else if (s[r]=='b') t2+='B';
            else t2+='b';
            r++;
        }
    }
    reverse(t2.begin(),t2.end());
    y=t1+s+t2;
    //cout<<t1<<' '<<s<<' '<<t2<<endl;
    if (l1!=0) y=x.substr(0,l1)+y;
    if (r1<(int)x.size()-1) y+=x.substr(r1+1,x.size()-1-r1);
    cout<<y;
}


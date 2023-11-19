#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
string l,r;
double res;
double dp[N+5][2][2];
int last0=-1,n;
double f(int pos,bool t1,bool t2) {
    double ans=-1;
    if (dp[pos][t1][t2]!=-1) return dp[pos][t1][t2];
    if (pos>=n) return 0;
    int lw,up;
    if (t1) lw=0;
    else lw=l[pos]-'0';
    if (t2) up=9;
    else up=r[pos]-'0';
    for (int i=lw;i<=up;i++) {
        bool b1=!(!t1&&(i==lw));
        bool b2=!(!t2&&(i==up));
        double t=f(pos+1,b1,b2);
        if (i==0&&pos<=last0) ans=max(ans,t);
        else ans=max(ans,t+log10(i));
    }
    dp[pos][t1][t2]=ans;
    //cout<<pos<<' '<<t1<<' '<<t2<<' '<<lw<<' '<<up<<' '<<ans<<endl;
    return ans;
}
int comp (string a, string b) {
    if (a.length()>b.length())
        return 1;
    if (a.length()<b.length())
        return -1;
    for (int i=0;i<a.length();i++) {
        if (a[i]>b[i]) {
            return 1;
        } else if (a[i]<b[i]) {
            return -1;
        }
    }
    return 0;
}
string operator + (string a, string b) {
    string res;
    while (a.length()>b.length())
        b='0'+b;
    while (a.length()<b.length())
        a='0'+a;
    int rem=0;
    for (int i=a.length()-1;i>=0;i--) {
        int t=(a[i]-48)+(b[i]-48)+rem;
        rem=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if (rem!=0) {
        res=char(rem+48)+res;
    }
    return res;
}
string operator * (string a, string b) {
    int mul=0;
    string c;
    int rem=0;
    for (int i=b.length()-1;i>=0;i--) {
        string res;
        for (int j=a.length()-1;j>=0;j--) {
            int t=(b[i]-48)*(a[j]-48)+rem;
            rem=t/10;
            t=t%10;
            res=char(t+48)+res;
        }
        for (int i=0;i<mul;i++)
            res.push_back('0');
        mul++;
        c=c+res;
    }
    if (rem!=0) {
        c=char(rem+48)+c;
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("COMNUM.INP","r",stdin);
    freopen("COMNUM.OUT","w",stdout);
    for (int i=0;i<=N;i++)
        for (int j=0;j<=1;j++)
            for (int k=0;k<=1;k++)
                dp[i][j][k]=-1;
    cin>>l>>r;
    int t=r.size()-l.size();
    for (int i=0;i<t;i++) {
        l='0'+l;
        last0=i;
    }
    n=l.size();
    double res=f(0,0,0);
    cout.precision(0);
    cout<<fixed<<pow(10,res);
//    cout<<res<<endl;
//    long long temp=(long long)res;
//    string ans="1";
//    for (long long i=1;i<=temp;i++) ans=ans*"10";
//    res-=temp;
//    temp=pow(10,res);
//    cout<<ans<<' '<<res<<' '<<temp<<endl;
//    ans=ans*to_string(temp);
//    cout<<ans;
}

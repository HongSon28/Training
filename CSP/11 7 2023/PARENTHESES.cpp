#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t;
string s;
int sm[N+5],minl[N+5],minr[N+5];
int main() {
    freopen("PARENTHESES.INP","r",stdin);
    freopen("PARENTHESES.OUT","w",stdout);
    cin>>t;
    while (t--) {
        cin>>s;
        s=' '+s;
        int len=s.size()-1;
        minl[0]=INT_MAX,minr[len+1]=INT_MAX;
        for (int i=1;i<=len;i++) {
            if (s[i]=='(') sm[i]=sm[i-1]+1;
            else sm[i]=sm[i-1]-1;
            minl[i]=min(minl[i-1],sm[i]);
        }
        for (int i=len;i>=1;i--) {
            minr[i]=min(minr[i+1],sm[i]);
        }
        if (sm[len]==2) {
            for (int i=1;i<=len;i++) {
                if (s[i]==')') continue;
                if (minl[i-1]>=0&&minr[i]>=2) cout<<i-1<<' ';
            }
        } else {
            for (int i=1;i<=len;i++) {
                if (s[i]=='(') continue;
                if (minl[i-1]>=0&&minr[i]>=-2) cout<<i-1<<' ';
            }
        }
        cout<<endl;
    }
}

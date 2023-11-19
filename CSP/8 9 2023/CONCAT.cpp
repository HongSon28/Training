#include<bits/stdc++.h>
using namespace std;
const int N=900;
string s[N+5];
map<string,int>mp;
int n;
int main() {
    freopen("CONCAT.INP","r",stdin);
    //freopen("CONCAT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>s[i];
        mp[s[i]]++;
    }
    for (int i=1;i<=n;i++) {
        for (int j=i+1;j<=n;j++) {
            string s1=s[i],s2=s[j];
            mp[s1]--;
            mp[s2]--;
            int len=s1.size()+s2.size();
            string t=' '+s1+s2;
            for (int k=len/2+1;k<=len;k++) {
                string x=t.substr(1,k-1);
                reverse(x.begin(),x.end());
                string y=t.substr(k+1,len-k);
                if (x.substr(0,y.size())!=y) continue;
                x.erase(0,y.size());
                if (mp[x]!=0) {
                    cout<<s1<<' '<<s2<<' '<<x;
                    return 0;
                }
            }
            mp[s1]++;
            mp[s2]++;

            swap(s1,s2);
            mp[s1]--;
            mp[s2]--;
            t=' '+s1+s2;
            for (int k=len/2+1;k<=len;k++) {
                string x=t.substr(1,k-1);
                reverse(x.begin(),x.end());
                string y=t.substr(k+1,len-k);
                if (x.substr(0,y.size())!=y) continue;
                x.erase(0,y.size());
                if (mp[x]!=0) {
                    cout<<s1<<' '<<s2<<' '<<x;
                    return 0;
                }
            }
            mp[s1]++;
            mp[s2]++;

            s1=s[i],s2=s[j];
            mp[s1]--;
            mp[s2]--;
            t=s1+s2;
            for (int k=1;k<len;k++) {
                string x=t.substr(1,k);
                string y=t.substr(k+1,len-k);
                reverse(x.begin(),x.end());
                if (y.substr(0,x.size())!=x) continue;
                y.erase(0,x.size());
                reverse(y.begin(),y.end());
                if (mp[y]!=0) {
                    cout<<y<<' '<<s1<<' '<<s2;
                    return 0;
                }
            }
            mp[s1]++;
            mp[s2]++;

            swap(s1,s2);
            mp[s1]--;
            mp[s2]--;
            t=s1+s2;
            for (int k=1;k<len;k++) {
                string x=t.substr(1,k);
                string y=t.substr(k+1,len-k);
                reverse(x.begin(),x.end());
                if (y.substr(0,x.size())!=x) continue;
                y.erase(0,x.size());
                reverse(y.begin(),y.end());
                if (mp[y]!=0) {
                    cout<<y<<' '<<s1<<' '<<s2;
                    return 0;
                }
            }
            mp[s1]++;
            mp[s2]++;
        }
    }
    cout<<-1;
}

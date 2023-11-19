#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool check (int l1,int r1,int l2,int r2){
    if (r1-l1<r2-l2) {
        int i=1,j=l2,cnt=0;
        while (i<=r1&j<=r2) {
            if (s[i]==s[j]) {
                i++;
                j++;
            } else {
                if (s[i]==s[j+1]&&cnt==0) {
                    cnt=1;
                    i++;
                    j+=2;
                }  else return false;
            }
        }
    } else {
        int i=1,j=l2,cnt=0;
        while (i<=r1&j<=r2) {
            if (s[i]==s[j]) {
                i++;
                j++;
            } else {
                if (s[i+1]==s[j]&&cnt==0) {
                    cnt=1;
                    i+=2;
                    j++;
                }  else return false;
            }
        }
    }
    return true;
}
int main() {
    cin>>s;
    n=s.size();
    if (n%2==0) {
        cout<<"NOT POSSIBLE";
        return 0;
    }
    s=' '+s;
    bool check1=check(1,n/2,n/2+1,n);
    bool check2=check(1,n/2+1,n/2+2,n);
    if (check1&&check2&&s.substr(1,n/2)!=s.substr(n/2+2,n/2)) cout<<"NOT UNIQUE";
    else if (!check1&&!check2) cout<<"NOT POSSIBLE";
    else if (check1) cout<<s.substr(1,n/2);
    else cout<<s.substr(n/2+2,n/2);
}

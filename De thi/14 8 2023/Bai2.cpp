#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long res;
int cnt1,cnt2,cnt3,cnt4;
int main() {
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>s;
    n=s.size();
    s=' '+s;
    int l=1,r=1;
    if (s[r]>='a'&&s[r]<='z') cnt1++;
    else if (s[r]>='A'&&s[r]<='Z') cnt2++;
    else if (s[r]>='0'&&s[r]<='9') cnt3++;
    else cnt4++;
    while (l<=n&&r<=n) {
        if (r-l+1<8) {
            r++;
            if (s[r]>='a'&&s[r]<='z') cnt1++;
            else if (s[r]>='A'&&s[r]<='Z') cnt2++;
            else if (s[r]>='0'&&s[r]<='9') cnt3++;
            else cnt4++;
            continue;
        }
        if (cnt1==0||cnt2==0||cnt3==0||cnt4==0) {
            r++;
            if (s[r]>='a'&&s[r]<='z') cnt1++;
            else if (s[r]>='A'&&s[r]<='Z') cnt2++;
            else if (s[r]>='0'&&s[r]<='9') cnt3++;
            else cnt4++;
            continue;
        }
        res+=n-r+1;
        if (s[l]>='a'&&s[l]<='z') cnt1--;
        else if (s[l]>='A'&&s[l]<='Z') cnt2--;
        else if (s[l]>='0'&&s[l]<='9') cnt3--;
        else cnt4--;
        l++;
    }
    cout<<res;
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    int L=0,R=0,U=0,D=0,res=0,left=0;
    int n;
    string s;
    cin>>n>>s;
    for (auto i:s) {
        if (i=='L') L++;
        else if(i=='R') R++;
        else if (i=='U') U++;
        else if (i=='D') D++;
    }
    if (L!=R) {
        int dif=abs(L-R);
        if (dif%2==0) {
            res+=dif/2;
        } else {
            res+=dif/2;
            left++;
        }
    }
    if (U!=D) {
        int dif=abs(U-D);
        if (dif%2==0) res+=dif/2;
        else {
            res+=dif/2;
            left++;
        }
    }
    if (left==1) cout<<-1;
    else if (left==0) cout<<res;
    else cout<<res+1;
}

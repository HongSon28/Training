#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,z[N+5];
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	cin>>s;
    n=s.size();
    int l=0,r=0;
    z[0]=0;
    cout<<n<<' ';
    for (int i=1;i<n;i++) {
        z[i]=0;
        if (i<r) z[i]=min(r-i,z[i-l]);
        while (i+z[i]<n&&s[z[i]]==s[i+z[i]]) z[i]++;
        if (i+z[i]>r) {
            l=i;
            r=i+z[i];
        }
        cout<<z[i]<<' ';
    }
}

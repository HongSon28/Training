#include<bits/stdc++.h>
using namespace std;
int n;
int main() {
    cin>>n;
    int t=n,sum=0;
    while (t>0) {
        sum+=t%10;
        t/=10;
    }
    sum=(10-sum%10)%10;
    cout<<n<<sum;
}

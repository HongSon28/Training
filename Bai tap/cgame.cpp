#include<bits/stdc++.h>
#define ll long long
using namespace std;
deque<ll>dq;
ll a,b;
int n;
int main() {
    cin>>n;
    for (int i=1;i<=n;i++) {
        ll temp;
        cin>>temp;
        dq.push_back(temp);
    }
    for (int i=1;i<=n;i++) {
        if (i%2==1) {
            if (dq.front()>dq.back()) {
                a+=dq.front();
                dq.pop_front();
            } else {
                a+=dq.back();
                dq.pop_back();
            }
        } else {
            if (dq.front()>dq.back()) {
                b+=dq.front();
                dq.pop_front();
            } else {
                b+=dq.back();
                dq.pop_back();
            }
        }
    }
    cout<<a<<' '<<b;
}

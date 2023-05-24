#include<bits/stdc++.h>
using namespace std;
struct human{
    long long height, behind, same;
};
long long n,temp;
stack<human>s;
long long res=0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>temp;
        if (s.empty()==true) {
            s.push({temp,0,0});
        } else if (s.empty()==false&&temp<s.top().height) {
            s.push({temp,1,0});
            res++;
        } else if (s.empty()==false&&temp==s.top().height) {
            res++;
            res+=s.top().same;
            if (s.top().behind==1) {
                res++;
            }
            s.push({temp,s.top().behind,s.top().same+1});
        } else {
            while (s.top().height<temp) {
                res++;
                s.pop();
                if (s.empty()==true) break;
            }
            if (s.empty()==false&&temp<s.top().height) {
                res++;
                s.push({temp,1,0});
            } else if (s.empty()==false&&temp==s.top().height) {
                res++;
                res+=s.top().same;
                if (s.top().behind==1) {
                    res++;
                }
                s.push({temp,s.top().behind,s.top().same+1});
            } else {
                s.push({temp,0,0});
            }
        }
    }
    cout<<res;
}

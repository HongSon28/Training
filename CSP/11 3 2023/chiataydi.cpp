#include <bits/stdc++.h>
using namespace std;
long long res;
long long calc(deque<long long>dq) {
    int i=0;
    long long sum=0;
    while (dq.empty()==false) {
        sum+=dq.back()*pow(2,i);
        dq.pop_back();
        i++;
    }
    return sum;
}
int main(){
    long long n;
    cin>>n;
    stack<long long>s;
    while(n>0){
        long long a=n%2;
        s.push(a);
        n/=2;
    }
    deque<long long>dq;
    while(!s.empty()){
        cout<<s.top();
        dq.push_back(s.top());
        s.pop();
    }
    cout<<'\n';
    for (int i=0;i<dq.size();i++) {
        res=max(res,calc(dq));
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<res;
}

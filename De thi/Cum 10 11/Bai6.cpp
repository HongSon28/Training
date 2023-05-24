#include<bits/stdc++.h>
using namespace std;
int main() {
    stack<double>num;
    stack<char>s;
    double n;
    char c;
    cin>>n>>c;
    num.push(n);
    s.push(c);
    string st;
    int i=0;
    while (cin>>st) {
        if (i%2==0) {
            n=stoi(st);
            if (s.top()=='*') {
                double t=num.top();
                s.pop();
                num.pop();
                n*=t;
                num.push(n);
            } else if (s.top()=='/') {
                double t=num.top();
                s.pop();
                num.pop();
                n=t/n;
                num.push(n);
            } else {
                num.push(n);
            }
        } else {
            c=st[0];
            s.push(c);
        }
        i++;
    }
    double res=0;
    while (!s.empty()) {
        if (s.top()=='-') {
            double t=num.top();
            num.pop();
            res-=t;
            s.pop();
        } else {
            double t=num.top();
            num.pop();
            res+=t;
            s.pop();
        }
    }
    res+=num.top();
    cout.precision(3);
    cout<<fixed<<res;
}

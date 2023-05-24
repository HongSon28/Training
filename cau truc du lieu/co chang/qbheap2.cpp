#include <bits/stdc++.h>
using namespace std;
priority_queue<int> st;
char c;
int x;

int main() {
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);

	while (cin>>c) {
		if (c == '+') {
			cin>>x;
            st.push(x);
		} else {
			if (!st.empty()) {
				int x = st.top();
				while (!st.empty() && st.top() == x) st.pop();
			}
		}
	}
    cout<<st.size()<<endl;
	while (!st.empty()) cout<<st.top()<<' ', st.pop();
}

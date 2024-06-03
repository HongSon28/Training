#include<bits/stdc++.h>

using namespace std;

bool checknt(int n){
	if (n<2)
        return false;
	for (int i=2; i<=sqrt(n); i++)
        if (n%i==0)
            return false;
	return true;
}
int main(){
    queue<int> q;
    int a, n;
    cin>>a>>n;
    for (int i = 2; i <= n, i < 10; i++){
        if (checknt(i)==true){
            q.push(i);
        }
    }
    while (q.empty()==false){
        for (int i = 1; i <= 9; i++){
            int k = q.front()*10 + i;
            if ( k <= n && checknt(k)){
                q.push(q.front()*10 + i);
            }
        }
        if (q.front()<a) {
            q.pop();
        } else {
            cout << q.front() << " ";
            q.pop();
        }
    }
    return 0;
}

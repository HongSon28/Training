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
int cd(int n) {
    int cnt=0;
    while (n!=0) {
        cnt++;
        n/=10;
    }
    return cnt;
}
int main(){
    int t;
    cin>>t;
    while (t--) {
        int k,cnt=0;
        cin>>k;
        int a=pow(10,k);
        queue<int> q;
        for (int i = 2; i < 10; i++){
            if (checknt(i)==true){
                q.push(i);
            }
        }
        while (q.empty()==false){
            for (int i = 1; i <= 9; i++){
                int temp = q.front()*10 + i;
                if ( temp < a && checknt(temp)){
                    q.push(temp);
                }
            }
            if (cd(q.front())==k) cnt++;
            q.pop();
        }
        cout<<cnt<<endl;
    }
}


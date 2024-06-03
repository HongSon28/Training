/*By https://duongdinh24.com*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Hàm tìm min
int min(int a, int b, int c){
    if(a<=b && a<=c)
        return a;
    else if(b < a && b<=c)
        return b;
    else
        return c;
}

// Hàm đếm số bước chuyển đổi xâu
void changeString(string a, string b){
    int step;  // Biến lưu số bước
    int n = a.size();  // Độ dài xâu a
    int m = b.size();  // Độ dài xâu b
    int L[n+1][m+1];   // Mảng kết quả
// thêm 1 bởi vì có 1 hàng và 1 cột cho L[0][j], L[i][0]

    // j =0, L[i][0] = i;
    for(int i=0; i<=n; i++)
        L[i][0] = i;
    // i = 0; L[0][j] = j;
    for(int j=0; j<=m; j++){
        L[0][j] = j;
    }

// Duyệt mảng kết quả: hàng trước, cột sau. Hàng xâu A, cột xâu B
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i-1] == b[j-1]) // nếu bằng nhau
                L[i][j] = L[i-1][j-1];
            else{ // nếu khác nhau
                 // min của 3 trường hợp
                L[i][j] = min(L[i-1][j], L[i-1][j-1], L[i][j-1] ) + 1;
            }
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=m;j++) {
            cout<<L[i][j]<<' ';
        }
        cout<<endl;
    }
    step = L[n][m];  // gán kết quả
    cout<<"\nSo buoc: "<<step<<"\n";  // in ra màn hình
// Truy vết
    int i = n;
    int j = m;
    while(i >=0 && j >=0){  // Nếu còn chưa qua vị trí cuối cùng
        if(a[i-1] == b[j-1]){  // Bằng nhau tức k có phép biến đổi
            i--;
            j--;
        }
        else{
            // Trường hợp xóa kí tự
            if( L[i-1][j] <= L[i-1][j-1] &&  L[i-1][j] <= L[i][j-1]){
                cout<<"Xoa "<<a[i-1]<<"\n";
                i--;
            }
            // Trường hợp sửa kí tự
            else if( L[i-1][j-1] < L[i-1][j] && L[i-1][j-1] <= L[i][j-1]){
                cout<<"Thay "<<a[i-1]<<" => "<<b[j-1]<<"\n";
                i--;
                j--;
            }
            // Trường hợp chèn kí tự
            else{
                cout<<"Chen "<<b[j-1]<<" sau "<<a[i-1]<<"\n";
                j--;
            }

        }
    }
}

int main(){
    string a, b;
        // Nhập hai xâu từ bàn phím
    cout<<"Nhap xau a: "; cin>>a;
    cout<<"Nhap xau b: "; cin>>b;
        // Gọi hàm xử lý
    changeString(a,b);
    return 0;
}

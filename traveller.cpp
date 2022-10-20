/*Một người du lịch muốn đi
tham quan 𝑁 thành phố 𝑇1
, 𝑇2, . . . , 𝑇𝑁. Xuất phát tại một
thành phố nào đó, người du lịch muốn qua tất cả các
thành phố còn lại mỗi thành phố đúng một lần rồi trở lại
thành phố ban đầu. Biết 𝑐𝑖𝑗 là chi phí đi lại từ thành phố
𝑇𝑖 đến thành phố 𝑇𝑗
. Hãy tìm một hành trình cho người
đi du lịch có tổng chi phí là nhỏ nhất.*/
/*
coi người đó xuất phát ở thành phố 1, sau đó duyệt toàn bộ hoán vị từ 2->n
vì 1 2 3 4 5 6 bằng 6 5 4 3 2 1 nên chỉ xét 1 cái.
nhập vào ma trận n*n là Cij ma trân chi phí từ i->j
tìm optimize option */
#include<bits/stdc++.h>
int N;//N thành phố
int C[100][100];//ma trận giá trị
int arr[100];//các trường hợp
int arropt[100];//trường hợp tối ưu
int valueOptimize;//giá trị của trường hợp tối ưu
bool unused[100];//kiểm tra phần tử từng cấu hình
//----------------------------------------------------
void init() {//khoi tao
    std::cin>>N;
    arropt[1]=1;
    arr[1]=1;
    valueOptimize=INT_MAX;
    for(int i=1;i<=N;++i) {
        for(int j=1;j<=N;++j) {
            std::cin>>C[i][j];
        }
    }
    for(int i=2;i<=N;++i) {
        unused[i]=true;
    }
}
void display() {//in ra kq cuoi
    for(int i=1;i<=N;++i) {
        std::cout<<arropt[i];
    }
        std::cout<<std::endl<<valueOptimize+C[arropt[N]][arropt[1]];
}
void update(int tempOptimize) {//cap nhat phuong an toi uu
    valueOptimize=tempOptimize;
    for(int i=2;i<=N;++i) {
    arropt[i]=arr[i];
    }
}
int totalCost(int sum) {//tinh tong thiet hai
    for(int i=1;i<N;++i) {
        sum+=C[arr[i]][arr[i+1]];
    }
    return sum;
}
void Try(int i) {//in tung cau hinh
    for(int j=2;j<=N;++j) { 
        if(unused[j]) {
            arr[i]=j;
            unused[j]=false;
            if(i==N) {
                int sum=0;
                sum=totalCost(sum);
                if(sum<valueOptimize) {
                    update(sum);
                }
            }
            else{
                Try(i+1);
            }
            unused[j]=true;
        }
    }
}
int main() {
    init();
    Try(2);
    display();
}
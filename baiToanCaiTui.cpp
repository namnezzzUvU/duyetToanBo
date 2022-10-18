/*Một nhà thám hiểm cần đem theo một
cái túi trọng lượng không quá 𝐵. Có 𝑁 đồ vật cần đem
theo. Đồ vật thứ 𝑖 có trọng lượng 𝑎𝑖
, có giá trị sử dụng 𝑐𝑖
(𝑖 = 1, 2, . . . , 𝑁; 𝑎𝑖
, 𝑐𝑖 ∈ 𝑍). Hãy tìm cách đưa đồ vật
vào túi cho nhà thám hiểm sao cho tổng giá trị sử dụng
các đồ vật trong túi là lớn nhất.
*/
 /*
 mỗi cách chọn là 1 phương án, cách chọn phù hợp là phương án tối ưu
 phù hợp với HÀM MỤC TIÊU của bài toán.
 ta in ra 1 chuỗi nhị phân độ dài n, 0 là 0 cho vào túi, 1 là cho vào túi.
 */
#include<bits/stdc++.h>
double B,N,c[1000],a[1000],arr[1000],arrOpt[1000],popt;
void init() {
    std::cin>>N>>B;
    for(int i=1;i<=N;++i) {
        std::cin>>a[i]>>c[i];
    }
    popt=INT_MIN;
}
int totalUseValue(int sum) {//ham tinh tonng gia tri su dung
    for(int i=1;i<=N;++i) {
    sum+=(c[i]*arr[i]);
    }
    return sum;
}
int totalWeight(int sum) {//ham tinh tong trong luong
    for(int i=1;i<=N;++i) {
    sum+=(a[i]*arr[i]);
    }
    return sum;
}
void update(int sum) {//ham cap nhat
     for(int i=1;i<=N;++i) {
        arrOpt[i]=arr[i];
     }
     popt=sum;
}
void Try(int i) {//kiem tra tung cau hinh
    for(int j=0;j<=1;++j) {
        arr[i]=j;
        if(i<N) Try(i+1);
        else{
            int sum=0,SUM=0;
            int useValue=totalUseValue(sum);
            int weight=totalWeight(SUM);
            if(weight<B) {
                if(useValue>popt) {
                    update(useValue);
                }
            }
        }
    }
}
void display() {
     for(int i=1;i<=N;++i) {
        std::cout<<arrOpt[i];
     }
     std::cout<<std::endl<<popt;
     std::cout<<std::endl;
}
int main() {
    init();
    Try(1);
    display();
}
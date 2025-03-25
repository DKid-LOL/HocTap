/*BT1: Viet chuong trinh:
Khai bao bien con tro ptr, bien x ,y ,z.
Xuat ra man hinh value va diachi cua tat ca cac bien tren.
Thay doi gia tri cua bien x y z thong qua con tro ptr.
Xuat ra gia tri cua con tro ptr trong tung truong hop khi thay doi gia tri cua bien x,y,z.
BT2: 
con tro la gi? , ung dung cua con tro ?
BT3:
Cau 1: Tao 1 struct Nhan vien cac thuoc tinh: Ten ,Msnv,ChucVu,Lương,SoThich,namsinh.
Lưu y: Dùng cấp phát động và truy cập các phân tử thông qua con trỏ., 
Cau 2: Iput data:
        Nhập số lượng phần từ kiểu dữ liệu Nhan vien theo yêu cầu của người dùng.
    Yêu câu: MSNV phải khác nhau,Năm sinh phải trên 18 tuổi va dưới 50 so với năm 2022.
Câu 3: "Sort"
    sắp xếp mảng theo Lương.Xuất ra man hình value mảng.
 Câu 4:  In ra số nhân viên có cùng sở thich.
Câu 5: Tìm người có tuổi từ 20 đên 30 tuổi.

Câu 6: Thêm 2 phần từ vào vị trí bất kỳ. Vị trí do người dùng nhập vào xuất ra value mảng.*/
//bai1:
#include<stdio.h>

int main(){
    int x = 2;
    int y = 4;
    int z = 6;
    int *ptr = NULL;
    printf("value cua bien x = %d" , x);
    printf("\naddress cua bien x = %d" , &x);
    printf("\nvalue cua bien y = %d" , y);
    printf("\naddress cua bien y = %d" , &y);
    printf("\nvalue cua bien z = %d" , z);
    printf("\naddress cua bien z : %d" , &z);
    printf("\nvalue cua ptr : %d" , ptr);
    printf("\naddress cua ptr : %d" , &ptr);
    ptr = &x;
    *ptr = 1;
    printf("\nvalue cua bien ptr : %d " , *ptr);
    printf("\naddress cua bien ptr : %d" , ptr);
    ptr = &y;
    *ptr = 3;
    printf("\nvalue cua bien ptr : %d " , *ptr);
    printf("\naddress cua bien ptr : %d" , ptr);
    ptr = &z;
    *ptr = 5;
    printf("\nvalue cua bien ptr : %d " , *ptr);
    printf("\naddress cua bien ptr : %d" , ptr);
//bai2 : 
/*Một "con trỏ" (hay "pointer" trong tiếng Anh) là một khái niệm quan trọng trong lập trình máy tính, thường được sử dụng trong các ngôn ngữ lập trình như C, C++, và một số ngôn ngữ khác. Con trỏ là một biến đặc biệt chứa địa chỉ bộ nhớ của một biến khác trong máy tính.

Dưới đây là một số khái niệm quan trọng liên quan đến con trỏ:

Địa chỉ bộ nhớ: Con trỏ lưu trữ địa chỉ bộ nhớ của một biến khác. Đây là con số duy nhất xác định vị trí của biến trong bộ nhớ.

Khai báo con trỏ: Để khai báo một con trỏ trong C/C++, bạn sử dụng dấu "*".
 Ví dụ:

int *ptr; // Khai báo một con trỏ kiểu int
Gán giá trị cho con trỏ: Bạn có thể gán địa chỉ của một biến cho một con trỏ bằng cách sử dụng toán tử "&".
 Ví dụ:

int x = 10;
int *ptr = &x; // Gán địa chỉ của biến x cho con trỏ ptr
Sử dụng con trỏ: Con trỏ có thể được sử dụng để truy cập và thay đổi giá trị của biến mà nó trỏ đến.
 Ví dụ:

*ptr = 20; // Thay đổi giá trị của biến x từ 10 thành 20
Ứng dụng của con trỏ: Con trỏ có nhiều ứng dụng quan trọng trong lập trình, bao gồm:

Quản lý bộ nhớ động: Con trỏ cho phép bạn cấp phát và giải phóng bộ nhớ động, giúp quản lý tài nguyên bộ nhớ hiệu quả hơn.

Truy cập cấu trúc dữ liệu phức tạp: Con trỏ giúp bạn truy cập và thao tác dữ liệu trong cấu trúc dữ liệu phức tạp như mảng động và danh sách liên kết.

Truyền tham số cho hàm: Con trỏ có thể được sử dụng để truyền tham số vào hàm mà cần thay đổi giá trị của tham số đó.

Tối ưu hóa hiệu suất: Con trỏ có thể giúp bạn tối ưu hóa hiệu suất chương trình bằng cách tránh sao chép dữ liệu một cách không cần thiết.*/
return 0;
}
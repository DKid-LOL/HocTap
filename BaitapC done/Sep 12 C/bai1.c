/*Bài 1: Viết chương trình khai báo mảng int có số lượng phần từ do người dùng nhập vào.
(y/c vlaue nhập từ bàn phím.)
a. xuất ra giá trị vừa nhập.
b. xuất ra địa chỉ các phần tử.
c. xuất ra kích thước các phần tử.
d.Tìm max min trong mảng.
e.xuất ra giá trị phần tử thứ 5(nếu có).
f.Tính tổng giá trị trung bình và xuất ra màn hình.
g.Thay thế giá trị thứ 2 do người dùng nhập vào.
Xuất ra giá trị các ptu.*/

#include<stdio.h>
#include<string.h>

int arr[1000];
void main(){
    int n,i;
    do{
        printf("\n Input element arr n: ");
        scanf("%d",&n);
    }while(n<0);
   
    for(i=0;i<n;i++){
        printf("\n input value arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    //a.xuat ra gia tri vua nhap:
    printf("\n\n\t\t VALUE ELEMENT ARR : ");
    for(i=0;i<n;i++){
        printf("\n Value element arr[%d] = %d .",i,arr[i]);
    }
    //b. xuat ra dia chi cac phan tu:
    printf("\n\n\t\t ADDRESS ELEMENT ARR : ");
    for(i=0;i<n;i++){
        printf("\n add element arr[%d] = %x .",i,&arr[i]);
    }
    //c. xuat ra kich thuoc cac phan tu.
    printf("\n\n\t\t SIZEOF ELEMENT ARR : ");
    for(i=0;i<n;i++){
        printf("\n Sizeof() element arr[%d] = %d .",i,sizeof(arr[i]));
    }
    //d. Tim max min trong mang:
    printf("\n\n\t\t MAX MIN ELEMENT ARR : ");
    int max =arr[0];
    int min =arr[0];
    for(i=1;i<n;i++){
        if(max<arr[i]){
            max = arr[i];
        }
        if( min >arr[i]){
            min = arr[i];
        }
    }
    printf("\n Value max = %d , min = %d in array.",max,min);
//    e.xu?t ra giá tr? ph?n t? th? 5(n?u có).
    printf("\n\n\t\t VALUE ELEMENT 5th IN ARR : ");
    int value_find;
    printf("\n Moi nhap tim value cua phan tu : ");
    scanf("%d",&value_find);
    if(n<value_find){
        printf("\n Ko co ptu thu %d.",value_find);
    }else{
        printf("\n Value phan tu thu %d: %d ",value_find,arr[value_find+1]);
    }
//    f.Tính t?ng giá tr? trung bình và xu?t ra màn hình.
    int sum=0;
    for(i=0;i<n;i++){
        sum += arr[i];
    }
    printf("\n Value TB = %f .",(float)sum/n);
//    g.Thay th? giá tr? th? 2 do ngu?i dùng nh?p vào.
    if(n<2){
        printf("\n mang ko co ptu thu 2");
    }else{
        printf("\n Input element 2: ");
        scanf("%d",&arr[2]);
    }
    //    Xu?t ra giá tr? các ptu.
        printf("\n\n\t\t VALUE ELEMENT ARR : ");
    for(i=0;i<n;i++){
        printf("\n Value element arr[%d] = %d .",i,arr[i]);
    }

}
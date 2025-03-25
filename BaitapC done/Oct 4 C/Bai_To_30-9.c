/* tao struct preson: hobby,year,sex,address
	tao struct nhanvien: Name voi thuoc tinh person, position(chuc vu), salary(luong),
	tao menu 
	+----------------------------------------------------------------------------------------------+
	|                          KHONG KHO KHI TA BIET TU DUY                      |
	| 90% THANH CONG PHU THUOC VAO SU CHAM CHI CAN CU |
	+----------------------------------------------------------------------------------------------+
	|1. input |2. oupt |3. search |4. add element |5.sort |6. exit               |
	+----------------------------------------------------------------------------------------------+
	case1: nhap du lieu
	case2: xuat du lieu ra ngoai man hinh
	case3:tim kiem nguoi que o ha noi
	case4:them 1 phan tu o vi tri ma nguoi dung nhap vao 
	case5:sap xep mang theo year
	case6:exit*/
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
    #include<stdbool.h>

	struct person{
		char hobby[64];
		char sex[64];
		char address[64];
		int year;
		
	};
	typedef struct person ps;
	
	struct employee{
        char name[64];
		ps obj;
		char id[64];
		char position[64];
		int salary;
		
	};
	typedef struct employee emp1;
	emp1* ptr;
	int i,j,y;
	int number_emp1;
	
void menu(){
	printf("\n+%-100s+","----------------------------------------------------------------------------------------------------");
	printf("\n|%-35s%30s%35s|"," ","KHONG KHO KHI TA BIET TU DUY "," ");
	printf("\n|%-26s%48s%26s|"," ","90% THANH CONG PHU THUOC VAO SU CHAM CHI CAN CU"," ");
	printf("\n+%-100s+","----------------------------------------------------------------------------------------------------");
	printf("\n|%-16s|%-16s|%-16s|%-16s|%-16s|%-15s|","1. input ","2. oupt ","3. search ","4. add element ","5.save file","6. openfile");
	printf("\n+%-100s+","----------------------------------------------------------------------------------------------------");
}
void input_add_1element(int i,int index_add){
	
	printf("\nInput employee number[%d]: ",i+1);
	printf("\nInput name[%d]: ",i+1);
	fflush(stdin);
    gets((ptr+i)->name);
	fflush(stdout);
	printf("\nInput year [%d]: ",i+1);
	scanf("%d",&((ptr+i)->obj).year);
	printf("\nInput address[%d]: ",i+1);
	fflush(stdin);
	gets(((ptr+i)->obj).address);
	fflush(stdout);
	printf("\nInput hobby[%d]: ",i+1);
	fflush(stdin);
	gets(((ptr+i)->obj).hobby);
	fflush(stdout);
	printf("\nInput sex(Male/Female)[%d]: ",i+1);
	fflush(stdin);
	gets(((ptr+i)->obj).sex);
	fflush(stdout);
	undo2:
	printf("\nInput id[%d]: ",i+1);
	fflush(stdin);
	gets((ptr+i)->id);
	fflush(stdout);
	for(j=0;j<number_emp1;j++){
		if(strcmp((ptr+j)->id,(ptr+i)->id)==0 && j != index_add) 
			goto undo2;
    }
	printf("\nInput position[%d]: ",i+1);
	fflush(stdin);
	gets((ptr+i)->position);
	fflush(stdout);
	printf("\nInput salary[%d]: ",i+1);
	scanf("%d",&((ptr+i)->salary));
}
void input(){
	for(i=0;i<number_emp1;i++){
		printf("\nInput employee number[%d]: ",i+1);
		printf("\nInput name[%d]: ",i+1);
		fflush(stdin);
        gets((ptr+i)->name);
		fflush(stdout);
		printf("\nInput year [%d]: ",i+1);
		scanf("%d",&((ptr+i)->obj).year);
		printf("\nInput address[%d]: ",i+1);
		fflush(stdin);
		gets(((ptr+i)->obj).address);
		fflush(stdout);
		printf("\nInput hobby[%d]: ",i+1);
		fflush(stdin);
		gets(((ptr+i)->obj).hobby);
		fflush(stdout);
		printf("\nInput sex(Male/Female)[%d]: ",i+1);
		fflush(stdin);
		gets(((ptr+i)->obj).sex);
		fflush(stdout);
		undo2:
		printf("\nInput id[%d]: ",i+1);
		fflush(stdin);
		gets((ptr+i)->id);
		fflush(stdout);
		for(j=0;j<i;j++){
			if(strcmp((ptr+j)->id,(ptr+i)->id)==0  ) 
				goto undo2;
        }
		printf("\nInput position[%d]: ",i+1);
		fflush(stdin);
		gets((ptr+i)->position);
		fflush(stdout);
		printf("\nInput salary[%d]: ",i+1);
		scanf("%d",&((ptr+i)->salary));
	}
}
	
void output(){
	for(i=0;i<number_emp1;i++){
		printf("\nDisplay employee information[%d]:",i+1);
        printf("\nName of employee [%d]: %s",i+1,(ptr+i)->name);
        printf("\nYear of employee[%d]: %d",i+1,((ptr+i)->obj).year);
        printf("\nAddress of employee[%d]: %s",i+1,((ptr+i)->obj).address);
        printf("\nHobby of employee[%d]: %s",i+1,((ptr+i)->obj).hobby);
        printf("\nSex of employee[%d]: %s",i+1,((ptr+i)->obj).sex);
        printf("\nID of employee[%d]: %s",i+1,(ptr+i)->id);
        printf("\nPosition of employee[%d]: %s",i+1,(ptr+i)->position);
        printf("\nSalary of employee[%d]: %d",i+1,(ptr+i)->salary);
	}
}
void output_table(emp1 object){
	printf("\n|%20s|%10s|%20s|%10d|%20s|%10d|",object.name,object.id,object.position,object.salary,object.obj.address,object.obj.year);
}
void searchemployee(){
    int dem_check=0;
    for(i=0;i<number_emp1;i++){
        if(strcmp(((ptr+i)->obj).address,"Ha Noi")==0){
            dem_check++;
        }
    }
    printf("\nThere are %d of people from Ha Noi:",dem_check);
}
void Addelement(int index_add){

    //*memcpy((ptr+i)->name,x.name,sizeof(emp1));
    if(index_add<=0){
        index_add = 0;
    }else if(y>=number_emp1){
        index_add = number_emp1;
    }else{
    	for(i=number_emp1-1;i>index_add;i--){
        	*(ptr+i) = *(ptr+i-1);
   		}
   		//input add_one_element.
   		for(i=0;i<number_emp1;i++){
   			if(i==index_add){
   				input_add_1element(i,index_add);
			}
   		}
	}
    printf("\nArray before add employee:");
    output();
}
void save_file(char namefile[20],FILE*fptr){
	printf("\n Enter file name : ");
	fflush(stdin);
	gets(namefile);
	fflush(stdout);
	fptr= fopen(namefile,"wb");
	if(fptr==NULL){
		printf("\n opening the file was not seccessful ");
	}else{
		fwrite(ptr,number_emp1*sizeof(emp1),1,fptr );
		if(ferror(fptr)!=0){
			printf("\n The file has not been written successfull !. ");
		}else{
			printf("\n Recorded file successfully.");
		}
	}
	fclose(fptr);

}
	
void open_file(char namefile[20],FILE*fptr){
	emp1 temp;
	
	printf("\n Enter file name : ");
	fflush(stdin);
	gets(namefile);
	fflush(stdout);
	fptr= fopen(namefile,"rb");
	if(fptr==NULL){
		printf("\n opening the file was not seccessful ");
	}else{
		printf("\n|%20s|%10s|%20s|%10s|%20s|%10s|","Name","id","position","salary","address","year");
		while(fread(&temp,sizeof(emp1),1,fptr) == 1) {
			printf("\n +-------------------------------------------------------------------------------------------------------+ ");
			output_table(temp);
		}
	}
	fclose(fptr);
}
	
int main(){
    int n;
    char inputch;
    char file_name[20];
    FILE*fptr =NULL;
    menu:
	menu();
    Nhaplai:
    do{
    printf("\nInput selection: ");
    scanf("%d",&n);
    }while(n<1||n>6);
	switch(n){
        case 1: //input(nhập dữ liệu nhân viên)
	        do{
	            printf("\ninput the number employee: ");
	            scanf("%d",&number_emp1);
	        }while(number_emp1<1);
	        ptr = (emp1*) calloc(number_emp1,sizeof(emp1));
	        input();
	        break;
        case 2://ouput(xuất dữ liệu nhân viên)
	        if(number_emp1==0){
	            printf("\nArray not data:");
	            goto menu;
	        }
	            output();
	        break;
        case 3://search employee(tìm kiếm nhân viên có quê ở Hà Nội)
	        if(number_emp1==0){
	            printf("\nArray not data:");
	            goto menu;
	        }
	            searchemployee();
	        break;
        case 4://Add element ( thêm phân tử)

	        if(number_emp1==0){
	            printf("\nArray not data:");
	            goto menu;
	        }
	        printf("\nInput the location need to the add employee: ");//Vị trí cần chèn phần tử thêm vào
	        scanf("%d",&y);
	        ptr = (emp1*) realloc (ptr,sizeof(emp1)*(number_emp1+1));
	        number_emp1=number_emp1+1;
	            Addelement(y);
	        break;
        case 5://sort the array by year(sắp xếp mang theo năm sinh)
	        if(number_emp1==0){
	            printf("\nArray not data:");
	            goto menu;
	        }
	        save_file(file_name,fptr);
	        break;
	    case 6:
	    	open_file(file_name,fptr);
        default:
        break;
    }
    printf("\nDo you like to return to the Menu?");
    printf("\nYes,i do (y,Y)");
    printf("\nNo, i don't (n,N)");
    printf("\nExit the screen(x,X)");
    undo4:
    scanf("%c",&inputch);
    switch(inputch){
    	case 'y':
    	case 'Y':
    		goto menu;
    	case 'x':
    	case 'X':
    		system("cls");
    	default:
    		goto undo4;
	}
    free(ptr);
    return 0;
}

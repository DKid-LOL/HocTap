#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct mobile{
	char name[25], hangSX[25];
	float giaMB;
	int namSX;
};
typedef struct mobile MB;
int i, j, n;
MB *ptr = NULL;
FILE *fptr = NULL;
void menu(){
	printf("+----------------------------------------------------------------------------------------------------+");
	printf("\n|%-45s|%s|%-45s|", " ", "MOBILE PHONE STORE MANAGEMENT PROGRAM"," ");
	printf("\n+----------------------------------------------------------------------------------------------------+");
	printf("\n|%-13s|%-13s|%-13s|%-13s|%-13s|%-13s|%-13s|", "1. Input", "2. Sort", "3. Analyze", "4. Find", "5. Save", "6. Open", "7. Exit");
	printf("\n+----------------------------------------------------------------------------------------------------+");
}
void input(){
	for(i=0; i<n; i++){
		printf("\nMobile %d : ", i+1);
		printf("\nMobile Name: ");
		fflush(stdin);
		gets((ptr+i)->name);
		fflush(stdout);
		printf("Manufacturer: ");
		fflush(stdin);
		gets((ptr+i)->hangSX);
		fflush(stdout);
		nhapLaiNamsx:
		printf("Release year: ");
		fflush(stdin);
		scanf("%d", &(ptr+i)->namSX);
		fflush(stdout);
		if((ptr+i)->namSX < 1999){
			printf("Mobile release year must be greater than or equal to 1999.");
			goto nhapLaiNamsx;
		}
		nhapLaiGiaSP:
		printf("Price: ");
		fflush(stdin);
		scanf("%f", &(ptr+i)->giaMB);
		fflush(stdout);
		if((ptr+i)->giaMB < 500 || (ptr+i)->giaMB > 6000){
			printf("Mobile price must be between 500($) and 6000($)");
				goto nhapLaiGiaSP;
		}
	}	
}
void output_Header(){
	printf("\n+----------------------------------------------------------------------------------------------------+");
	printf("\n|%-25s|%-25s|%-23s|%-24s|", "Mobile Name", "Manufacturer", "Release Year", "Price");
	printf("\n+----------------------------------------------------------------------------------------------------+");
}
void output_body(){
	printf("\n|%-25s|%-24s|%-24d|%-24f|", (ptr+i)->name, (ptr+i)->hangSX, (ptr+i)->namSX, (ptr+i)->giaMB);
	printf("\n+----------------------------------------------------------------------------------------------------+");
}
void sapXepTen(){
	for(i=0; i<n-1; i++){
		for(j=1; j<n; j++){
			if(strcmp((ptr+i)->name, (ptr+j)->name)>0){
				MB tgMB = *(ptr+i);
				*(ptr+i) = *(ptr+j);
				*(ptr+j) = tgMB;
			}
		}
	}
	output_Header();
	for(i=0; i<n; i++){
		output_body();
	}
}
void timKiem(){
	char timHangMB[25];
	int demHangSX = 0;
	printf("\nInput Manufacturer: ");
	fflush(stdin);
	gets(timHangMB);
	fflush(stdout);
	for(i=0; i<n; i++){
		if(strcmp((ptr+i)->hangSX, timHangMB)== 0){
			demHangSX++;
		}
	}
	if(demHangSX == 0){
		printf("\nThe manufacturer you just entered cannot be found.");
	}
	else{
		printf("\nFound %d manufacturer you are looking for: ", demHangSX);
		output_Header();
		for(i=0; i<n; i++){
			if(strcmp((ptr+i)->hangSX, timHangMB)== 0){
				output_body();
			}			
		}
	}
}
void savefile(){
	FILE *fptr;
	fptr = fopen("namefile.dat", "w");
	if(fptr == NULL){
		printf("\nError");
	}
	else{
		fwrite(ptr,n*sizeof(MB), 1, fptr);
		if(ferror(fptr) != 0){
			printf("\nError");
		}
		else{
			printf("\nDone");		
		}
	}
	fclose(fptr);
}
void openfile(){
	FILE *fptr;
	MB temp;
	fptr = fopen("namefile.dat", "r");
	if(fptr == NULL){
		printf("\nError");
	}
	else{
		output_Header();
		while(fread(&temp, n*sizeof(MB), 1, fptr) == 1){
			printf("\n|%-25s|%-25s|%-25d|%-25f|", temp.name, temp.hangSX, temp.namSX, temp.giaMB);
			printf("\n+----------------------------------------------------------------------------------------------------+");
		}		
	}
	fclose(fptr);
}
void main(){
	quayLaiMenu:
	menu();
	int m;
	printf("\nInput your choice: ");
	scanf("%d", &m);
	switch(m){
		case 1:
			printf("\nNumber of mobile: ");
			scanf("%d", &n);
			ptr = (MB*)calloc(n, sizeof(MB));
			input();
			break;
		case 2:
			sapXepTen();
			break;
		case 3:
			timKiem();
			break;
		case 4:
			break;
		case 5:
			savefile();
			break;
		case 6:
			openfile();
			break;
		case 7:
			break;
		default:
			printf("\nChoose between 1 to 7. Please try again");
			goto quayLaiMenu;
			break;
	}
	nhapLaiLC:
	printf("\nDo you want to continue ?");
	printf("\n- Yes, I do. ( press 'y', 'Y')");
	printf("\n- No , I don't. (press 'n', 'N')");
	printf("\n- Please crear the screen ! (press 'c', 'C')");
	char select;
	printf("\nYour choice : ");
	fflush(stdin);
	scanf("%c", &select);
	fflush(stdout);
	switch(select){
		case 'y':
		case 'Y':
			goto quayLaiMenu;
				break;
		case 'x':
		case 'X':
			exit(0);
				break;
		case 'c':
		case 'C':
			system("cls");
				break;
		default:
			printf("\nplease try again: ");
			goto nhapLaiLC;
			break;			
	}

free(ptr);
return 0;
}
























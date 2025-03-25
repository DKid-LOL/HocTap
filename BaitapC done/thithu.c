#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[25];
    char nationality[25];
    int birth_year;
    float net_worth;
};

typedef struct Person PS;

PS *ptr_ps;
int i,n,j;
void input() {
    for (i=0;i<n;i++) {
        printf("\n Please input Person[%d]",i+1);
        printf("\n Name:");
        fflush(stdin);
        gets((ptr_ps+i)->name);
        fflush(stdout);
        printf("\n Nationality:");
        fflush(stdin);
        gets((ptr_ps+i)->nationality);
        fflush(stdout);
        int birth_year;
        do {
            printf("\nBirth Year: ");
            scanf("%d", &birth_year);
            if (birth_year>1993) {
                printf("\n Person age must be less than or equal to 30");
            } else {
                (ptr_ps+i)->birth_year=birth_year;
            }
        } while (birth_year>1993);

    float net_worth;
        do{
            printf("\nNet Worth: ");
            scanf("%f", &net_worth);
            if (net_worth<1||net_worth>100) {
                printf("\n Net worth must be between 1 (billion $) and 100 (billion $).");
            } else {
                (ptr_ps+i)->net_worth=net_worth;
            }
        } while (net_worth<1||net_worth>100);
    }
}

void display() {
    printf("\n+-----------------------------------------------------------------------------------------------------+");
    printf("\n|%-25s|%-25s|%-25s|%-25s|", "Person Name", "Nationality", "Birth Year", "Net Worth (billion $)");
    printf("\n+-----------------------------------------------------------------------------------------------------+");
    for (i=0; i<n;i++) {
        printf("\n|%-25s|%-25s|%-25d|%-25.2f|",(ptr_ps+i)->name,(ptr_ps+i)->nationality,(ptr_ps+i)->birth_year,(ptr_ps+i)->net_worth);
    }
    printf("\n+-----------------------------------------------------------------------------------------------------+");
}
void sort(){
    for(i=0; i<n-1;i++) {
        for(j=i+1;j<n;j++) {
            if ((ptr_ps+i)->net_worth<(ptr_ps+j)->net_worth) {
                PS temp=*(ptr_ps+i);
                *(ptr_ps+i)=*(ptr_ps+j);
                *(ptr_ps+j)=temp;
            }
        }
    }
    display();
}

void analyze() {
    int count=0;
    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (strcmp((ptr_ps+i)->nationality,(ptr_ps+j)->nationality)==0){
                count++;
                break;
            }
        }
    }

    printf("Statistics Result:\n");
    for (i=0;i<n;i++) {
        int temp=0;
        for (j = 0; j < i; j++) {
            if(strcmp((ptr_ps+i)->nationality,(ptr_ps+j)->nationality)==0){
                temp=1;
                break;
            }
        }
        if (temp==0) {
            count=0;
            for(j=i;j<n;j++) {
                if (strcmp((ptr_ps+i)->nationality,(ptr_ps+j)->nationality)==0){
                    count++;
                }
            }
            printf("+ There are %d person(s) from '%s'.\n", count,(ptr_ps+i)->nationality);
        }
    }
}

void find(){
    char targetNationality[25];
    float minNetWorth;
    int found=0;

    printf("Enter Nationality: ");
    fflush(stdin);
    gets(targetNationality);
    fflush(stdout);

    printf("Enter Min Net Worth (billion $): ");
    scanf("%f",&minNetWorth);

    printf("Search Results:\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|Person Name   |Nationality     |Birth Year     |Net Worth (billion $)    |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    for (i = 0; i < n; i++) {
        if (strcmp((ptr_ps+i)->nationality,targetNationality)==0&&(ptr_ps+i)->net_worth>minNetWorth) {
            printf("|%-14s|%-16s|%-14d|%-24.2f|\n", (ptr_ps+i)->name,(ptr_ps+i)->nationality,(ptr_ps+i)->birth_year,(ptr_ps+i)->net_worth);
            found++;
        }
    }
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("%d persons found.\n", found);
}

void save(){
    char fileName[100];
    FILE *file;

    printf("File name: ");
    fflush(stdin);
    gets(fileName);
    fflush(stdout);

    file=fopen(fileName, "wb");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    fwrite(&n, sizeof(int), 1, file);

    for (i=0;i<n;i++) {
        fwrite((ptr_ps+i),sizeof(PS),1,file);
    }

    fclose(file);
    printf("Data successfully saved into file!\n");
}

void open(){
    char fileName[100];
    FILE *file;

    printf("File name: ");
    fflush(stdin);
    gets(fileName);
    fflush(stdout);

    file=fopen(fileName,"rb");

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        return;
    }

    if (ptr_ps != NULL) {
        free(ptr_ps);
    }

    fread(&n,sizeof(int),1,file);

    ptr_ps=(PS*)malloc(n*sizeof(PS));

    for (i=0;i<n;i++){
        fread((ptr_ps+i), sizeof(PS),1,file);
    }

    fclose(file);

    printf("+-----------------------------------------------------------------------------------------------------+\n");
    printf("|Person Name   |Nationality     |Birth Year     |Net Worth (billion $)    |\n");
    printf("+-----------------------------------------------------------------------------------------------------+\n");
    for (i=0;i<n;i++) {
        printf("|%-14s|%-16s|%-14d|%-24.2f|\n", (ptr_ps+i)->name, (ptr_ps+i)->nationality,(ptr_ps+i)->birth_year,(ptr_ps+i)->net_worth);
    }
    printf("+-----------------------------------------------------------------------------------------------------+\n");

    printf("Data successfully loaded from file!\n");
}
 int main(){
undo1:
    printf("\n+------------------------------------------------------------------+");
    printf("\n|%-13s%-39s%-14s%|", " ", "BILLIONAIRES PROFILE MANAGEMENT PROGRAM", " ");
    printf("\n+------------------------------------------------------------------+");
    printf("\n|1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit |");
    printf("\n+------------------------------------------------------------------+");
    char choice;
    printf("\n Enter your choice: "); choice=getchar();
    while(choice == '\n'){
        choice = getchar();
    }
    switch(choice){
        case '1':
            do {
                printf("\nInput the number of persons: ");
                scanf("%d", &n);
            } while (n < 1);
            ptr_ps=(PS*)calloc(n,sizeof(PS));
            input();
            goto undo2;
            break;
        case '2':
            sort();
            goto undo2;
            break;
        case '3':
            analyze();
            goto undo2;
            break;
        case '4':
            find();
            goto undo2;
            break;
        case '5':
            save();
            goto undo2;
            break;
        case '6':
            open();
            goto undo2;
            break;
        case '7':
            system("cls");
            break;
        default:
            printf("Error. Please choose again");
            break;
    }
undo2:
    printf("\nDo you want to continue?");
    printf("\nYes, I do (y, Y)");
    printf("\nNo, I don't (n, N, 7)");
    printf("\nExit the program (x, X)");
    printf("\nYour choice: ");
    choice=getchar();
    while (choice == '\n'){
        choice=getchar();        
    }
    switch(choice){
        case 'y':
        case 'Y':
            goto undo1;
            break;
        case 'n':
        case 'N':
        case '7':
            return 0;
            break;
        case 'x':
        case 'X':
            system("cls");
            break;
    }
    free(ptr_ps);
    return 0;
}


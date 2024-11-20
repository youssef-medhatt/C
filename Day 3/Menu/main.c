
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <dos.h>
#include <dir.h>
#define UP 72
#define ENTER 13
#define ESC 27
#define DOWN 80
#define BACKSPACE 8
#define NEW 1
#define DISPLAY 2
#define MODIFY 3
#define EXIT 4
#define ROW 0
#define COL 50
#define SIZE 100
#define WHITE 7
#define BLUE 1
#include "youssef_string.h"
typedef struct Employee{
    int code;
    char name[30];
    int salary;
}Employee;
void enterEmployee(Employee e[],int i){
int validInput = 0;
while(!validInput){
    fflush(stdin);
     printf("Enter Employee %d id = ",i+1);
     int isNum = scanf("%d",&e[i].code);
     if(isNum && e[i].code > 0){
       validInput =1;
     for(int j =0;j<i;j++){
     if(e[i].code == e[j].code) {validInput = 0 ; printf("ID taken, choose another \n");}
     }
     }
     else printf("Invalid ID\n");
}
validInput = 0;
     printf("Enter Employee %d Name = ",i+1);
     fflush(stdin);
     scanf("%s",e[i].name);
while(!validInput){
    fflush(stdin);
     printf("Enter Employee %d Salary = ",i+1);
     int isNum = scanf("%d",&e[i].salary);
     if(isNum) validInput =1;
     else printf("Invalid input, please enter a number \n");
}
}
void gotoxy1(int x,int y){
COORD coord;
coord.X = y;
coord.Y = x;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void SetColor(int ForgC){
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }


void New(){
system("cls");
SetColor(BLUE);
gotoxy1(ROW+5,COL);
printf("1.NEW \n");
SetColor(WHITE);
gotoxy1(ROW+10,COL);
printf("2.DISPLAY \n");
gotoxy1(ROW+15,COL);
printf("3.MODIFY \n");
gotoxy1(ROW+20,COL);
printf("4.EXIT \n");
gotoxy1(ROW+25,COL-28);
printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}

void Display(){
system("cls");
gotoxy1(ROW+5,COL);
printf("1.NEW \n");
SetColor(BLUE);
gotoxy1(ROW+10,COL);
printf("2.DISPLAY \n");
SetColor(WHITE);
gotoxy1(ROW+15,COL);
printf("3.MODIFY\n");
gotoxy1(ROW+20,COL);
printf("4.EXIT\n");
gotoxy1(ROW+25,COL-28);
printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
void Modify(){
system("cls");
gotoxy1(ROW+5,COL);
printf("1.NEW \n");
gotoxy1(ROW+10,COL);
printf("2.DISPLAY \n");
SetColor(BLUE);
gotoxy1(ROW+15,COL);
printf("3.MODIFY\n");
SetColor(WHITE);
gotoxy1(ROW+20,COL);
printf("4.EXIT\n");
gotoxy1(ROW+25,COL-28);
printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
void Exit(){
system("cls");
gotoxy1(ROW+5,COL);
printf("1.NEW \n");
gotoxy1(ROW+10,COL);
printf("2.DISPLAY \n");
gotoxy1(ROW+15,COL);
printf("3.MODIFY\n");
gotoxy1(ROW+20,COL);
SetColor(BLUE);
printf("4.EXIT\n");
SetColor(WHITE);
gotoxy1(ROW+25,COL-28);
printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
int NewPressed(Employee empArr[],int i){
system("cls");
char userChoice;

while(!(userChoice == 'n' || userChoice == 'N')){
int validInput = 0;
printf("Enter Employee data \n");
enterEmployee(empArr,i);
        i++;
while(!validInput){
fflush(stdin);
printf("Do you want to enter another employee? (y/n) \n");
scanf("%c",&userChoice);
if(userChoice == 'y' || userChoice == 'Y' || userChoice == 'n' || userChoice == 'N'){
validInput = 1;
}
else{
                                              printf("INVALID INPUT! \n");

                                            }
}
                                            }

return i;
}
void DisplayPressed(Employee empArr[]){
system("cls");

int i = 0;
while(empArr[i].code != 0){

     printf("Employee %d id = %d \n",i+1,empArr[i].code);

     printf("Employee %i Name = %s \n",i+1,empArr[i].name);

    printf("Employee %d Salary = %d \n",i+1,empArr[i].salary);
    printf("-------------------------- \n");

i++;
}
}
int ModifyPressed(Employee empArr[],int indexOfLastEmp){
system("cls");
int i = 0;
int idChoice;
int empIndex;
int validInput=0;
char userChoice;
while(empArr[i].code != 0){
     printf("Employee %d id = %d \n",i+1,empArr[i].code);
i++;
}
while(!validInput){
i = 0;
printf("Choose ID to edit: \n");
fflush(stdin);
int exist=0;
int isNum = scanf("%d",&idChoice);
if(isNum){
    while(empArr[i].code != 0){
     if(idChoice == empArr[i].code){ empIndex = i; exist =1;}
i++;
}
}
if(isNum && exist){
    validInput = 1;
}
else{
    printf("INVALID ID! \n");
}

}
validInput=0;

while(!validInput){
printf("Press n for Name or s for Salary or i for ID or d to delete \n");
fflush(stdin);
scanf("%c",&userChoice);
if(userChoice == 's' || userChoice == 'd' || userChoice == 'n' || userChoice == 'i'){
    validInput = 1;
}
else{
    printf("Invalid choice \n");
}


}
validInput = 0;
if(userChoice == 's'){
      int salary;
            while(!validInput){
                fflush(stdin);
                 printf("Enter New Salary = ");
                 int isNum = scanf("%d",&salary);
                 if(isNum) validInput =1;
                 else printf("Invalid input, please enter a number \n");
            }
            empArr[empIndex].salary = salary;

}
else if(userChoice == 'n'){
               char name[30];
                fflush(stdin);
                 printf("Enter New Name = ");
                 scanf("%s",name);
            voidStringCopy(empArr[empIndex].name,name,30);

}
else if(userChoice == 'i'){
        int id;
    while(!validInput){
    fflush(stdin);
     printf("Enter New ID = ");
     int isNum = scanf("%d",&id);
     if(isNum && id > 0){
       validInput =1;
     for(int j =0;j<i;j++){
     if(id == empArr[j].code) {validInput = 0 ; printf("ID taken, choose another \n");}
     }
     }
     else printf("Invalid ID\n");
}
empArr[empIndex].code = id;
}
else if(userChoice == 'd'){
        int j =empIndex;
    while(empArr[j].code != 0){
        empArr[j].code=empArr[j+1].code;
        voidStringCopy(empArr[j].name,empArr[j+1].name,30);
        empArr[j].salary=empArr[j+1].salary;
        j++;
    }
    indexOfLastEmp--;
}
printf("DONE! \n");
return indexOfLastEmp;
}

int main()
{


Employee empArr[SIZE]={0};
int Option = NEW;
int Menu = 0;
char ch = 0;
int indexOfEmp = 0;

        gotoxy1(ROW+5,COL);
        SetColor(BLUE);
        printf("1.NEW \n");
        gotoxy1(ROW+10,COL);
        SetColor(WHITE);
        printf("2.DISPLAY \n");
        gotoxy1(ROW+15,COL);
        printf("3.MODIFY \n");
        gotoxy1(ROW+20,COL);
        printf("4.EXIT \n");
        gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");
    while(ch != ESC ){
        ch = getch();
            if(ch == -32){
                ch = getch();
                        }
    if(Menu == 0 && (ch == UP ||  ch == DOWN)){
                        if(ch == UP){
                                if(Option == NEW){
                                    Option = EXIT;
                                }
                                else{
                            Option--;
                                }
                        }
                        else if(ch == DOWN){
                            if(Option == EXIT){
                                Option = NEW;
                            }
                            else{
                                Option++;
                            }
                        }
                            switch(Option){
                                    case NEW:
                                        New();
                                        break;
                                    case DISPLAY:
                                        Display();
                                        break;
                                    case MODIFY:
                                        Modify();
                                        break;
                                    case EXIT:
                                        Exit();
                                        break;
                                    default:
                                        printf("INVALID!");

        }
    }
                         if(Menu == 0 && ch == ENTER){
                                Menu = 1;
                                    switch(Option){

                                        case NEW:
                                            indexOfEmp = NewPressed(empArr,indexOfEmp);
                                            printf("ENTER BACKSPACE TO GO BACK OR ESC TO EXIT");
                                            break;
                                        case DISPLAY:
                                            DisplayPressed(empArr);
                                            printf("ENTER BACKSPACE TO GO BACK OR ESC TO EXIT");
                                            break;
                                        case MODIFY:
                                            indexOfEmp = ModifyPressed(empArr,indexOfEmp);
                                            printf("ENTER BACKSPACE TO GO BACK OR ESC TO EXIT");
                                            break;
                                        case EXIT:
                                            ch = ESC;
                                            break;

        }

                        }
                       if(Menu == 1 && ch == BACKSPACE){
                           system("cls");

                            Option = NEW;
        Menu = 0;
        gotoxy1(ROW+5,COL);
        SetColor(BLUE);
        printf("1.NEW \n");
        gotoxy1(ROW+10,COL);
        SetColor(WHITE);
        printf("2.DISPLAY \n");
        gotoxy1(ROW+15,COL);
        printf("3.MODIFY \n");
        gotoxy1(ROW+20,COL);
        printf("4.EXIT \n");
        gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

                       }


    }




    return 0;
}

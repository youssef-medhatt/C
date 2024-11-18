
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <dos.h>
#include <dir.h>
#define UP 72
#define ENTER 13
#define DOWN 80
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
SetColor(1);
printf("1.NEW \n");
SetColor(7);

printf("2.DISPLAY \n");
printf("3.EXIT \n");
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE\n OR ESC TO EXIT");

}
void Display(){
system("cls");

printf("1.NEW \n");
SetColor(1);

printf("2.DISPLAY \n");
SetColor(7);

printf("3.EXIT\n");
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE\n OR ESC TO EXIT");

}
void Exit(){
system("cls");
printf("1.NEW \n");
printf("2.DISPLAY \n");
SetColor(1);

printf("3.EXIT \n");
SetColor(7);

        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE\n OR ESC TO EXIT");

}
void NewPressed(){
system("cls");
printf("1.NEW PRESSED \n");

}
void DisplayPressed(){
system("cls");


printf("2.DISPLAY PRESSED\n");

}
void ExitPressed(){
system("cls");


printf("3.EXIT PRESSED \n");
}
int main()
{



int Option = 1;
char ch = 0;

        printf("1.NEW \n");
        printf("2.DISPLAY \n");
        printf("3.EXIT \n");
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE\n OR ESC TO EXIT");
    while(ch != 27){
        ch = getch();
            if(ch == -32){
                ch = getch();
                        }
                        if(ch == UP){
                                if(Option == 1){
                                    Option = 3;
                                }
                                else{
                            Option--;
                                }
                        }
                        else if(ch == DOWN){
                            if(Option == 3){
                                Option = 1;
                            }
                            else{
                                Option++;
                            }
                        }
                        else if(ch == ENTER){
                                    switch(Option){
                                        case 1:
                                            NewPressed();
                                            break;
                                        case 2:
                                            DisplayPressed();
                                            break;
                                        case 3:
                                            ExitPressed();
                                            break;
                                        default:
                                            printf("INVALID!");

        }
                        break;
                        }
                        else{
                            continue;
                        }
        switch(Option){
    case 1:
        New();
        break;
    case 2:
        Display();
        break;
    case 3:
        Exit();
        break;
    default:
        printf("INVALID!");

        }

    }



    return 0;
}

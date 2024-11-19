
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
#define EXIT 3
#define ROW 5
#define COL 50
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
SetColor(1);
gotoxy1(ROW,COL);
printf("1.NEW \n");
SetColor(7);
gotoxy1(ROW+10,COL);
printf("2.DISPLAY \n");
gotoxy1(ROW+20,COL);
printf("3.EXIT \n");
gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
void Display(){
system("cls");
gotoxy1(ROW,COL);
printf("1.NEW \n");
SetColor(1);
gotoxy1(ROW+10,COL);

printf("2.DISPLAY \n");
SetColor(7);
gotoxy1(ROW+20,COL);

printf("3.EXIT\n");
gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
void Exit(){
system("cls");
gotoxy1(ROW,COL);

printf("1.NEW \n");
gotoxy1(ROW+10,COL);

printf("2.DISPLAY \n");
SetColor(1);
gotoxy1(ROW+20,COL);

printf("3.EXIT \n");
SetColor(7);
gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");

}
void NewPressed(){
system("cls");
printf("1.NEW PRESSED \n");

}
void DisplayPressed(){
system("cls");


printf("2.DISPLAY PRESSED\n");

}

int main()
{



int Option = NEW;
char ch = 0;
gotoxy1(ROW,COL);
        printf("1.NEW \n");
        gotoxy1(ROW+10,COL);
        printf("2.DISPLAY \n");
        gotoxy1(ROW+20,COL);
        printf("3.EXIT \n");
        gotoxy1(ROW+25,COL-28);
        printf("NAVIGATE USING UP-ARW AND DOWN-ARW AND ENTER TO CHOOSE OR ESC TO EXIT");
    while(ch != ESC ){
        ch = getch();
            if(ch == -32){
                ch = getch();
                        }
    if(ch == UP ||  ch == DOWN || ch == BACKSPACE){
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
                                    case EXIT:
                                        Exit();
                                        break;
                                    default:
                                        printf("INVALID!");

        }
    }
                         if(ch == ENTER){
                                    switch(Option){
                                        case NEW:
                                            NewPressed();
                                                    printf("ENTER BACKSPACE TO GO BACK OR ESC TO EXIT");

                                            break;
                                        case DISPLAY:
                                            DisplayPressed();
                                                    printf("ENTER BACKSPACE TO GO BACK OR ESC TO EXIT");

                                            break;
                                        case EXIT:
                                            ch = ESC;
                                            break;

        }

                        }



    }



    return 0;
}

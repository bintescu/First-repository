#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int verificareLINIE(int c,char **A)
{
    if((A[c][0]==A[c][1] && A[c][1]==A[c][2]) && A[c][0]=='X' ) return 1;
    if((A[c][0]==A[c][1] && A[c][1]==A[c][2]) &&  A[c][0]=='O' ) return 2;
   else return 0;
}

int verificareColoana(int c,char **A)
{
    if((A[0][c]==A[1][c] && A[1][c]==A[2][c]) && A[0][c]=='X' ) return 1;
    if((A[0][c]==A[1][c] && A[1][c]==A[2][c]) &&  A[0][c]=='O') return 2;
    return 0;
}

int verificareDiagonala(char **A)
{
    if(A[0][0]==A[1][1] && A[1][1]==A[2][2] && A[0][0]=='X' ) return 1;
    if(A[0][2]==A[1][1] && A[1][1]==A[2][0] &&  A[0][2]=='X')  return 2;
    if(A[0][2]==A[1][1] && A[1][1]==A[2][0] &&  A[0][2]=='O')  return 2;
    if(A[0][0]==A[1][1] && A[1][1]==A[2][2] && A[0][0]=='O' ) return 2;
    return 0;
}


int GameOver(char **A)
{
int i;
for(i=0;i<3;i++)
{
    if (verificareColoana(i,A) ==1 || verificareLINIE(i,A) == 1 || verificareDiagonala(A) == 1)
    {
    printf("\n\n    Game Over  , X a castigat ");
     return 0;

    }
    else if(verificareColoana(i,A) ==2 || verificareLINIE(i,A)==2 || verificareDiagonala(A)==2 )
    {
         printf("\n\n    Game Over  , O a castigat ");
     return 0;

    }
}
    return 1;
}

void puneX(char **A)
{ int l,c;
  printf(" \n X : Pe ce linie si coloana punem X ?\n");
    scanf("%d%d",&l,&c);

    while(l<1 || l>3 || c<1 || c>3 || A[l-1][c-1]=='X' || A[l-1][c-1]=='O'  )
       {
           printf(" \n X : Ai gresit , pe ce linie si coloana punem X ?\n");
    scanf("%d%d",&l,&c);
       }
   A[l-1][c-1]='X';
}

int puneO(int l,int c,char **A)
{

 if(A[l][c]!='X' && A[l][c]!='O')
  {
      A[l][c]='O';
      return 1;
  }
else return 0;

}

int puneOManual(char **A)
{
 int l,c;

        printf(" \n   O : Pe ce linie si coloana punem O ?\n");
    scanf("%d%d",&l,&c);
   while(l<1 || l>3 || c<1 || c>3 || A[l-1][c-1]=='X' || A[l-1][c-1]=='O'  )
       {
           printf(" \n O : Ai gresit , pe ce linie si coloana punem O ?\n");
    scanf("%d%d",&l,&c);
       }
   A[l-1][c-1]='O';
}
void afisare(char **A)
{
    int i=0,j=0;

    for(i=0;i<3;i++)
    { printf("\n");
      for(j=0;j<3;j++)
        printf("| %c ",A[i][j]);
    printf("|\n________________");
    }
}

int cateColoaneSuntPline(char **A)
{   int i,j,c=0,nr=0;
    for(j=0;j<3;j++)
       {  c=0;
           for(i=0;i<3;i++)
    {
        if(A[i][j]=='X' || A[i][j]=='O') {c++;}
        else break;
    }
      if(c==3) nr++; }

return nr;
}

int cateRanduriSuntPline(char **A)
{
    int i,j,nr=0,c=0;
    for(i=0;i<3;i++)
    { c=0;
        for(j=0;j<3;j++)
        {
            if(A[i][j]=='X' || A[i][j]=='O') {c++;}
                else break;
        }

    if(c==3) {nr++; printf("\n\n Este plina linia %d \n \n",i);}

    }
    return nr;
}

int matriceaPlina(char **A)
{ int i,j,nr=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
{
    if(A[i][j]=='X' || A[i][j]=='O') nr++;
}
 if(nr==9) return 1;
 else return 0;

}



int main()
{

    //char A[3][3]={{0,0,0},{0,0,0},{0,0,0}};
char **A=(char **)malloc(3*sizeof(char **));
A[0]=(char *)calloc(9,sizeof(char*));
int i=0;
for(i=0;i<3;i++)
A[i]=A[0]+i*3;

   printf("\n Apasa N pentru 2 jucatori sau M pentru un singur jucator \n");
    char ch;
do {ch = getch();} while(ch!='N' && ch!='n' && ch!='M' && ch!='m');
system("cls");

 time_t t;

    afisare(A);
    int runda=1;
  do
   {    int l,c;
        printf("   \n\n\n  Runda %d \n ",runda++);
       puneX(A);
     system("cls");
    afisare(A);                                       //if(GameOver(A)==0) {system("cls"); afisare(A); printf("\n \n X a castigat \n \n"); break;}
    if(matriceaPlina(A)){ system("cls"); afisare(A) ;  printf("\n \n Game over : Nimeni nu a castigat \n \n"); break;}
    if(GameOver(A)==0) { system("cls"); afisare(A) ; printf("\n\n X a castigat , Game Over \n\n"); break;}
    if(ch=='m' || ch=='M') {
        do{
          srand((unsigned) time(&t));
         l=rand() % 3;
         c=rand()% 3;
        } while(puneO(l,c,A)==0);
    }
    else if(ch=='N' || ch=='n')
    {
       puneOManual(A);
    }
    system("cls");
    afisare(A);

   } while(GameOver(A)==1);
                                                           //if(GameOver(A)==1 && n==0) printf(" O a castigat ");
    return 0;
}

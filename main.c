#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <errno.h>
#define MAX 255

int Palindrome(char * ReadLine, int Letters, int ind);
void MoveWord(char * ReadLine, char * WriteLine, int *wPos, int Letters, int ind);
void InsertSpace(char * WriteLine,int *wPos);
void DoStuff(char * ReadLine,char * WriteLine);

int main(int kiek,char *Parametrai[])
{
    char ReadLine[MAX];
    char WriteLine[MAX];
    FILE * rPointer;
    FILE * wPointer;
    rPointer = fopen(Parametrai[1],"r");
    wPointer = fopen(Parametrai[2],"w");

    if(rPointer == NULL || wPointer == NULL)
    {
        perror("");
        return 0;
    }

    while(!feof(rPointer))
    {
        fgets(ReadLine,255,rPointer);
        DoStuff(ReadLine,WriteLine);
        fputs(WriteLine,wPointer);
    }

    fclose(rPointer);
    fclose(wPointer);

    return 0;
}

int Palindrome(char * ReadLine, int Letters, int ind)
{
    int i;
    int x = ind+Letters;
    for(i = ind; i < ind+Letters; i++)
    {
        if(ReadLine[i]!=ReadLine[--x])
                    return 0;
    }
    return 1;
}

void MoveWord(char * ReadLine, char * WriteLine, int *wPos, int Letters, int ind)
{
    int i;
    for(i = ind; i < ind+Letters; i++)
    {
        WriteLine[(*wPos)]=ReadLine[i];
        (*wPos)++;
    }
}

void InsertSpace(char * WriteLine,int *wPos)
{
    WriteLine[(*wPos)]=' ';
    (*wPos)++;
}

void DoStuff(char * ReadLine,char * WriteLine)
{
    int Letters = 0;
    int wPos = 0;
    int i;
    int Length = strlen(ReadLine);
    memset(WriteLine,0,255);
    for(i = 0; i <= Length; i++)
    {
        if(ReadLine[i]!=' ' && i != Length)
            Letters++;

        else
        {

            if(Palindrome(ReadLine,Letters,i-Letters) == 0)
                MoveWord(ReadLine,WriteLine,&wPos,Letters+1,i-Letters);

            else
                InsertSpace(WriteLine,&wPos);

            Letters = 0;
        }
    }
}



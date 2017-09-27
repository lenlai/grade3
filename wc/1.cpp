#include "stdio.h"
#include "string.h"
#include "stdlib.h"
 
int charcalculate=0;
 
int wordcalculate=0;
 
int linecalculate=0;
 
void calculate(char * file)
{
    FILE *fp;
    char a;
    if((fp=fopen(file,"r"))==NULL)
    {
        printf("read file failed£¡\n");
        exit(-1);
    }
    while(!feof(fp))
    {
        a=fgetc(fp);
        if(a!=' '&&a!='\n'&&a!='\t'&&a!=','&&a!='.'&&a!='!'&&a!=';'&&a!='=')
            charcalculate++;
        if(a==' '||a=='\n'||a=='\t'||a==','||a=='.'||a=='!'||a=='='||a==';')
            wordcalculate++;
        if(a=='\n'||a=='\t')
            linecalculate++;
    }
    linecalculate++;
    charcalculate--;         
    fclose(fp);
}
 
int main(int argc, char* argv[])             
{
    FILE *fp;
 
    calculate(argv[2]);
    while(1)
    {
        if((fp=fopen(argv[2],"r"))==NULL)
        {  
        printf("FileNull\n\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
        continue;
        }
        else if(!strcmp(argv[1],"-c"))                 
            printf("File:%sCharNum:%d\n",argv[2],charcalculate);
        else if(!strcmp(argv[1],"-w"))                  
            printf("File:%sWordNum:%d\n",argv[2],wordcalculate);
        else if(!strcmp(argv[1],"-l"))                
            printf("File:%sLineNum:%d\n",argv[2],linecalculate);
        else if(!strcmp(argv[1],"exit"))
        {
            printf("Exit!\n");
            break;
        }
        else
            printf("NullPoint\n");
        printf("\n\n");
        scanf("%s%s%s",argv[0],argv[1],argv[2]);
    }
    return 0;
     
}
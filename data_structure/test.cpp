#include<stdio.h>
int main(int argc,char *args[]){
    int i,k;
    printf("Hello World");
    printf("argc:%d\nargv:\n",argc);
    for(i = 0 ; i<argc;i++){
        printf("%d : %s\n",i,args[i]);
    }
    getchar();
    return 0;
}


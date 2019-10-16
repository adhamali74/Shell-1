#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
using namespace std;
char* argv[50];
char line[255];
int c;
bool b=false;
int cid;
void khlsne(){
    char* temp;
    temp=strtok(line," ");
    while(temp){
        if(temp[0]=='&'){
            b=true;
            argv[c]=NULL;
            return;
        }
        argv[c++]=temp;
        temp=strtok(NULL," ");
    }
    int l=strlen(argv[c-1]);
    argv[c-1][l-1]='\0';
    argv[c]=NULL;
}
int main()
{
    hell:
    printf("SHELL>> ");
    b=false;
    c=0;
    fgets(line,255,stdin);
    khlsne();
    if(!strcmp(argv[0],"exit"))exit(0);
    pid_t id=fork();
    if(!id){
        execvp(argv[0],argv);
    }
    else{
    if(!b)
    wait(NULL);
    printf("Process %d has been terminated\n",id);
    goto hell;
    }
}


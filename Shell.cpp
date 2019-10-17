#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
using namespace std;
char* argv[50];
char line[255];
set<int> PIDs;
int c;
FILE* f;
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
void handler(int x){
int status;
for(auto x:PIDs){
   if(waitpid(x,&status,WNOHANG)){
    PIDs.erase(x);
    fprintf(f,"This process %d is terminated \n",x);
}
}
}

int main()
{
    signal(SIGCHLD,handler);
    f=fopen("log.txt","w");
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
    PIDs.insert(id);
    if(!b)
    wait(NULL);
    goto hell;
    }
}


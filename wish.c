/* Lähteet
https://github.com/dmulholl/kash/blob/master/src/kash.c parsinta aliohjelma.
Tästä linkistä on haettu apua käyttäjän käskyn parsimiseen. Rivit 100-130

https://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf
Tästä on otettu mallie kuinka lapsi prosessi ajetaan.  
 */



#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

#define MAX 30

void interactiveMode();
void batchMode(char *);
char** parseInput(char *);
int builtInCommands(char**);
void executeBuildInCommands(int);
void executeCommands(char **);

int main(int argc, char* argv[]){
    char *check;
    char error_message[30] = "An error has occurred\n";
    if(argc==1){ 
        interactiveMode();
    }else if(argc==2){
        check=strstr(argv[1],".");
        if(check){
            batchMode(argv[1]);
        }
    }else
        write(STDERR_FILENO, error_message, strlen(error_message));
    return(0);
}

//Reads commands from user input
void interactiveMode(){
    size_t size=50;
    char *command;
    char exitCommand[6]="exit";

    if((command=(char *)malloc(size * sizeof(char)))==NULL){
        perror("malloc fail");
        exit(1);
    }
    while(strcmp(command,exitCommand)!=0){
        printf("wish> ");
        getline(&command,&size,stdin);     
       
        char ** parsedInput=parseInput(command);
        
        builtInCommands(parsedInput);
        executeCommands(parsedInput);

    }

    free(command);
    
    return;
}
// Reads commands from a file and executes them
void batchMode(char *file){
    char row[MAX], *command, *command2;
    char pathname[MAX]="/bin/";

    FILE *readFile;

    
    if((readFile=fopen(file,"r"))==NULL){
        perror("cannot open file");
        exit(1);
    }
    
    while(fgets(row,MAX,readFile)!= NULL){
        
        if((command=strtok(row," "))==NULL){
            printf("Strtok failed\n");
            exit(1);
        }
        if((command2=strtok(NULL,"\n"))==NULL){
            printf("strtok failed");
            exit(1);
        }
    }
    strcat(pathname,command);
    char *args[]={pathname,command2 ,"/home",NULL};
    execv(pathname,args);

    fclose(readFile);
    return;
}
//Parses user input
char **parseInput(char *command){
    int size=20;
    int length=0;
    char **parsedInputs;
    char error_message[30] = "An error has occurred\n";

    if((parsedInputs=(char **)malloc(size * sizeof(char)))==NULL){
        perror("malloc fail");
        exit(1);
    }
    if(!parsedInputs){
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
    char *separetors=" \t\r\n";
    char *parsedInput=strtok(command,separetors);

    while(parsedInput != NULL){
        parsedInputs[length]=parsedInput;
        length++;
        if(length >= size){
            size=(int)(size * 1.5);
            parsedInputs=realloc(parsedInputs,size*sizeof(char*));
            if(!parsedInputs){
                write(STDERR_FILENO, error_message, strlen(error_message));
            }
        }
        parsedInput=strtok(NULL,separetors);
    }
    parsedInputs[length]=NULL;

    return parsedInputs;
}
//Here is built in commands. User input is compared to built in commands if it is a built int command then it gets executed
int builtInCommands(char **command){
    char error_message[30] = "An error has occurred\n";
    char *buildExit="exit",*buildCd="cd",*buildPath="path";
    
    //Exits
    if(strcmp(buildExit,command[0])==0){
        free(command);
        exit(0);
    // Changes working directory
    }else if(strcmp(buildCd,command[0])==0){
        if(command[1]==NULL){
            write(STDERR_FILENO, error_message, strlen(error_message));        
        }else
            if(chdir(command[1])!=0){
                write(STDERR_FILENO, error_message, strlen(error_message));
            }
    }else if(strcmp(buildPath,command[0])==0){
        printf("Path Ei toimi.\n");
    }
    return 0;
}
// Executing commands that user has given. 
void executeCommands(char **command){
    char pathname[MAX]="/bin/";
    char error_message[30] = "An error has occurred\n";

    int rc=fork();
    if(rc < 0){
        write(STDERR_FILENO, error_message, strlen(error_message));
        exit(1);
    }else if(rc==0){
        strcat(pathname,command[0]);
        char *args[]={pathname,command[1] ,"/home",NULL};
        execv(pathname,args);          
    }else{
        wait(NULL);
        return;
    }
    
}  
//https://stackoverflow.com/questions/29686433/search-for-a-word-in-file-line-by-line-in-c-programming
// Tästä lähteestä on haettu apua kuinka etsitä haluttu sana tiedostosta. Rivi 72
//https://www.delftstack.com/howto/c/string-contains-in-c/
// Tästä lähteestä haettu apua kuinka selvittää onko argumentti "tiedosto" vaiko ei. Rivi 33

#define _GNU_SOURCE
#define MAX 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readAndPrint(char *, char *);
void printFile(char *);
void readStdinFile(char * ,char *);


int main(int argc, char* argv[]){
    char *check;
    char stdinFile[MAX]="stdinfile.txt";
    char buffer[MAX];
    FILE *readFile;

    if(argc==3){
        readAndPrint(argv[1],argv[2]);
    }
    else if(argc>3){
        printf("Too many arguments.\n");
    }

    //Checks if commandline argument is file or a word, if it's file then it reads the file.
    //if it's not a file then it reads stdin and creates a file.
    else if(argc==2){
        check=strstr(argv[1],".");
        
        if(check){
            printFile(argv[1]);
        }
        else{
            //Reads file from stdin and creates a new file were it stores all its content. 
            if((readFile=fopen(stdinFile,"w"))==NULL){
                perror("error opening file");
                exit(1);
            }
            while(fgets(buffer,MAX,stdin)!=NULL){
                fprintf(readFile,"%s",buffer);            
            }
            fclose(readFile);
            //Reads the created file
            readStdinFile(stdinFile,argv[1]);

        }    
    }
    else{ 
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    
    return(0);
}
// Reads all the lines from where searchable word appears
void readAndPrint(char *word, char *file){
    char *line=NULL;
    size_t len=0;
    ssize_t nread;
    FILE *readFile;

    if((readFile=fopen(file,"r"))==NULL){
        printf("wgrep: cannot open file\n");
        exit(1);
    }
    while((nread=getline(&line, &len, readFile))!= -1){
        if(strstr(line,word)!=NULL){
            printf("%s",line);
        }
    }
    
    free(line);
    fclose(readFile);
    return;
}

// Reads file if commandline argument only contains file
void printFile(char *file){
    FILE *readFile;
    char line[MAX];

    if((readFile=fopen(file,"r"))==NULL){
        printf("wgrep: cannot open file %s\n",file);
        exit(1);   
    }
    while(fgets(line,MAX,readFile)!=NULL){
        printf("%s",line);
    }
    fclose(readFile);
    printf("\n");
    return;
}

//Reads the created file from stdin
void readStdinFile(char *file,char *word){
    char *row=NULL;
    size_t llen=0;
    ssize_t read;
    FILE *stdinFile;
    
    word[strlen(word)-1]='\0';

    if((stdinFile=fopen(file,"r"))==NULL){
        printf("error opening file");
        exit(1);
    }
        
    while((read=getline(&row, &llen, stdinFile))!= -1){
        if(strstr(row,word)!=NULL){
            printf("%s",row);
        }
    }
    free(row);
    fclose(stdinFile);
    
    return;
}
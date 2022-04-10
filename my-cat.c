#include <stdio.h>
#include <stdlib.h>
#define MAX 500

void checkIfFileCanBeOpened(char *file);
void read(char *file);

int main(int argc, char* argv[]){
    int i;
    if(argc>1){
        if(argc==2){
           read(argv[1]);
        //Checks if user gives multiple arguments   
        }if(argc>2){
            //Now it checks if those arguments are files and can those be oppened.    
            for(i=1;i<argc;i++){
                checkIfFileCanBeOpened(argv[i]);
            }
        }
    }
    
    return (0);
}
// If user gives many files on command line, then checks if all of those can be oppened and then reads those files
void checkIfFileCanBeOpened(char *file){
    FILE *readFile;
    char row[MAX];
    if((readFile=fopen(file,"r"))==NULL){
        printf("wcat: cannot open file\n");
        exit(1);
    }
    while(fgets(row,MAX,readFile)!=NULL){
        printf("%s",row);
    }
    fclose(readFile);
    return;
}
// Reads files if user gives only two commandline parameters
void read(char* file){
    FILE *readFile;
    char row[MAX];

    if((readFile=fopen(file,"r"))==NULL){
        printf("wcat: cannot open file\n");
        exit(1);
    }
    while(fgets(row,MAX,readFile)!=NULL){
        printf("%s",row);
    }
    
    fclose(readFile);
    return;
}
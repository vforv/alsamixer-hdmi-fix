/* 
 * File:   main.c
 * Author: root
 *
 * Created on July 21, 2015, 11:16 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define TRUE  1
#define FALSE 0

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define RESET "\033[0m"
char createFile(char * filename,int device,int card);
/*
 * 
 */
int main(int argc, char **argv[]) {
    puts("-------------USAGE----------------");
    puts("TO CHECK YOUR DEVICE TYPE IN CONSOLE" KCYN " aplay -l" RESET);
    puts("TO START SCRIPT TYPE" KCYN " scriptname 0 3" RESET);
    puts(KYEL "FIRST ARGUMENT IS CARD NUMBER" RESET KMAG " SECOND ARGUMENT IS DEVICE NUMBER" RESET);
    puts("AFTER CHANGES OPEN AND CLOESE BROWSER");
    puts("-----------------------------");
    if(argc == 3){
    if(createFile("/root/.asoundrc",atoi(argv[2]),atoi(argv[1]))){
        printf(KGRN "[+] " RESET "CONFIGURATION FILE CREATED\n");
        printf(KBLU "CARD NUMBER: %d \n",atoi(argv[2]));
        printf("DEVICE NUMBER: %d \n" RESET,atoi(argv[1]));
    }else{
        puts(KRED "[-] " RESET "CONFIGURATION FILE NOT CREATED\n");
    }
    
    }else{
        printf(KRED "[-] " RESET "WRONG NUMBER OF ARGUMENTS\n");
    }
    
    return (EXIT_SUCCESS);
}


char createFile(char * filename,int device,int card){
        FILE * database;
        database = fopen(filename, "w");
        fprintf(database, "%s \n","pcm.!default {");
        fprintf(database, "%s \t \n","type hw");
        fprintf(database, "%s %d\t \n","card",card);
        fprintf(database, "%s %d\t \n","device",device);
        fprintf(database, "%s \n","}");
        fclose(database);
        return TRUE;
}


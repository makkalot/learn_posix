#include <stdio.h>
#include <stdlib.h>
#include "statls.h"
#include "errutils.h"

int main(int argc, char *argv[]){

    struct stat statbuf;
    int i,file_type;
    char permbuf[10],time_str[200]; 
    unsigned long hard_links; 
    char *user,*group;
    long int fsize;

    if(argc == 1)
        err_quit("Wrong number of arguments usage : %s file1 file2 ...",argv[0]);
    
    for(i=1;i<argc;i++){

        if(stat(argv[i],&statbuf) < 0){
           err_msg("Couldnt stat %s ",argv[i]);
           continue;
        }
        
        if((file_type = get_file_type(&statbuf)) < 0){
            err_msg("Couldnt get file type for : %s ",argv[i]);
            continue;
        }

        if(get_file_perms(&statbuf,permbuf) < 0){
            err_msg("Couldnt get file perms for : %s ",argv[i]);
            continue;
        }

        hard_links = get_file_hlinks(&statbuf);
        
        if(get_file_user(&statbuf,&user) < 0){
            err_msg("Couldnt get file owner for : %s ",argv[i]);
            continue;
        }

        if(get_file_group(&statbuf,&group) < 0){
            err_msg("Couldnt get file group for : %s ",argv[i]);
            continue;
        }
        
        fsize = get_file_size(&statbuf);
        
        if(get_file_mtime(&statbuf,time_str,sizeof(time_str)) < 0){
            err_msg("Couldnt get file mtime for : %s ",argv[i]);
            continue;
        }

        printf("%c%s % 5u % 10s % 10s % 5ld % 5s % 10s\n",file_type,permbuf,hard_links,user,group,fsize,time_str,argv[i]);
    
    }

    return 0;
}

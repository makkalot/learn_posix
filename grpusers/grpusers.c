#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <grp.h>

#include "errutils.h"

int main(int argc, char *argv[]){
    
    int i,j;
    struct group *group_info;

    if(argc == 1)
        err_quit("Wrong number of arguments usage : %s group1 group2 ...",argv[0]);
    
    for(i=1;i<argc;i++){

        if((group_info = getgrnam(argv[i])) == NULL){
            err_msg("The group does not exist : %s ",argv[i]);
            continue;
        }
        
        printf("Group %s : \n",argv[i]);
        
        j=0;
        while(group_info->gr_mem && group_info->gr_mem[j] != NULL){
            printf(" \t %s \n",group_info->gr_mem[j]);
            j++;
        }
        
        printf("\n\n");
    }

    return 0;
}

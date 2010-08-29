#include "statls.h"
#include <stdio.h>

/*************************************************
 *
 * Gets the type of the file 
 * @param statbuf : the stat structure to extract type
 * @return file type or -1 on error
 ************************************************/
int get_file_type(const struct stat *statbuf){
    
    switch(statbuf->st_mode & S_IFMT){
        case S_IFSOCK:
            return 's';
        
        case S_IFLNK:
            return 'l';

        case S_IFREG:
            return '-';

        case S_IFBLK:
            return 'b';

        case S_IFDIR:
            return 'd';

        case S_IFCHR:
            return 'c';

        case S_IFIFO:
            return 'f';

        default:
            return -1;
    }
    return 0;

}

/*************************************************
 *
 * Gets the perms of the file in rwx rwx rwx format
 * @param statbuf : the stat structure to extract perms
 * @return perms returned in perm_buf or -1 on error
 ************************************************/

int get_file_perms(const struct stat *statbuf,char *perm_buf){
    
    int i,j,perm_res;

    for(i = 0,j=0;i<3;i++){
        
        perm_res = (statbuf->st_mode & (PERM_MASK >> i*NUM_OF_BITS));
        
        if((perm_res & (PERM_READ >> i*NUM_OF_BITS))){
            perm_buf[j] = 'r';
        }
        else
            perm_buf[j] = '-';
        
        j++;

        if((perm_res & (PERM_WRITE >> i*NUM_OF_BITS))){
            perm_buf[j] = 'w';
        }
         else
            perm_buf[j] = '-';
        
        j++;

        if((perm_res & (PERM_EXEC >> i*NUM_OF_BITS))){
            perm_buf[j] = 'x';
        }
        else
            perm_buf[j] = '-';
        
        j++;

    }
    
    perm_buf[j] = '\0';
    
    return 0;

}


/*************************************************
 *
 * Gets the num of hard links for file
 * @param statbuf : the stat structure to extract perms
 * @return the num of hard links
 ************************************************/
unsigned long get_file_hlinks(const struct stat *statbuf){
    return (unsigned long)statbuf->st_nlink;
}

/*************************************************
 *
 * Gets the name of the file owner
 * @param statbuf : the stat structure to extract perms
 * @return the name in user or -1 on error
 ************************************************/

int get_file_user(const struct stat *statbuf,char **user){
    
    struct passwd *user_info;
    
    if((user_info = getpwuid(statbuf->st_uid)) == NULL)
        return -1;

    *user = user_info->pw_name;

    return 0;

}

/*************************************************
 *
 * Gets the group owner name of the file
 * @param statbuf : the stat structure to extract perms
 * @return name in **group on error -1 
 ************************************************/

int get_file_group(const struct stat *statbuf, char **group){
    
    struct group *group_info;

    if((group_info = getgrgid(statbuf->st_gid)) == NULL)
        return -1;

    *group = group_info->gr_name;

    return 0;

}

/*************************************************
 *
 * Gets the size in bytes of the file
 * @param statbuf : the stat structure to extract perms
 * @return size in bytes
 ************************************************/

long int get_file_size(const struct stat *statbuf){
    return (long int)statbuf->st_size;
}

/*************************************************
 *
 * Gets the modification time of file
 * @param statbuf : the stat structure to extract perms
 * @return the time as string in *mtime ,on error -1
 ************************************************/

int get_file_mtime(const struct stat *statbuf,char *mtime,unsigned int size){
    time_t t;
    struct tm *tmp;
    
    t = statbuf->st_mtime;
    tmp = localtime(&t);
    
    if (tmp == NULL) {
        return -1;
    }
    

    if (strftime(mtime,size,"%Y-%m-%d %H:%M", tmp) == 0) {
        return -1;
    }

    return 0;

}

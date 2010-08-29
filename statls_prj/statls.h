#ifndef __H__STATLS__
#define __H__STATLS__

#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define PERM_MASK S_IRWXU
#define PERM_READ S_IRUSR
#define PERM_WRITE S_IWUSR
#define PERM_EXEC S_IXUSR

#define NUM_OF_BITS 3

int get_file_type(const struct stat *statbuf);
int get_file_perms(const struct stat *statbuf,char *perm_buf);
unsigned long get_file_hlinks(const struct stat *statbuf);
int get_file_user(const struct stat *statbuf,char **user);
int get_file_group(const struct stat *statbuf, char **group);
long get_file_size(const struct stat *statbuf);
int get_file_mtime(const struct stat *statbuf,char *mtime,unsigned int size);

#endif

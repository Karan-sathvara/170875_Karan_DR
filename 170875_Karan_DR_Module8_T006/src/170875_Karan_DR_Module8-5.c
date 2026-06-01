/*
* File Name     : 170875_Karan_DR_Module8-5.c
* Description   : Modify the fsize program to print the other information contained in the inode entry.
* Author        : Karan Sathvara
* Created       : 29-04-2026
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

#define MAX_PATH 1024

void fsize(char *name);
void dirwalk(char *dir, void (*fp)(char *));

/*
* Function Name : fsize
* Description   : This function will check
*               : file exists or not
		: checks if it is directory then call recursively dirwalk to find subdirectory.
                : and prints the information contained in the inode entry.
* Author        : Karan Sathvara
* Created       : 29-04-2026
*/

void fsize(char *name)
{
    struct stat mData;

    if (stat(name, &mData) == -1) {
        printf("fsize : can't access %s\n", name);
        return;
    }

    if (S_ISDIR(mData.st_mode)) {
        dirwalk(name, fsize);
    }

    char perm[10];
    char type;

    type = S_ISDIR(mData.st_mode) ? 'd' : '-';

    perm[0] = (mData.st_mode & S_IRUSR) ? 'r' : '-';
    perm[1] = (mData.st_mode & S_IWUSR) ? 'w' : '-';
    perm[2] = (mData.st_mode & S_IXUSR) ? 'x' : '-';

    perm[3] = (mData.st_mode & S_IRGRP) ? 'r' : '-';
    perm[4] = (mData.st_mode & S_IWGRP) ? 'w' : '-';
    perm[5] = (mData.st_mode & S_IXGRP) ? 'x' : '-';

    perm[6] = (mData.st_mode & S_IROTH) ? 'r' : '-';
    perm[7] = (mData.st_mode & S_IWOTH) ? 'w' : '-';
    perm[8] = (mData.st_mode & S_IXOTH) ? 'x' : '-';

    perm[9] = '\0';

    printf("---------------------------------------\n");
    printf("Name        : %s\n", name);
    printf("Inode       : %ld\n", mData.st_ino);
    printf("Size        : %ld\n", mData.st_size);
    printf("Links       : %ld\n", mData.st_nlink);
    printf("UID         : %d\n", mData.st_uid);
    printf("GID         : %d\n", mData.st_gid);
    printf("Access Time : %s", ctime(&mData.st_atime));
    printf("Modify Time : %s", ctime(&mData.st_mtime));
    printf("Change Time : %s", ctime(&mData.st_ctime));
    printf("Permissions : %c%s\n", type,perm);
    printf("---------------------------------------\n");
    printf("\n");
}

/*
* Function Name : dirwalk
* Description   : This function will
*		: build path and recursively call fsize to print
* Author        : Karan Sathvara
* Created       : 29-04-2026
*/

void dirwalk(char *dir, void (*fp)(char *))
{
    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dFd;

    if ((dFd = opendir(dir)) == NULL) {
        printf("dirwalk : can't open %s\n", dir);
        return;
    }

    while ((dp = readdir(dFd)) != NULL) {

        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0){
            continue;
	}

        if (strlen(dir) + strlen(dp->d_name) + 2 > sizeof(name)){
            printf("dirwalk: dir/filename is too long\n");
	    return;
	}
        else {
            sprintf(name, "%s%s", dir, dp->d_name);
            (*fp)(name);
        }
    }
    closedir(dFd);
}

/*
* Function Name : modified_fsize
* Description   : This function will
*               : print all information contained inode entry
* Author        : Karan Sathvara
* Created       : 29-04-2026
*/

void modified_fsize(int8_t argc, char **argv)
{
    if (argc == 1){
        printf("No File/Dir name given\n");
    }
    else{
	for(int8_t idx = 1; idx < argc; idx++){
		fsize(argv[idx]);
	}
    }
}

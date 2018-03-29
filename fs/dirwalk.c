#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define MAX_PATH 512

void dirwalk(char *name)
{
   int ret;
   char buf[MAX_PATH];
   struct dirent *dp;
   DIR *dfd;
   struct stat stbuf;

   ret = stat(name, &stbuf);
   if (ret) {
      fprintf("failed to stat file/dir %s, exiting..\n", name);
   }

   /* end condition: not a directory, print name and return */
   if ((stbuf.st_mode & S_IFMT) != S_IFDIR) {
      printf("%s\n", name);
      return;
   }
   
   /* open the directory */
   dfd = opendir(name);
   if (dfd == NULL) {
      fprintf("failed to open %s\n", name);
   }

   /* walk the directory */
   while (dp = readdir(dfd)) {
      char *fname = dp->d_name;
      /* skip . and .. directories */
      if (strcmp(fname, ".") == 0 || strcmp(fname, "..") == 0) {
         continue;
      }
      if (strlen(fname) + strlen(name) + 2 > MAX_PATH) {
         fprintf("file name %s/%s too long", name, fname);
         continue;
      }
      sprintf(buf, "%s/%s", name, fname);
      printf("%s\n", buf);
      dirwalk(buf);
   }
}

int main(int argc, char **argv)
{
   if (argc != 2) {
      fprintf(stderr, "usage: ./a.out <path>\n");
   }

   printf("walking dir %s\n", *++argv);
   dirwalk(*argv);

   return 0;
}

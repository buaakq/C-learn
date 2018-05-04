#include <stdio.h>
#include <sys/types.h>
#include <regex.h>

#define MAX 128
char str[MAX];
int ret;

int check_ip(const char *str, int *valid)
{
   int ret = 0;
   regmatch_t match = {0};
   const char *pattern = "^([0-9]{1,3}\\.){3}[0-9]{1,3}$";
   //printf("reg pattern: %s\n", pattern);
   regex_t reg;
   *valid = 0;

   ret = regcomp(&reg, pattern, REG_EXTENDED | REG_NOSUB);
   if (ret) {
      printf("regcomp failed\n");
      return ret;
   }

   ret = regexec(&reg, str, 1, &match, 0);
   if (ret == 0) {
      *valid = 1;
   }

   return 0;
}

int main()
{
   int ret, valid;
   while(1) {
      printf("input an ip that you want to check: ");
      ret = scanf("%s", str);
      if (ret == EOF)
         break;
      printf("checking string %s\n", str);

      ret = check_ip(str, &valid);
      if (ret) {
         printf("failed to check this ip!\n");
         continue;
      }
      printf("%svalid ip: %s\n", valid ? "" : "in", str);
   }

   return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
void printHelper(int fileMode, int b, int c, char p) {
  if ((fileMode & b) && (fileMode & c))
    printf("%c",p);
  else
    printf("-");
}

void printPermissions(int fileMode) {
  printf("-");
  /* owner permissions */
  printHelper(fileMode, S_IRUSR, S_IREAD, 'r');
  printHelper(fileMode, S_IWUSR, S_IWRITE, 'w');
  printHelper(fileMode, S_IXUSR, S_IEXEC, 'x');
  /* group permissions */
  printHelper(fileMode, S_IRGRP, S_IREAD, 'r');
  printHelper(fileMode, S_IWGRP, S_IWRITE, 'w');
  printHelper(fileMode, S_IXGRP, S_IEXEC, 'x');
  /* other user permissions */
  printHelper(fileMode, S_IROTH, S_IREAD, 'r');
  printHelper(fileMode, S_IWOTH, S_IWRITE, 'w');
  printHelper(fileMode, S_IXOTH, S_IEXEC, 'x');
}

void statP(char * str) {
  struct stat * pter = malloc(sizeof(struct stat)); // allocate some memory
  stat(str, pter); // record metadata into pter
  // printing file info:
  printf("file: %s\n", str);
  long int size = pter -> st_size;
  if(size < 1000)
    printf("size: %ld B\n", size);
  else if (size < 1000000)
    printf("size: %ld.%ld KB\n", size/1000, size%1000);
  else if (size < 1000000000)
    printf("size: %ld.%ld MB\n", size/1000000, size%1000000);
  else
    printf("size: %ld.%ld GB\n", size/1000000000, size%1000000000);
  printf("mode(permissions): (%3o)\n", pter -> st_mode&0777);
  printPermissions(pter -> st_mode);
  char temp[100];
  strftime(temp, 100, "%c", localtime(&(pter -> st_atime)));
  printf("\ntime accessed: %s\n", temp);
  free(pter);
}




int main() {
  // printing results
  printf("_________________________\n");
  statP("temp.txt");
  printf("_________________________\n");
  statP("README.md");
  return 0;
}

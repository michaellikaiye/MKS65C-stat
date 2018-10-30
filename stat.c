/* file size */
/* mode (permissions) */
/* time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016 */
/* Note */
/* You may hardcode the file that your program uses, make sure the program works when I download and run it. */
/* If only there were some file that you know I will have and where it is... hmm... */
/* Once you have that, try the following: */
/* Modify the size so it is printed out in human readable form (that is using B, KB, MB, GB). */
/* You may want to look into the sprintf function to help. */
/* Attempt to print out the permissions in ls -l form, ignoring the early bits that include the file type information */
/* Permissions are of type mode_t, which is an integer type. */
/* The permissions section of the mode is stored in the last 9 bits of the mode_t data type. */

		     
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void statP(int fd) {
  struct stat x;
  int size = stat("lo.txt", x->st_size);
  printf("%d", size);
}


int main() {
  int fd = open("lo.txt",O_CREAT | O_WRONLY, 0777);
  int arr[10];
  int re = write(fd, arr, sizeof arr);
  close(fd);
  
  return 0;
}

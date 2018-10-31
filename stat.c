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

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

void statP(char * str) {
	struct stat * pter = malloc(sizeof(struct stat)); // allocate some memory
	stat(str, pter); // record metadata into pter

	// printing file info:
	printf("file: temp.txt\n");

	// read contents(just to practice reading)
	int straw = open("temp.txt", O_RDONLY);
	char arr[10];
	read(straw, arr, 10);
	close(straw);

	printf("contents: %s", arr);
	printf("size: %ld\n", pter -> st_size);
	printf("mode(permissions): %o\n", pter -> st_mode);
	char temp[100];
	strftime(temp, 100, "%c", localtime(& (pter -> st_atime)));
	printf("time accessed: %s\n", temp);
}

int main() {
	// int straw = open("teemp.txt", O_CREAT | O_RDWR, 0666);
	// int st[3];
	// st[0] = 1;
	// st[1] = 3;
	// st[2] = 5;
	// //   int i;
	// //   for
	// write(straw, st, sizeof(int));
	// close(straw);
	//
	// int * nums = malloc(4);
	// straw = open("teemp.txt", O_RDONLY);
	// read(straw, nums, 4);
	// close(straw);
	// printf("%d\n", * nums + 5);
	//   straw = open("temp.txt", O_RDONLY);
	//   statP(straw);

	// printing results
	printf("_________________________\n");
	statP("temp.txt");
	return 0;
}

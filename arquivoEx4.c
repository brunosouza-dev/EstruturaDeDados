#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declaring variables 
  FILE *archive;
  

  // Opening the 'txt' archive
  archive = fopen("output.txt", "w");
  
  // Verifying if archive is null
  if (archive == NULL) {
    printf("Error to open the archive");
    exit(1);
  }

  const char *message = "This is a example message.";
  fputs(message, archive);

  // Closing the archive
  fclose(archive);

  return 0;
}
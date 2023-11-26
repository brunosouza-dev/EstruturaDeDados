#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declaring variables 
  FILE *archive;
  int number = 125;
  char word[] = "This phrase will be recorded in archive.";

  // Opening the 'txt' archive
  archive = fopen("output.txt", "w");
  
  // Verifying if archive is null
  if (archive == NULL) {
    printf("Error to open the archive");
    exit(1);
  }

  // Opening and writing this print in the archive and then closing 
  fprintf(archive, "Number: %d Word: %s", number, word);
  fclose(archive);
  
  return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Declaring variables 
  FILE *archive;
  int number;
  char word[50];

  // Opening the 'txt' archive
  archive = fopen("archive.txt", "r");
  
  // Verifying if archive is null
  if (archive == NULL) {
    printf("Error to open the archive");
    exit(1);
  }

  // Reading and recording the read text into de variables and then closing
  fscanf(archive, "%d %s", &number, word);
  printf("Number %d\nWord: %s", number, word);
  fclose(archive);

  return 0;
}
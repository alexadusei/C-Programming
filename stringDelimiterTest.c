/* 
   DESCRIPTION: This program takes strings as its parameters and outputs a list of each
                word delimited by spaces, along with heap space info
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "StringDelimiter.h"

int countSpaces(char theString[]);
char** splitString(char theString[], int *arraySize);
void cleanup(char *words[], int numWords);

int countSpaces(char theString[]){
  int i = 0;
  int count = 0;

  while (theString[i] != '\0'){
    if (theString[i] == ' ')
      count++;
    i++;
  }

  return count;
}

char** splitString(char *theString, int *numWords){
  int j, k = 0, count = 0;
  int strLength = strlen(theString) + 1;
  *numWords = countSpaces(theString) + 1;
  char **wordArray = malloc(*numWords * sizeof(char *));

  for (j = 0; j < strLength; ){
    char *temp = malloc(strLength * sizeof(char *));
    while (theString[j] != ' ')
      temp[k++] = theString[j++];

    temp[k] = '\0';
    wordArray[count++] = temp;

    k = 0;
    j++;
  }  

  return wordArray;
}

void cleanup(char **words, int numWords){
  int i;

  for (i = 0; i < numWords; i++){
    free(words[i]);
  }

  free(words);
}

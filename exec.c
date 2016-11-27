#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(){
  char str[32];

 
  printf("Enter command: ");
  fgets(str, 32, stdin);
  printf("%s\n",str);

  char *s = str;
  char *command[32];
  int i = 0;

  s = strsep(&s,"\n");

  while (s) {
    command[i] = strsep(&s," ");
    i++;
  }
  command[i] = NULL;

  execvp(command[0],command);
  if (errno) {
    printf("Error");
  }

  return 0;
}
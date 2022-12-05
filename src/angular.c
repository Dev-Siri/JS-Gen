#include <stdio.h>
#include <stdlib.h>
#include "include/angular.h"

void angular(char project_name[255])
{
  char command[255];
  sprintf(command, "ng new %s", project_name);
  system("npm i -g @angular/cli");
  system(command);
  printf("Project created successfuly");
}
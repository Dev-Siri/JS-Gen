#include <stdio.h>
#include <stdlib.h>
#include "include/utils.h"

void install_dependencies(char project_name[PROJECT_NAME_LIMIT])
{
  char command[42];
  sprintf(command, "cd %s && npm i", project_name);
  
  printf("\e[0;34m\u2022\e[0m Installing Dependencies...\n");
  system(command);
  printf("\e[0;32m\u2713\e[0m Project Created Successfuly!");
}

void create_file(char path[100], const char* content)
{
  FILE* pFile = fopen(path, "w");

  fputs(content, pFile);

  fclose(pFile);
}
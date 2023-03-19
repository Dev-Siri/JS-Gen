#include <stdio.h>
#include <stdlib.h>
#include "include/generate.h"

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    generate(argv[2], argv[1]);
    exit(0);
  }

  char framework[10];
  char project_name[PROJECT_NAME_LIMIT];

  printf(
    "---------Javascript Project Generator---------\n"
    "\e[0;34m? \e[0mChoose your framework \e[0;37m>\e[0m\n"
    "\e[0;34m> React\n"
    "\e[0;31m> Angular\n"
    "\e[0;32m> Vue\n"
    "\e[0;91m> Svelte\n"
  );

  printf("\e[0;34m? \e[0mYour Choice \e[0;37m>\e[0m ");
  scanf("%s", framework);

  printf("\e[0;34m? \e[0mProject name \e[0;37m>\e[0m ");
  scanf("%s", project_name);

  generate(framework, project_name);
  return 0;
}
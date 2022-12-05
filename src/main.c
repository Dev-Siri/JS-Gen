#include <stdio.h>
#include <stdlib.h>
#include "include/main.h"
#include "include/generate.h"

int main(int argc, char *argv[])
{
  if (argc >= 3)
  {
    generate(argv[2], argv[1]);
    exit(0);
  }

  char framework[10];
  char project_name[255];

  printf("---------Javascript Project Generator---------\n");
  printf("Choose your framework:\n");
  printf("1. React\n");
  printf("2. Angular\n");
  printf("3. Vue\n");
  printf("4. Svelte\n");

  printf("Your choice: ");
  scanf("%s", framework);

  printf("Name of the project: ");
  scanf("%s", project_name);

  generate(framework, project_name);
  return 0;
}
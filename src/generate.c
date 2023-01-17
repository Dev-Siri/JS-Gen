#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/generate.h"

int str_to_int(char framework[10])
{
  if (!strcmp(framework, "react") ||!strcmp(framework, "React")) return 1;
  else if (!strcmp(framework, "angular") || !strcmp(framework, "Angular")) return 2;
  else if (!strcmp(framework, "vue") || !strcmp(framework, "Vue")) return 3;
  else if (!strcmp(framework, "svelte") || !strcmp(framework, "Svelte")) return 4;

  return 0;
}

void generate(char framework[10], char project_name[255])
{
  int framework_as_int = str_to_int(framework);

  switch (framework_as_int)
  {
    case 1:
      printf("Creating a %s project\n", framework);
      react(project_name);
      break;
    case 2:
      printf("Creating an %s project\n", framework);
      angular(project_name);
      break;
    case 3:
      printf("Creating a %s project\n", framework);
      vue(project_name);
      break;
    case 4:
      printf("Creating a %s project\n", framework);
      svelte(project_name);
      break;
    default:
      printf("\nInvalid framework");
  }
}
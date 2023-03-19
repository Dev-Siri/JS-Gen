#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/utils.h"
#include "include/react.h"
#include "include/angular.h"
#include "include/vue.h"
#include "include/svelte.h"
#include "include/generate.h"

static const struct {
  const char name[PROJECT_NAME_LIMIT];
  int value;
} framework_map[] = {
  { "react", REACT },
  { "React", REACT },
  { "angular", ANGULAR },
  { "Angular", ANGULAR },
  { "vue", VUE },
  { "Vue", VUE },
  { "svelte", SVELTE },
  { "Svelte", SVELTE }
};

int str_to_framework(char framework[10])
{
  const int len = sizeof(framework_map) / sizeof(*framework_map);

  for (int i = 0; i < len; i++) {
    if (!strcmp(framework, framework_map[i].name)) return framework_map[i].value;
  }

  return -1;
}

void generate(char framework[10], char project_name[PROJECT_NAME_LIMIT])
{
  int framework_as_int = str_to_framework(framework);

  printf("\e[0;34m\u2022\e[0m Creating a %s project\n", framework);
  
  switch (framework_as_int)
  {
    case REACT:
      react(project_name);
      break;
    case ANGULAR:
      angular(project_name);
      break;
    case VUE:
      vue(project_name);
      break;
    case SVELTE:
      svelte(project_name);
      break;
    default:
      printf("\n\u274c Invalid framework.\n");
      exit(1);
  }

  install_dependencies(project_name);
}
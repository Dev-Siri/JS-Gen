#ifndef GENERATE_H
#define GENERATE_H
#define PROJECT_NAME_LIMIT 30

typedef enum
{
  REACT,
  ANGULAR,
  VUE,
  SVELTE,
} Framework;

void generate(char framework[10], char project_name[PROJECT_NAME_LIMIT]);

int str_to_framework(char framework[10]);
#endif
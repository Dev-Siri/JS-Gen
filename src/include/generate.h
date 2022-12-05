#define GENERATE_H
#include "react.h"
#include "angular.h"
#include "vue.h"
#include "svelte.h"

void generate(char framework[10], char project_name[255]);

int str_to_int(char framework[10]);
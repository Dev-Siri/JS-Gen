#ifndef UTILS_H
#define UTILS_H
#include "generate.h"

void install_dependencies(char project_name[PROJECT_NAME_LIMIT]);
void create_file(char path[100], const char* content);
#endif
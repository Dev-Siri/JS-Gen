#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include "include/vue.h"

void vue(char project_name[255])
{
  char public_folder_path[255];
  char vscode_folder_path[255];
  char src_folder_path[255];

  sprintf(public_folder_path, "%s/public", project_name);
  sprintf(vscode_folder_path, "%s/.vscode", project_name);
  sprintf(src_folder_path, "%s/src", project_name);

  _mkdir(project_name);
  _mkdir(public_folder_path);
  _mkdir(vscode_folder_path);
  _mkdir(src_folder_path);

  FILE* files[7];
  for (unsigned int i = 0; i < 7; i++)
  {
    switch (i)
    {
      case 0: {
        char html[387];
        char html_path[255];
        sprintf(html_path, "%s/index.html", project_name);

        files[i] = fopen(html_path, "w");
        sprintf(html, "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\" />\n    <link rel=\"icon\" href=\"#\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n    <title>%s</title>\n  </head>\n  <body>\n    <div id=\"app\"></div>\n    <script type=\"module\" src=\"/src/main.js\"></script>\n  </body>\n</html>", project_name);
        fprintf(files[i], html);
        fclose(files[i]);
        break;
      }
      case 1: {
        const char extensions[3073] = "{\n  \"recommendations\": [\"Vue.volar\", \"Vue.vscode-typescript-vue-plugin\"]\n}";
        char extensions_path[255];

        sprintf(extensions_path, "%s/extensions.json", vscode_folder_path);
        files[i] = fopen(extensions_path, "w");
        fprintf(files[i], extensions);
        fclose(files[i]);
        break;
      }
      case 2: {
        char package_json[600];
        char package_json_path[255];
        sprintf(package_json_path, "%s/package.json", project_name);

        files[i] = fopen(package_json_path, "w");
        sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"1.0.0\",\n  \"private\": true,\n  \"scripts\": {\n    \"dev\": \"vite\",\n    \"build\": \"vite build\",\n    \"preview\": \"vite preview\"\n  },\n  \"dependencies\": {\n    \"vue\": \"^3.2.45\"\n  },\n  \"devDependencies\": {\n    \"@vitejs/plugin-vue\": \"^3.2.0\",\n    \"vite\": \"^3.2.4\"\n  }\n}", project_name);
        fprintf(files[i], package_json);
        fclose(files[i]);
        break;
      }
      case 3: {
        const char vite_config[] = "import { fileURLToPath, URL } from 'node:url';\n\nimport { defineConfig } from 'vite';\nimport vue from '@vitejs/plugin-vue';\n\nexport default defineConfig({\n  plugins: [vue()],\n  resolve: {\n    alias: {\n      '@': fileURLToPath(new URL('./src', import.meta.url)),\n    },\n  },\n});";
        char vite_config_path[255];
        sprintf(vite_config_path, "%s/vite.config.js", project_name);

        files[i] = fopen(vite_config_path, "w");
        fprintf(files[i], vite_config);
        fclose(files[i]);
        break;
      }
      case 4: {
        const char main_js[] = "import { createApp } from 'vue';\nimport App from './App.vue';\n\nconst app = createApp(App);\napp.mount('#app');";
        char main_js_path[255];
        sprintf(main_js_path, "%s/main.js", src_folder_path);

        files[i] = fopen(main_js_path, "w");
        fprintf(files[i], main_js);
        fclose(files[i]);
        break;
      }
      case 5: {
        const char app_vue[] = "<script>\n  // JavaScript here\n</script>\n\n<template>\n  <h1>Hello, World!</h1>\n</template>\n\n<style scoped>\n  /* CSS here */\n</style>";
        char app_vue_path[255];
        sprintf(app_vue_path, "%s/App.vue", src_folder_path);

        files[i] = fopen(app_vue_path, "w");
        fprintf(files[i], app_vue);
        fclose(files[i]);
        break;
      }
      case 6: {
        const char gitignore[] = "logs\n*.log\nnpm-debug.log*\nyarn-debug.log*\nyarn-error.log*\npnpm-debug.log*\nlerna-debug.log*\n\nnode_modules\n.DS_Store\ndist\ndist-ssr\ncoverage\n*.local\n\n/cypress/videos/\n/cypress/screenshots/\n\n.vscode/*\n!.vscode/extensions.json\n.idea\n*.suo\n*.ntvs*\n*.njsproj\n*.sln\n*.sw?";
        char gitignore_path[255];
        sprintf(gitignore_path, "%s/.gitignore", project_name);

        files[i] = fopen(gitignore_path, "w");
        fprintf(files[i], gitignore);
        fclose(files[i]);
        break;
      }
    }
  }

  printf("Installing dependencies...");
  char command[255];
  sprintf(command, "cd %s && npm i", project_name);
  system(command);
  printf("Project created successfuly!");
}
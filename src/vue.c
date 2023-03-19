#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "include/vue.h"
#include "include/utils.h"

void vue(char project_name[PROJECT_NAME_LIMIT])
{
  char vscode_folder_path[39];
  char src_folder_path[35];

  sprintf(vscode_folder_path, "%s/.vscode", project_name);
  sprintf(src_folder_path, "%s/src", project_name);

  mkdir(project_name, S_IRWXU);
  mkdir(vscode_folder_path, S_IRWXU);
  mkdir(src_folder_path, S_IRWXU);

  const char html[] = "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\" />\n    <link rel=\"icon\" href=\"#\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" />\n    <title>Vue App</title>\n  </head>\n  <body>\n    <div id=\"app\"></div>\n    <script type=\"module\" src=\"/src/main.js\"></script>\n  </body>\n</html>";
  char html_path[42];
  sprintf(html_path, "%s/index.html", project_name);
  create_file(html_path, html);

  const char extensions[] = "{\n  \"recommendations\": [\"Vue.volar\", \"Vue.vscode-typescript-vue-plugin\"]\n}";
  char extensions_path[56];
  sprintf(extensions_path, "%s/extensions.json", vscode_folder_path);
  create_file(extensions_path, extensions);

  char package_json[315];
  char package_json_path[44];
  sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"1.0.0\",\n  \"private\": true,\n  \"scripts\": {\n    \"dev\": \"vite\",\n    \"build\": \"vite build\",\n    \"preview\": \"vite preview\"\n  },\n  \"dependencies\": {\n    \"vue\": \"^3.2.45\"\n  },\n  \"devDependencies\": {\n    \"@vitejs/plugin-vue\": \"^3.2.0\",\n    \"vite\": \"^3.2.4\"\n  }\n}", project_name);
  sprintf(package_json_path, "%s/package.json", project_name);
  create_file(package_json_path, package_json);

  const char vite_config[] = "import { fileURLToPath, URL } from 'node:url';\n\nimport { defineConfig } from 'vite';\nimport vue from '@vitejs/plugin-vue';\n\nexport default defineConfig({\n  plugins: [vue()],\n  resolve: {\n    alias: {\n      '@': fileURLToPath(new URL('./src', import.meta.url)),\n    },\n  },\n});";
  char vite_config_path[46];
  sprintf(vite_config_path, "%s/vite.config.js", project_name);
  create_file(vite_config_path, vite_config);

  const char main_js[] = "import { createApp } from 'vue';\nimport App from './App.vue';\n\nconst app = createApp(App);\napp.mount('#app');";
  char main_js_path[44];
  sprintf(main_js_path, "%s/main.js", src_folder_path);
  create_file(main_js_path, main_js);
  
  const char app_vue[] = "<script>\n  // JavaScript here\n</script>\n\n<template>\n  <h1>Hello, World!</h1>\n</template>\n\n<style scoped>\n  /* CSS here */\n</style>";
  char app_vue_path[44];
  sprintf(app_vue_path, "%s/App.vue", src_folder_path);
  create_file(app_vue_path, app_vue);
  
  const char gitignore[] = "logs\n*.log\nnpm-debug.log*\nyarn-debug.log*\nyarn-error.log*\npnpm-debug.log*\nlerna-debug.log*\n\nnode_modules\n.DS_Store\ndist\ndist-ssr\ncoverage\n*.local\n\n/cypress/videos/\n/cypress/screenshots/\n\n.vscode/*\n!.vscode/extensions.json\n.idea\n*.suo\n*.ntvs*\n*.njsproj\n*.sln\n*.sw?";
  char gitignore_path[44];
  sprintf(gitignore_path, "%s/.gitignore", project_name);
  create_file(gitignore_path, gitignore);
}
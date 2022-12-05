#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include "include/react.h"

void react(char project_name[255])
{
  char public_folder_path[255];
  char src_folder_path[255];

  sprintf(public_folder_path, "%s/public", project_name);
  sprintf(src_folder_path, "%s/src", project_name);

  _mkdir(project_name);
  _mkdir(public_folder_path);
  _mkdir(src_folder_path);

  FILE* files[6];
  for (unsigned int i = 0; i < 6; i++)
  {
    switch (i)
    {
      case 0: {
        char html[600];
        char html_path[255];
        sprintf(html_path, "%s/index.html", public_folder_path);

        files[i] = fopen(html_path, "w");
        sprintf(html, "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\" />\n    <link rel=\"icon\" href=\"%%PUBLIC_URL%%/favicon.ico\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />\n    <meta name=\"theme-color\" content=\"#000000\" />\n    <meta name=\"description\" content=\"Website description\" />\n    <title>%s</title>\n  </head>\n  <body>\n    <noscript>You need to enable JavaScript to run this app.</noscript>\n    <div id=\"root\"></div>\n  </body>\n</html>", project_name);
        fprintf(files[i], html);
        fclose(files[i]);
        break;
      }
      case 1: {
        char package_json[800];
        char package_json_path[255];
        sprintf(package_json_path, "%s/package.json", project_name);

        files[i] = fopen(package_json_path, "w");
        sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"1.0.0\",\n  \"private\": true,\n  \"scripts\": {\n    \"start\": \"react-scripts start\",\n    \"build\": \"react-scripts build\"\n  },\n  \"dependencies\": {\n    \"react\": \"^18.2.0\",\n    \"react-dom\": \"^18.2.0\",\n    \"react-scripts\": \"5.0.1\"\n  },\n  \"browserslist\": {\n    \"production\": [\n      \">0.2%%\",\n      \"not dead\",\n      \"not op_mini all\",\n      \"not IE 11\"\n    ],\n    \"development\": [\n      \"last 1 chrome version\",\n      \"last 1 firefox version\",\n      \"last 1 safari version\"\n    ]\n  }\n}", project_name);
        fprintf(files[i], package_json);
        fclose(files[i]);
        break;
      }
      case 2: {
        const char robots_txt[] = "# https://www.robotstxt.org/robotstxt.html\nUser-agent: *\nDisallow:";
        char robots_txt_path[255];
        sprintf(robots_txt_path, "%s/robots.txt", public_folder_path);

        files[i] = fopen(robots_txt_path, "w");
        fprintf(files[i], robots_txt);
        fclose(files[i]);
        break;
      }
      case 3: {
        const char index_js[] = "import React from 'react';\nimport { createRoot } from 'react-dom/client';\n\nimport App from './App';\n\nconst root = createRoot(document.getElementById('root'));\nroot.render(\n  <React.StrictMode>\n    <App />\n  </React.StrictMode>\n);";
        char index_js_path[255];
        sprintf(index_js_path, "%s/index.js", src_folder_path);

        files[i] = fopen(index_js_path, "w");
        fprintf(files[i], index_js);
        fclose(files[i]);
        break;
      }
      case 4: {
        const char app_jsx[] = "import React from 'react';\n\nconst App = () => {\n  return (\n    <div>\n      <h1>Hello, World!</h1>\n    </div>\n  );\n}\n\nexport default App;";
        char app_jsx_path[255];
        sprintf(app_jsx_path, "%s/App.jsx", src_folder_path);

        files[i] = fopen(app_jsx_path, "w");
        fprintf(files[i], app_jsx);
        fclose(files[i]);
        break;
      }
      case 5: {
        const char gitignore[] = "/node_modules\n/.pnp\n.pnp.js\n\n/coverage\n\n/build\n\n.DS_Store\n.env.local\n.env.development.local\n.env.test.local\n.env.production.local\n\nnpm-debug.log*\nyarn-debug.log*\nyarn-error.log*";
        char gitignore_path[255];
        sprintf(gitignore_path, "%s/.gitignore", project_name);

        files[i] = fopen(gitignore_path, "w");
        fprintf(files[i], gitignore);
        fclose(files[i]);
        break;
      }
    }
  }
  
  char command[255];
  sprintf(command, "cd %s && npm i", project_name);
  system(command);
  printf("\nProject created successfully!");
}
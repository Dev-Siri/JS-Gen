#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "include/utils.h"
#include "include/react.h"

void react(char project_name[PROJECT_NAME_LIMIT])
{
  char public_folder_path[38];
  char src_folder_path[35];

  sprintf(public_folder_path, "%s/public", project_name);
  sprintf(src_folder_path, "%s/src", project_name);

  mkdir(project_name, S_IRWXU);
  mkdir(public_folder_path, S_IRWXU);
  mkdir(src_folder_path, S_IRWXU);

  const char html[] = "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\" />\n    <link rel=\"icon\" href=\"%%PUBLIC_URL%%/favicon.ico\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />\n    <meta name=\"theme-color\" content=\"#000000\" />\n    <meta name=\"description\" content=\"Website description\" />\n    <title>React App</title>\n  </head>\n  <body>\n    <noscript>You need to enable JavaScript to run this app.</noscript>\n    <div id=\"root\"></div>\n  </body>\n</html>";
  char html_path[50];
  sprintf(html_path, "%s/index.html", public_folder_path);
  create_file(html_path, html);

  char package_json[534];
  char package_json_path[44];
  sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"1.0.0\",\n  \"private\": true,\n  \"scripts\": {\n    \"start\": \"react-scripts start\",\n    \"build\": \"react-scripts build\"\n  },\n  \"dependencies\": {\n    \"react\": \"^18.2.0\",\n    \"react-dom\": \"^18.2.0\",\n    \"react-scripts\": \"5.0.1\"\n  },\n  \"browserslist\": {\n    \"production\": [\n      \">0.2%%\",\n      \"not dead\",\n      \"not op_mini all\",\n      \"not IE 11\"\n    ],\n    \"development\": [\n      \"last 1 chrome version\",\n      \"last 1 firefox version\",\n      \"last 1 safari version\"\n    ]\n  }\n}", project_name);
  sprintf(package_json_path, "%s/package.json", project_name);
  create_file(package_json_path, package_json);
  
  const char robots_txt[] = "# https://www.robotstxt.org/robotstxt.html\nUser-agent: *\nDisallow:";
  char robots_txt_path[50];
  sprintf(robots_txt_path, "%s/robots.txt", public_folder_path);
  create_file(robots_txt_path, robots_txt);

  const char index_js[] = "import React from 'react';\nimport { createRoot } from 'react-dom/client';\n\nimport App from './App';\n\nconst root = createRoot(document.getElementById('root'));\nroot.render(\n  <React.StrictMode>\n    <App />\n  </React.StrictMode>\n);";
  char index_js_path[45];
  sprintf(index_js_path, "%s/index.js", src_folder_path);
  create_file(index_js_path, index_js);
  
  const char app_jsx[] = "import React from 'react';\n\nconst App = () => {\n  return (\n    <div>\n      <h1>Hello, World!</h1>\n    </div>\n  );\n}\n\nexport default App;";
  char app_jsx_path[44];
  sprintf(app_jsx_path, "%s/App.jsx", src_folder_path);
  create_file(app_jsx_path, app_jsx);
  
  const char gitignore[] = "/node_modules\n/.pnp\n.pnp.js\n\n/coverage\n\n/build\n\n.DS_Store\n.env.local\n.env.development.local\n.env.test.local\n.env.production.local\n\nnpm-debug.log*\nyarn-debug.log*\nyarn-error.log*";
  char gitignore_path[42];
  sprintf(gitignore_path, "%s/.gitignore", project_name);
  create_file(gitignore_path, gitignore);
}
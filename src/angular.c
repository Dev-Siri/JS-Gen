#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "include/utils.h"
#include "include/angular.h"

void angular(char project_name[PROJECT_NAME_LIMIT])
{
  char dot_vscode_path[38];
  char src_folder_path[35];
  char app_folder_path[40];

  sprintf(dot_vscode_path, "%s/.vscode", project_name);
  sprintf(src_folder_path, "%s/src", project_name);
  sprintf(app_folder_path, "%s/app", src_folder_path);

  mkdir(project_name, S_IRWXU);
  mkdir(dot_vscode_path, S_IRWXU);
  mkdir(src_folder_path, S_IRWXU);
  mkdir(app_folder_path, S_IRWXU);

  const char tsconfig_app_json[] = "{\n  \"extends\": \"./tsconfig.json\",\n  \"compilerOptions\": {\n    \"outDir\": \"./out-tsc/app\",\n    \"types\": []\n  },\n  \"files\": [\n    \"src/main.ts\"\n  ],\n  \"include\": [\n    \"src/**/*.d.ts\"\n  ]\n}";
  char tsconfig_app_json_path[49];
  sprintf(tsconfig_app_json_path, "%s/tsconfig.app.json", project_name);
  create_file(tsconfig_app_json_path, tsconfig_app_json);

  const char tsconfig_json[] = "{\n  \"compileOnSave\": false,\n  \"compilerOptions\": {\n    \"baseUrl\": \"./\",\n    \"outDir\": \"./dist/out-tsc\",\n    \"forceConsistentCasingInFileNames\": true,\n    \"strict\": true,\n    \"noImplicitOverride\": true,\n    \"noPropertyAccessFromIndexSignature\": true,\n    \"noImplicitReturns\": true,\n    \"noFallthroughCasesInSwitch\": true,\n    \"sourceMap\": true,\n    \"declaration\": false,\n    \"downlevelIteration\": true,\n    \"experimentalDecorators\": true,\n    \"moduleResolution\": \"node\",\n    \"importHelpers\": true,\n    \"target\": \"ES2022\",\n    \"module\": \"ES2022\",\n    \"useDefineForClassFields\": false,\n    \"lib\": [\n      \"ES2022\",\n      \"dom\"\n    ]\n  },\n  \"angularCompilerOptions\": {\n    \"enableI18nLegacyMessageIdFormat\": false,\n    \"strictInjectionParameters\": true,\n    \"strictInputAccessModifiers\": true,\n    \"strictTemplates\": true\n  }\n}";
  char tsconfig_json_path[45];
  sprintf(tsconfig_json_path, "%s/tsconfig.json", project_name);
  create_file(tsconfig_json_path, tsconfig_json);

  const char tsconfig_spec_json[] = "{\n  \"extends\": \"./tsconfig.json\",\n  \"compilerOptions\": {\n    \"outDir\": \"./out-tsc/spec\",\n    \"types\": [\n      \"jasmine\"\n    ]\n  },\n  \"include\": [\n    \"src/**/*.spec.ts\",\n    \"src/**/*.d.ts\"\n  ]\n}";
  char tsconfig_spec_json_path[50];
  sprintf(tsconfig_spec_json_path, "%s/tsconfig.spec.json", project_name);
  create_file(tsconfig_spec_json_path, tsconfig_spec_json);

  char package_json[1061];
  char package_json_path[44];
  sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"0.0.0\",\n  \"scripts\": {\n    \"ng\": \"ng\",\n    \"start\": \"ng serve\",\n    \"build\": \"ng build\",\n    \"watch\": \"ng build --watch --configuration development\",\n    \"test\": \"ng test\"\n  },\n  \"private\": true,\n  \"dependencies\": {\n    \"@angular/animations\": \"^15.1.0\",\n    \"@angular/common\": \"^15.1.0\",\n    \"@angular/compiler\": \"^15.1.0\",\n    \"@angular/core\": \"^15.1.0\",\n    \"@angular/forms\": \"^15.1.0\",\n    \"@angular/platform-browser\": \"^15.1.0\",\n    \"@angular/platform-browser-dynamic\": \"^15.1.0\",\n    \"@angular/router\": \"^15.1.0\",\n    \"rxjs\": \"~7.8.0\",\n    \"tslib\": \"^2.3.0\",\n    \"zone.js\": \"~0.12.0\"\n  },\n  \"devDependencies\": {\n    \"@angular-devkit/build-angular\": \"^15.1.1\",\n    \"@angular/cli\": \"~15.1.1\",\n    \"@angular/compiler-cli\": \"^15.1.0\",\n    \"@types/jasmine\": \"~4.3.0\",\n    \"jasmine-core\": \"~4.5.0\",\n    \"karma\": \"~6.4.0\",\n    \"karma-chrome-launcher\": \"~3.1.0\",\n    \"karma-coverage\": \"~2.2.0\",\n    \"karma-jasmine\": \"~5.1.0\",\n    \"karma-jasmine-html-reporter\": \"~2.0.0\",\n    \"typescript\": \"~4.9.4\"\n  }\n}", project_name);
  sprintf(package_json_path, "%s/package.json", project_name);
  
  const char index_html[] = "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"UTF-8\">\n    <title>Angular App</title>\n    <base href=\"/\" />\n    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\" />\n    <link rel=\"icon\" href=\"#\" />\n  </head>\n  <body>\n    <app-root></app-root>\n  </body>\n</html>";
  char index_html_path[46];
  sprintf(index_html_path, "%s/index.html", src_folder_path);
  create_file(index_html_path, index_html);

  const char main_ts[] = "import { platformBrowserDynamic } from '@angular/platform-browser-dynamic';\n\nimport { AppModule } from './app/app.module';\n\nplatformBrowserDynamic().bootstrapModule(AppModule)\n  .catch(error => console.error(error));";
  char main_ts_path[43];
  sprintf(main_ts_path, "%s/main.ts", src_folder_path);
  create_file(main_ts_path, main_ts);
      
  const char styles_sass[] = "// Add your styles here!";
  char styles_sass_path[47];
  sprintf(styles_sass_path, "%s/styles.sass", src_folder_path);
  create_file(styles_sass_path, styles_sass);;

  const char gitignore[] = "/dist\n/tmp\n/out-tsc\n/bazel-out\n\n/node_modules\nnpm-debug.log\nyarn-error.log\n\n.idea/\n.project\n.classpath\n.c9/\n*.launch\n.settings/\n*.sublime-workspace\n\n.vscode/*\n!.vscode/settings.json\n!.vscode/tasks.json\n!.vscode/launch.json\n!.vscode/extensions.json\n.history/*\n\n/.angular/cache\n.sass-cache/\n/connect.lock\n/coverage\n/libpeerconnection.log\ntestem.log\n/typings\n\n.DS_Store\nThumbs.db";
  char gitignore_path[42];
  sprintf(gitignore_path, "%s/.gitignore", project_name);
  create_file(gitignore_path, gitignore);

  const char dot_editorconfig[] = "root = true\n\n[*]\ncharset = utf-8\nindent_style = space\nindent_size = 2\ninsert_final_newline = true\ntrim_trailing_whitespace = true\n\n[*.ts]\nquote_type = single\n\n[*.md]\nmax_line_length = off\ntrim_trailing_whitespace = false";
  char dot_editorconfig_path[45];
  sprintf(dot_editorconfig_path, "%s/.editorconfig", project_name);
  create_file(dot_editorconfig_path, dot_editorconfig);

  const char angular_json[] = "{\n  \"$schema\": \"./node_modules/@angular/cli/lib/config/schema.json\",\n  \"version\": 1,\n  \"newProjectRoot\": \"projects\",\n  \"projects\": {\n    \"app\": {\n      \"projectType\": \"application\",\n      \"schematics\": {\n        \"@schematics/angular:component\": {\n          \"style\": \"sass\"\n        }\n      },\n      \"root\": \"\",\n      \"sourceRoot\": \"src\",\n      \"prefix\": \"app\",\n      \"architect\": {\n        \"build\": {\n          \"builder\": \"@angular-devkit/build-angular:browser\",\n          \"options\": {\n            \"outputPath\": \"dist/app\",\n            \"index\": \"src/index.html\",\n            \"main\": \"src/main.ts\",\n            \"polyfills\": [\n              \"zone.js\"\n            ],\n            \"tsConfig\": \"tsconfig.app.json\",\n            \"inlineStyleLanguage\": \"sass\",\n            \"assets\": [\n              \"src/favicon.ico\",\n              \"src/assets\"\n            ],\n            \"styles\": [\n              \"src/styles.sass\"\n            ],\n            \"scripts\": []\n          },\n          \"configurations\": {\n            \"production\": {\n              \"budgets\": [\n                {\n                  \"type\": \"initial\",\n                  \"maximumWarning\": \"500kb\",\n                  \"maximumError\": \"1mb\"\n                },\n                {\n                  \"type\": \"anyComponentStyle\",\n                  \"maximumWarning\": \"2kb\",\n                  \"maximumError\": \"4kb\"\n                }\n              ],\n              \"outputHashing\": \"all\"\n            },\n            \"development\": {\n              \"buildOptimizer\": false,\n              \"optimization\": false,\n              \"vendorChunk\": true,\n              \"extractLicenses\": false,\n              \"sourceMap\": true,\n              \"namedChunks\": true\n            }\n          },\n          \"defaultConfiguration\": \"production\"\n        },\n        \"serve\": {\n          \"builder\": \"@angular-devkit/build-angular:dev-server\",\n          \"configurations\": {\n            \"production\": {\n              \"browserTarget\": \"app:build:production\"\n            },\n            \"development\": {\n              \"browserTarget\": \"app:build:development\"\n            }\n          },\n          \"defaultConfiguration\": \"development\"\n        },\n        \"extract-i18n\": {\n          \"builder\": \"@angular-devkit/build-angular:extract-i18n\",\n          \"options\": {\n            \"browserTarget\": \"app:build\"\n          }\n        },\n        \"test\": {\n          \"builder\": \"@angular-devkit/build-angular:karma\",\n          \"options\": {\n            \"polyfills\": [\n              \"zone.js\",\n              \"zone.js/testing\"\n            ],\n            \"tsConfig\": \"tsconfig.spec.json\",\n            \"inlineStyleLanguage\": \"sass\",\n            \"assets\": [\n              \"src/favicon.ico\",\n              \"src/assets\"\n            ],\n            \"styles\": [\n              \"src/styles.sass\"\n            ],\n            \"scripts\": []\n          }\n        }\n      }\n    }\n  }\n}";
  char angular_json_path[44];
  sprintf(angular_json_path, "%s/angular.json", project_name);
  create_file(angular_json_path, angular_json);

  const char extensions_json[] = "{\n  \"recommendations\": [\"angular.ng-template\"]\n}";
  char extensions_json_path[55];
  sprintf(extensions_json_path, "%s/extensions.json", dot_vscode_path);
  create_file(extensions_json_path, extensions_json);

  const char launch_json[] = "{\n  \"version\": \"0.2.0\",\n  \"configurations\": [\n    {\n      \"name\": \"ng serve\",\n      \"type\": \"pwa-chrome\",\n      \"request\": \"launch\",\n      \"preLaunchTask\": \"npm: start\",\n      \"url\": \"http://localhost:4200/\"\n    },\n    {\n      \"name\": \"ng test\",\n      \"type\": \"chrome\",\n      \"request\": \"launch\",\n      \"preLaunchTask\": \"npm: test\",\n      \"url\": \"http://localhost:9876/debug.html\"\n    }\n  ]\n}";
  char launch_json_path[51];
  sprintf(launch_json_path, "%s/launch.json", dot_vscode_path);
  create_file(launch_json_path, launch_json);
  
  const char tasks_json[] = "{\n  \"version\": \"2.0.0\",\n  \"tasks\": [\n    {\n      \"type\": \"npm\",\n      \"script\": \"start\",\n      \"isBackground\": true,\n      \"problemMatcher\": {\n        \"owner\": \"typescript\",\n        \"pattern\": \"$tsc\",\n        \"background\": {\n          \"activeOnStart\": true,\n          \"beginsPattern\": {\n            \"regexp\": \"(.*?)\"\n          },\n          \"endsPattern\": {\n            \"regexp\": \"bundle generation complete\"\n          }\n        }\n      }\n    },\n    {\n      \"type\": \"npm\",\n      \"script\": \"test\",\n      \"isBackground\": true,\n      \"problemMatcher\": {\n        \"owner\": \"typescript\",\n        \"pattern\": \"$tsc\",\n        \"background\": {\n          \"activeOnStart\": true,\n          \"beginsPattern\": {\n            \"regexp\": \"(.*?)\"\n          },\n          \"endsPattern\": {\n            \"regexp\": \"bundle generation complete\"\n          }\n        }\n      }\n    }\n  ]\n}";
  char tasks_json_path[50];
  sprintf(tasks_json_path, "%s/tasks.json", dot_vscode_path);
  create_file(tasks_json_path, tasks_json);

  const char app_component_html[] = "<h1>Hello, World!</h1>\n<router-outlet></router-outlet>";
  char app_component_html_path[60];
  sprintf(app_component_html_path, "%s/app.component.html", app_folder_path);
  create_file(app_component_html_path, app_component_html);
  
  const char app_component_sass[] = "body {\n  margin: 0;\n  padding: 0;\n  box-sizing: border-box;\n}";
  char app_component_sass_path[60];
  sprintf(app_component_sass_path, "%s/app.component.sass", app_folder_path);
  create_file(app_component_sass_path, app_component_sass);
  
  const char app_routing_module_ts[] = "import { NgModule } from '@angular/core';\nimport { RouterModule, Routes } from '@angular/router';\n\nconst routes: Routes = [];\n\n@NgModule({\n  imports: [RouterModule.forRoot(routes)],\n  exports: [RouterModule]\n})\nexport class AppRoutingModule { }";
  char app_routing_module_ts_path[63];
  sprintf(app_routing_module_ts_path, "%s/app-routing.module.ts", app_folder_path);
  create_file(app_routing_module_ts_path, app_routing_module_ts);

  const char app_module_ts[] = "import { NgModule } from '@angular/core';\nimport { BrowserModule } from '@angular/platform-browser';\n\nimport { AppRoutingModule } from './app-routing.module';\nimport { AppComponent } from './app.component';\n\n@NgModule({\n  declarations: [\n    AppComponent\n  ],\n  imports: [\n    BrowserModule,\n    AppRoutingModule\n  ],\n  providers: [],\n  bootstrap: [AppComponent]\n})\nexport class AppModule { }";
  char app_module_ts_path[55];
  sprintf(app_module_ts_path, "%s/app.module.ts", app_folder_path);
  create_file(app_module_ts_path, app_module_ts);
  
  const char app_component_ts[] = "import { Component } from '@angular/core';\n\n@Component({\n  selector: 'app-root',\n  templateUrl: './app.component.html',\n  styleUrls: ['./app.component.sass']\n})\nexport class AppComponent {\n  title = 'app';\n}";
  char app_component_ts_path[58];
  sprintf(app_component_ts_path, "%s/app.component.ts", app_folder_path);
  create_file(app_component_ts_path, app_component_ts);
}
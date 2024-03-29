#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "include/utils.h"
#include "include/svelte.h"

void svelte(char project_name[PROJECT_NAME_LIMIT])
{
  char public_folder_path[38];
  char scripts_folder_path[39];
  char src_folder_path[35];

  sprintf(public_folder_path, "%s/public", project_name);
  sprintf(scripts_folder_path, "%s/scripts", project_name);
  sprintf(src_folder_path, "%s/src", project_name);

  mkdir(project_name, S_IRWXU);
  mkdir(public_folder_path, S_IRWXU);
  mkdir(scripts_folder_path, S_IRWXU);
  mkdir(src_folder_path, S_IRWXU);

  const char html[] = "<!DOCTYPE html>\n<html lang=\"en\">\n  <head>\n    <meta charset=\"utf-8\" />\n    <meta name=\"viewport\" content=\"width=device-width,initial-scale=1\" />\n    <title>Svelte App</title>\n    <link rel=\"icon\" href=\"#\" />\n    <link rel=\"stylesheet\" href=\"/global.css\" />\n    <link rel=\"stylesheet\" href=\"/build/bundle.css\" />\n    <script defer src=\"/build/bundle.js\"></script>\n  </head>\n  <body></body>\n</html>";
  char html_path[50];
  sprintf(html_path, "%s/index.html", public_folder_path);
  create_file(html_path, html);

  const char typescript_setup_file[] = "const fs = require(\"fs\")\nconst path = require(\"path\")\nconst { argv } = require(\"process\")\n\nconst projectRoot = argv[2] || path.join(__dirname, \"..\")\n\nconst packageJSON = JSON.parse(fs.readFileSync(path.join(projectRoot, \"package.json\"), \"utf8\"))\npackageJSON.devDependencies = Object.assign(packageJSON.devDependencies, {\n  \"svelte-check\": \"^2.0.0\",\n  \"svelte-preprocess\": \"^4.0.0\",\n  \"@rollup/plugin-typescript\": \"^8.0.0\",\n  \"typescript\": \"^4.0.0\",\n  \"tslib\": \"^2.0.0\",\n  \"@tsconfig/svelte\": \"^2.0.0\"\n});\n\npackageJSON.scripts = Object.assign(packageJSON.scripts, { check: \"svelte-check --tsconfig ./tsconfig.json\" });\nfs.writeFileSync(path.join(projectRoot, \"package.json\"), JSON.stringify(packageJSON, null, \"  \"));\n\nconst beforeMainJSPath = path.join(projectRoot, \"src\", \"main.js\");\nconst afterMainTSPath = path.join(projectRoot, \"src\", \"main.ts\");\nfs.renameSync(beforeMainJSPath, afterMainTSPath);\n\nconst appSveltePath = path.join(projectRoot, \"src\", \"App.svelte\");\nlet appFile = fs.readFileSync(appSveltePath, \"utf8\");\n\nappFile = appFile.replace(\"<script>\", '<script lang=\"ts\">');\nappFile = appFile.replace(\"export let name;\", 'export let name: string;');\n\nfs.writeFileSync(appSveltePath, appFile)\n\nconst rollupConfigPath = path.join(projectRoot, \"rollup.config.js\")\nlet rollupConfig = fs.readFileSync(rollupConfigPath, \"utf8\")\n\nrollupConfig = rollupConfig.replace(`'rollup-plugin-terser';`, `'rollup-plugin-terser';\nimport sveltePreprocess from 'svelte-preprocess';\nimport typescript from '@rollup/plugin-typescript';`);\n\nrollupConfig = rollupConfig.replace(`'src/main.js'`, `'src/main.ts'`);\n\nrollupConfig = rollupConfig.replace(\n  'compilerOptions:',\n  'preprocess: sveltePreprocess({ sourceMap: !production }),\\n\\tcompilerOptions:'\n);\n\nrollupConfig = rollupConfig.replace(\n  'commonjs(),',\n  'commonjs(),\\n\\t\\typescript({\\n\\t\\t\\tsourceMap: !production,\\n\\t\\t\\tinlineSources: !production\\n\\t\\t}),'\n);\nfs.writeFileSync(rollupConfigPath, rollupConfig);\n\nconst tsconfig = `{\n  \"extends\": \"@tsconfig/svelte/tsconfig.json\",\n\n  \"include\": [\"src/**/*\"],\n  \"exclude\": [\"node_modules/*\", \"__sapper__/*\", \"public/*\"]\n}`;\nconst tsconfigPath =  path.join(projectRoot, \"tsconfig.json\");\nfs.writeFileSync(tsconfigPath, tsconfig);\n\nconst dtsPath =  path.join(projectRoot, \"src\", \"global.d.ts\");\nfs.writeFileSync(dtsPath, `/// <reference types=\"svelte\" />`);\n\nif (!argv[2]) {\n  fs.unlinkSync(path.join(__filename));\n\n  const remainingFiles = fs.readdirSync(path.join(__dirname));\n  \n  if (remainingFiles.length === 1 && remainingFiles[0] === '.DS_store') fs.unlinkSync(path.join(__dirname, '.DS_store'));\n  if (fs.readdirSync(path.join(__dirname)).length === 0) fs.rmdirSync(path.join(__dirname));\n}\n\nfs.mkdirSync(path.join(projectRoot, \".vscode\"), { recursive: true });\nfs.writeFileSync(path.join(projectRoot, \".vscode\", \"extensions.json\"), `{\n  \"recommendations\": [\"svelte.svelte-vscode\"]\n}`);\n\nconsole.log(\"Converted to TypeScript.\");\n\nif (fs.existsSync(path.join(projectRoot, \"node_modules\")));\nconsole.log(\"\\nYou will need to re-run your dependency manager to get started.\");\n";
  char typescript_setup_file_path[59];
  sprintf(typescript_setup_file_path, "%s/setupTypescript.js", scripts_folder_path);
  create_file(typescript_setup_file_path, typescript_setup_file);
        
  
  char package_json[570];
  char package_json_path[44];
  sprintf(package_json_path, "%s/package.json", project_name);
  sprintf(package_json, "{\n  \"name\": \"%s\",\n  \"version\": \"1.0.0\",\n  \"private\": true,\n  \"scripts\": {\n    \"build\": \"rollup -c\",\n    \"dev\": \"rollup -c -w\",\n    \"start\": \"sirv public --no-clear\"\n  },\n  \"devDependencies\": {\n    \"@rollup/plugin-commonjs\": \"^17.0.0\",\n    \"@rollup/plugin-node-resolve\": \"^11.0.0\",\n    \"rollup\": \"^2.3.4\",\n    \"rollup-plugin-css-only\": \"^3.1.0\",\n    \"rollup-plugin-livereload\": \"^2.0.0\",\n    \"rollup-plugin-svelte\": \"^7.0.0\",\n    \"rollup-plugin-terser\": \"^7.0.0\",\n    \"svelte\": \"^3.0.0\"\n  },\n  \"dependencies\": {\n    \"sirv-cli\": \"^2.0.0\"\n  }\n}", project_name);
  create_file(package_json_path, package_json);

  const char rollup_config[] = "import svelte from 'rollup-plugin-svelte';\nimport commonjs from '@rollup/plugin-commonjs';\nimport resolve from '@rollup/plugin-node-resolve';\nimport livereload from 'rollup-plugin-livereload';\nimport { terser } from 'rollup-plugin-terser';\nimport css from 'rollup-plugin-css-only';\n\nconst production = !process.env.ROLLUP_WATCH;\n\nconst serve = () => {\n  let server;\n\n  const toExit = () => { if (server) server.kill(0); };\n\n  return {\n    writeBundle() {\n      if (server) return;\n      server = require('child_process').spawn('npm', ['run', 'start', '--', '--dev'], {\n        stdio: ['ignore', 'inherit', 'inherit'],\n        shell: true\n      });\n\n      process.on('SIGTERM', toExit);\n      process.on('exit', toExit);\n    }\n  };\n};\n\nexport default {\n  input: 'src/main.js',\n  output: {\n    sourcemap: true,\n    format: 'iife',\n    name: 'app',\n    file: 'public/build/bundle.js'\n  },\n  plugins: [\n    svelte({\n      compilerOptions: {\n        dev: !production\n      }\n    }),\n    css({ output: 'bundle.css' }),\n\n    resolve({\n      browser: true,\n      dedupe: ['svelte']\n    }),\n    commonjs(),\n    !production && serve(),\n    !production && livereload('public'),\n    production && terser()\n  ],\n  watch: {\n    clearScreen: false\n  }\n};";
  char rollup_config_path[48];
  sprintf(rollup_config_path, "%s/rollup.config.js", project_name);
  create_file(rollup_config_path, rollup_config);

  const char main_js[] = "import App from './App.svelte';\n\nconst app = new App({ target: document.body });\n\nexport default app;";
  char main_js_path[44];
  sprintf(main_js_path, "%s/main.js", src_folder_path);
  create_file(main_js_path, main_js);
  
  const char app_svelte[] = "<script>\n  // JavaScript here\n</script>\n\n<style>\n  /* CSS here */\n</style>\n\n<main>\n  <h1>Hello World!</h1>\n</main>";
  char app_svelte_path[47];
  sprintf(app_svelte_path, "%s/App.svelte", src_folder_path);
  create_file(app_svelte_path, app_svelte);
  
  const char gitignore[] = "node_modules\n/public/build";
  char gitignore_path[44];
  sprintf(gitignore_path, "%s/.gitignore", project_name);
  create_file(gitignore_path, gitignore);
  
  install_dependencies(project_name);
  
  printf("\nProject created successfully!");
}
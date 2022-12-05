# JS-Gen

Short for JavaScript Generator, is a tool for generating a JavaScript project *fast*

## Getting Started
First, clone the repository:
```sh
git clone https://github.com/Dev-Siri/JS-Gen.git
```
Then after opening the project, compile the code.
```sh
make
# Additionally, You can clean the object files
make clean
```
### Usage

Run the binary with
```sh
cd bin
# Change the executable extension depending on your OS
# Default is .exe
./JS-Gen.*
```

Command line arguments:

```sh
./JS-Gen.exe <project-name> <framework-name>
```

Currently, the tools supports 4 frameworks
- React
- Angular (Default CLI)
- Vue
- Svelte

Examples:
```sh
./JS-Gen.exe react-app react
./JS-Gen.exe angular-app angular
./JS-Gen.exe vue-app vue
./JS-Gen.exe svelte-app svelte
```

## License

MIT Licensed, see <a href="LICENSE.md">LICENSE.md</a>
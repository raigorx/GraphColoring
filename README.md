# GraphColoring

GraphColoring Algorithm Backtracking <https://en.wikipedia.org/wiki/Graph_coloring>

## Live-Demo
<https://godbolt.org/z/9Y9dcn7rd>

## Requirement

- c++20 compiler

## How to Build?

### As standalone example

GCC:

```
cd src
g++ -std=c++20 main.cpp -o main
```

CLANG:

```
clang++ -std=c++20 main.cpp -o main
```

MSVC

Open Visual Studio Developer Command Prompt <https://learn.microsoft.com/en-us/visualstudio/ide/reference/command-prompt-powershell?view=vs-2022>

```
cd src
cl /std:c++20 /EHsc main.cpp
```

### Using cmake

```
git clone https://github.com/raigorx/GraphColoring.git
cd GraphColoring
cmake -B build
cmake --build build
```

#### Compile result will be on directories bin and lib

## Running Tests

Test are made using google test <https://google.github.io/googletest/> tests are build via cmake same process as above.

You can run them via cmake:

```
cd GraphColoring/build
ctest
```

Or directly

```
cd src
./main_test
```

# compiler

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/d201a49a0f674f03b9f296aa123a6333)](https://www.codacy.com/app/Anticom/compiler?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=Anticom/compiler&amp;utm_campaign=Badge_Grade)

## Project description
Compiler framework alongside `go` compiler implementation.

The lexer and parser toolkit itself is located inside `tpl` subdirectory.

## Build instructions
To build the `go` compiler, after cloning this repository, run:
```sh
$ mkdir build
$ cd build
$ export CXX=/usr/bin/clang++ # <- optional
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make
```

You should be left with `go` executable in the build directory.
Currently the go compiler only looks for a `hello.go` in `pwd` and lexes + parses it.

## Current status of development
The `go` compiler in this repository is a work-in-progress.

The lexer is done so far, although some APIs could be improved by a lot.

The parser is still in early stages of development. The idea is to build a DSL using C++'s operator overloading capabilities so the developer can be able to formulate the grammar in a BNF'ish syntax.
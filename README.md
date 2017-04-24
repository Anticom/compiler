# compiler

## Project description
Compiler framework alongside `go` compiler implementation.

The lexer and parser toolkit itself is located inside `tpl` subdirectory.

## Build instructions
After cloning this repository, run:
```sh
$ cd gocompiler
$ mkdir Release
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
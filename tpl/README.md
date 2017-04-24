# Lexer & Parser toolkit

## Build instructions

The build of this project is managed via CMake.

You can optionally instruct CMake to use `clang++` over `gcc` by exporting it as `CXX`:
```
$ export CXX=/usr/bin/clang++
```

Debug Build:
```
$ mkdir Debug
$ cd Debug/
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ # From now on you can simply do:
$ make
```

Release Build:
```
$ mkdir Release
$ cd Release/
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ # From now on you can simply do:
$ make
```

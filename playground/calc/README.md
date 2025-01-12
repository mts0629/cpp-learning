# Calc

Commandline calculator

```sh
$ ./calc
> 1 + 2 + 3
6
> 4 * 5 - 6
14
> (7 + 8) / 9
1.66667
> 3.14*2*2
12.56
> quit # Finish calculation
```

## Prereqiusites

- GNU g++ (C++14)
- CMake (>= 3.22)
- clang-format (>= 13.0.0)
- GoogleTest (v.1.15.2)

## Directories

```
calc/
  |- src/ ... headers and sources
  |- test/ ... unit tests
  |- .clang-format ... formatter configuration
  |- googletest/ ... license of GoogleTest (BSD-3-Clause license)
  |- LICENSE
  `- README.md
```

## Build

```sh
$ cmake -S . -B ./build
$ cmake --build ./build
```

Executable binary is built as `./build/calc`.

## Test

```sh
$ cmake -S . -B ./build
$ cmake --build ./build
$ cd ./build
$ ctest
```

## License

Unlicense

### GoogleTest

BSD 3-Clause License

## References

- [再帰下降法でC言語数式パーサーもどきを作ってみる](https://zenn.dev/nomunomu0504/articles/a8504ec7a18744)

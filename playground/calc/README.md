# Calc

Commandline calculator

```sh
$ ./calc
> 1+2+3
6
> 4*5-6
14
```

## Prereqiusites

- GNU g++ (C++14)
- CMake (>= 3.22)
- clang-format
- GoogleTest (v.1.15.2)

## Directories

```
calc/
  |- src/ ... Headers and sources
  |- test/ ... Tests
  |- .clang-format ... Format configuration
  |- googletest/ ... license of GoogleTest (BSD-3-Clause license)
  |- LICENSE
  `- README.md
```

## Build

```sh
$ cmake -S . -B ./build
$ cmake --build ./build
```

Target binary is built as `./build/calc`.

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

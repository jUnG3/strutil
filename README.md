# strutil

String util for C. The lib provides a `trim` and a `strexplode` function.

# Build

Explains how to build a debug version.

```bash
$ cmake -DCMAKE_BUILD_TYPE=Debug -B cmake-build-debug -S .
$ cmake --build cmake-build-debug
```

# Test

Build and run tests.

```bash
$ cmake -DCMAKE_BUILD_TYPE=Debug -DENABLE_TESTS=ON -B cmake-build-debug -S .
$ cmake --build ./cmake-build-debug --target test
```

# Install

Build a release version and install it.

```bash
$ cmake -DCMAKE_BUILD_TYPE=Release -B cmake-build-release -S .
$ sudo cmake --build cmake-build-release --target install
```

# CMake options

| Name           | Description                                         |
|----------------|-----------------------------------------------------|
| `ENABLE_TESTS` | If `ON` tests are build and executed. Default `OFF` |

# Build dependencies

| Name    | Description         | Condition                      |
|---------|---------------------|--------------------------------|
| `cunit` | Unit test framework | Only if `ENABLE_TESTS` is `ON` |
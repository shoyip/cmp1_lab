# Vector3D

## Goal

Design and implement a C++ class with name `Vector3D` to handle mathematical
operations involving vectors in $\mathbb{R}^3$.

## Features

- [x] Pick appropriate data members
- [x] Implement constructors of all kinds you think may be of use
- [x] Implement setters
- [x] Implement member functions `scalarProduct()`, `vectorProduct()`, `magnitude()`, `theta()` and `phi()`
- [x] Implement the function `angle()` to calculate and return the angle between two vectors
- [x] Overload operators `+`, `-` and `=`
- [x] Overload operators `*` and `/` so that you can multiply or divide a vector by a double
- [x] Ensure you can handle both spherical and cartesian coordinate systems

## Design

## Compilation and Use

Issue the following command to compile the library to `Vector3D.o`.

```console
$ g++ -c Vector3D.cc
```

Issue then the following command to compile the executable.

```console
$ g++ -o vector vector.cpp Vector3D.o
```

**WARNING**: `vector` is the name of the main program, `Vector3D` is the name of the library.

# QuantMath

A C++ library that leverages SIMD and GPU intrinsics for financial mathematics

This is a sister repository of https://github.com/sleung852/FinMathLib 

## Overview

This library provides high-performance implementations of financial mathematical operations using modern C++ techniques, including:
- SIMD (Single Instruction, Multiple Data) optimizations
- GPU intrinsics support
- Financial option pricing models
- Statistical computations for quantitative finance

## Features

- High-performance mathematical operations
- Support for various financial derivatives pricing
- Optimized for both CPU and GPU computing
- Modular design with clear separation of concerns

## Getting Started

### Prerequisites

To build this project, you'll need:
- C++17 compatible compiler
- CMake 3.10 or higher
- Optional: CUDA toolkit for GPU support

### Building

```bash
mkdir build
cd build
cmake ..
make
```

### Usage

Include the necessary headers in your C++ code:

```cpp
#include "options/Option.h"
#include "pricer/BlackScholes.h"
```

## Project Structure

- `main.cpp` - Entry point of the application
- `common.h` - Common definitions and utilities
- `math_util/` - Mathematical utility functions
- `options/` - Financial option models and interfaces
- `pricer/` - Pricing engine implementations
- `test/` - Unit tests

## Contributing

Contributions are welcome! Please follow the existing code style and add appropriate tests.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
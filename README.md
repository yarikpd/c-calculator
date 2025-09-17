# RPN Calculator

A command-line calculator application that evaluates expressions using Reverse Polish Notation (RPN). This calculator supports basic arithmetic operations, power operations, and rounding functions.

## Features

- Evaluate RPN expressions with support for basic arithmetic (+, -, \*, /, ^)
- Power operations (^)
- Rounding functions:
    - Floor (f) - rounds down to the nearest integer
    - Ceiling (c) - rounds up to the nearest integer
    - Round (r) - rounds to the nearest integer according to standard rules
- Calculation history with configurable size
- Support for negative numbers

## Building from Source

### Prerequisites

- CMake (version 3.20 or higher)
- C++ compiler with C++20 support
- Google Test (for running tests)

### Build Instructions

```bash
# Clone the repository
git clone https://github.com/yarikpd/c-calculator.git
cd c-calculator

# Build the project
cmake -B build
cmake --build build
```

## Usage

Run the calculator:

```bash
./build/rpn_calculator
```

### Commands

- `r` - Evaluate an RPN expression
- `h` - Show calculation history
- `c` - Clear history
- `e` - Exit the calculator

### RPN Expression Examples

- Basic arithmetic: `2 3 +` (equals 5)
- Complex expression: `15 7 1 1 + - / 3 * 2 1 1 + + -` (equals 5)
- Using floor: `3.7 f` (equals 3.0)
- Using ceiling: `3.2 c` (equals 4.0)
- Using round: `3.5 r` (equals 4.0)
- Combined operations: `2.8 3.4 + f` (equals 6.0)

## Docker Support

You can build and run the calculator in a Docker container:

```bash
# Build the Docker image
docker build -t rpn-calculator .

# Run the container
docker run -it rpn-calculator
```

## Testing

The project includes unit tests using Google Test:

```bash
# Build and run the tests
cmake -B build
cmake --build build
cd build && ctest
```
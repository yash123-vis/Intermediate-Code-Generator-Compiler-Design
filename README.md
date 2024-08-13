
# Go Program Intermediate Code Generator

This project implements an Intermediate Code Generator (ICG) using Flex and Bison, designed to generate and run Go programs based on the defined specifications.

## Overview

The ICG reads an input Go program, performs lexical and syntax analysis, and generates intermediate code for execution according to the patterns and rules specified.

## Requirements

- **Flex** (Fast Lexical Analyzer)
- **Bison** (GNU Parser Generator)
- **GCC** (GNU Compiler Collection)
- Windows or Unix-like operating system

## Setup Instructions

### 1. Clone the Repository

```bash
git clone <repository-url>
cd <repository-folder>
```

### 2. Generate the Intermediate Code Generator

Run the following commands in the terminal after saving all the files in the same folder:

```bash
flex lexer.l.txt
bison -d tac.y --warnings=none
g++ tac.tab.c -w -o gocompiler
./gocompiler < test.go
```

These commands will compile the ICG and execute the Go program specified in `test.go`.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request if you have suggestions or improvements.

## License

This project is licensed under the [MIT License](LICENSE).


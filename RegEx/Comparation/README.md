# Comparative between RegEx and String

**Regex Performance and Optimization** 

## Description

This project explores the performance of regular expressions, particularly in contexts where regex is deemed "heavyweight." We investigate whether regular expressions should be avoided or optimized in different scenarios, addressing concerns about their computational complexity, processing overhead, and alternatives in string parsing.

## Features

- Performance benchmarking of common regex patterns.
- Exploration of alternatives to regex for specific use cases.
- Tools for regex optimization and reducing complexity.

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/LucasDiasJorge/Compilers-Studies.git
   ```
2. Navigate to the project directory:
   ```bash
   cd Comparation
   ```
3. Compile the project (assuming it is in C/C++ or similar languages):
   ```bash
   make
   ```

## Usage

To run the performance tests:
```bash
./regex_benchmark
```

## Expected

```bash
Regex verification time: 0.001288 seconds
Scratch verification time: 0.000003 seconds
Regex matched 4 strings
Scratch code matched 4 strings
```
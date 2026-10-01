# Professional Scientific Calculator
A C++ implementation of a professional scientific calculator with a modern GUI built with Qt6.

**Developed by Moise-codes**

## Features

### Basic Operations
- Addition, Subtraction, Multiplication, Division
- Power operation (x^y)
- Square root (√)
- Decimal point support
- Sign change (+/-)
- Percentage (%)
- Parentheses support ( )

### Scientific Functions
- Trigonometric functions: sin, cos, tan (in degrees)
- Logarithmic functions: log (base 10), ln (natural log)
- Exponential function (e^x)
- Factorial (x!)
- Constants: π (pi), e (Euler's number)

### Memory Functions
- MC (Memory Clear)
- MR (Memory Recall)
- M+ (Memory Add)
- M- (Memory Subtract)

### Additional Features
- Prime number checker
- Backspace (delete last digit)
- AC (All Clear)
- Responsive and zoomable UI
- Professional dark theme design
- Keyboard shortcuts for all operations

## How to Run

### Prerequisites
- CMake 3.5 or higher
- Qt6 (with Widgets module)
- C++17 compatible compiler

### Build Instructions
```bash
# Clone the repository
git clone <repository-url>
cd SCM

# Create build directory
mkdir -p cmake-build-debug
cd cmake-build-debug

# Configure with CMake
cmake ..

# Build the project
cmake --build .

# Run the calculator
./calculator
```

## Keyboard Functionality
- **Number keys**: {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
- **Math operators**: {+ (`Shift` + `=`), -, * (`Shift` + `8`), /}
- **Clear**: {C, Delete, Escape}
- **Backspace**: Backspace key (deletes last digit)
- **Equal**: {=, Return, Enter}
- **Decimal**: Period (.)
- **Parentheses**: ( and )
- **Percent**: %

Note that numpad keys may not work.

## UI Features
- **Responsive Design**: The calculator window can be resized and will adjust accordingly
- **Minimum Size**: 400x500 pixels to ensure usability
- **Professional Dark Theme**: Modern dark interface with color-coded buttons
  - Orange: Mathematical operators
  - Green: Equals button
  - Red: Clear button
  - Gray: Numbers and scientific functions
  - Dark gray: Memory functions

## License
This project is open source and available for educational purposes.

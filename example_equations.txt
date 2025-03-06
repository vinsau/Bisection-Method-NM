### Translating Mathematical Equations into C++ Code

This document provides examples of how common mathematical equations can be translated into C++ code using standard arithmetic operators and functions from the `<cmath>` library.

#### Basic Polynomial Equations
1. **Cubic Polynomial:**
   - Equation: \( x^3 - 4x - 9 \)
   - Code: `(x * x * x) - (4 * x) - 9`

2. **Quadratic Polynomial:**
   - Equation: \( ax^2 + bx + c \)
   - Code: `(a * x * x) + (b * x) + c`

3. **Linear Equation:**
   - Equation: \( mx + b \)
   - Code: `(m * x) + b`

#### Trigonometric Functions
1. **Sine Function:**
   - Equation: \( sin(x) \)
   - Code: `sin(x)`

2. **Cosine Function:**
   - Equation: \( cos(x) \)
   - Code: `cos(x)`

3. **Tangent Function:**
   - Equation: \( tan(x) \)
   - Code: `tan(x)`

#### Exponential and Logarithmic Functions
1. **Exponential Function:**
   - Equation: \( e^x \)
   - Code: `exp(x)`

2. **Natural Logarithm:**
   - Equation: \( ln(x) \)
   - Code: `log(x)`

3. **Base-10 Logarithm:**
   - Equation: \( log_{10}(x) \)
   - Code: `log10(x)`

#### Square Root
- Equation: \( \sqrt{x} \)
- Code: `sqrt(x)`

#### Absolute Value
- Equation: \( |x| \)
- Code: `fabs(x)`

#### Power Function
- Equation: \( x^n \)
- Code: `pow(x, n)`

### Notes
- All trigonometric functions assume the input is in radians.
- The `<cmath>` library must be included to use these functio
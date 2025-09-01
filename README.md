# Polynomial Solver from Roots (Base Conversion + Polynomial Construction)

##  Problem Statement
You are given `n` roots of a polynomial in **JSON format**, where each root is represented by:
- A **base** (number system like 2, 4, 10, 16, etc.)
- A **value** (string representation of the root in that base)

You also get:
- `n`: Number of roots provided
- `k`: Minimum number of roots required to solve for the coefficients of the polynomial

The degree of the polynomial is: M=K-1

### Objective
1. Parse the input.  
2. Convert root values from the given base into **decimal**.  
3. Select the first `k` roots.  
4. Construct the polynomial:
   \[
   P(x) = (x - r_1)(x - r_2)...(x - r_k)
   \]
5. Output the coefficients of the polynomial.

---

##  Input Format
Example JSON input:
```json
{
  "keys": { "n": 4, "k": 3 },
  "1": { "base": "10", "value": "4" },
  "2": { "base": "2", "value": "111" },
  "3": { "base": "10", "value": "12" },
  "6": { "base": "4", "value": "213" }
}

**## OUTPUT FORMAT
**
Polynomial coefficients:
1 -23 160 -336 

 

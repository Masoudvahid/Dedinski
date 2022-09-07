# Quadratic Equation Solver
* Code Issues that have been solved:  

0. Initial Commit
```
1. Initialize Variables
2. Make Input/Output Function
3. Manage Exception For Scanf
4. Use Pointers Not Reference
5. Output The Results In Output Module
6. Solve Linear Eq
7. Mistake In Formula: The Term Is Getting Multiplied By A Not Dividing
8. Sqrt Of Disc
9. B*B Vs Pow(B,2)
10. Move Enum To Header
11. Rename Enum To Capital Letter
12. Make Io.Cpp, Io.H, Solver.Cpp, Solver.H
13. Quadratic_equation To Solve Equations
14. Root_types To Number Of Roots
15. Return Number Of Roots Of Func Solve_quadratic
16. Handle Comparison For Discriminant To 0
17. Use Doxigen
18. Capital Letters Are Used For Constants And Use Small For Variables
```
1. Second Commit
```
1. Initialize Variables
2. Make Input/Output Function
3. Manage Exception For Scanf
4. Use Pointers Not Reference
5. Output The Results In Output Module
6. Solve Linear Eq
7. Mistake In Formula: The Term Is Getting Multiplied By A Not Dividing
8. Sqrt Of Disc
9. Move Enum To Header
10. Rename Enum To Capital Letter
11. Make IO.cpp, IO.h, Solver.cpp, Solver.h
12. Quadratic_equation To Solve Equations
13. Root_types To Number Of Roots
14. Return Number Of Roots Of Func Solve_quadratic
15. Handle Comparison For Discriminant To 0
16. Capital Letters Are Used For Constants And Use Small For Variables
```
2. Third Commit
```Documentation for the file has been created.

Unit testing has been created with all possible test cases

NOTE: Typedef are not used in c++ se we can remove them

NOTE: For testing we can use arguments to perform testing procedure

IMPORTANT: Do not terminate the program using exit and abort, instead return the correct value for the mistake like -1 for failure and 0 for correctness to be able to monitor where the problem is

IMPORTANT: Do not use empty operators, maybe we can misunderstand that next line is in the loop (ex. while (getchar() != '\n'); )

IMPORTANT: #endif // !EQUATIONS_IO_H

IMPORTANT: Do not initialize variables in struct in c "COMPILATION ERROR"

IMPORTANT: Better not to use defines in main part of programs

QUESTION: in "assert(a != nullptr);" when I enter a as 0, I assert would be called and that's because NULL is actually 0

1) exit(-1) removed
2) cycle till get correct input
3) number_of_roots -> n_roots
4) SolveEquations -> SolveEquation
6) Move RootNumbers to another header
7) Use text file for inputs of tests and answers, to refuse more recompiling
```

2. Issue #1 (const pointer and pointer to const) L3
```
IO.cpp: you can use const pointer parameters. Look for difference between const double* param and double* const param
const Object* obj; // can't change data
Object* const obj; // can't change pointer
const Object* const obj; // can't change data or pointer
```
3. Issue #2 (file docs) L1
```
IO.h: use @file for documentation of a file
```
4. Issue #3 (Docs style) L1
```
solver.cpp: You can make this comment as a documentation for doxygen.
```


5. Issue #4 (Extra empty line) L41
```
solver.h: Delete empty line.
```

6. Minor problems
```
Add assert for checking if pointer is null

SolveEquation:
if the power is 2, do not use pow function, it makes it a little complex.

SolveEquation:
comparison with == is prohibited for double
```
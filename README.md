This repo contains a transcript of the C _Program for Arithmetic Coding_ found in **Witten Ian H., Neal Radford M., Cleary John G. (1987). _Arithmetic coding for data compression_. Communications of the ACM, 30(6), 520–540. doi:[10.1145/214762.214771](https://dl.acm.org/doi/10.1145/214762.214771),** as well as a slightly modified version.

The `verbatim` folder hosts the original, (hopefully) unchanged files as they appear in the paper, while the root contains my modified, (hopefully) compileable files.

Here is a list of my changes:
- Since the program was written before the C programming language was first standardized, it has uses old style function declarations: the type of the function arguments used to be declared below the signature and before the opening braces (see [this SO question](https://stackoverflow.com/questions/13789450/variable-declaration-between-function-name-and-first-curly-brace)). I commented those lines and updated the signatures to modern standards.
- Included <stdlib.h>, so that the `exit` and `abort` functions are available.

(For a similar project implemented in C++, see [dmitrykravchenko2018/arithmetic_coding](https://github.com/dmitrykravchenko2018/arithmetic_coding).)

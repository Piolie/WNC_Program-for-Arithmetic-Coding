This repo contains a transcript of the C _Program for Arithmetic Coding_ found in **Witten Ian H., Neal Radford M., Cleary John G. (1987). _Arithmetic coding for data compression_. Communications of the ACM, 30(6), 520–540. doi:[10.1145/214762.214771](https://dl.acm.org/doi/10.1145/214762.214771),** as well as a slightly modified version.

The `verbatim` folder hosts the original, (hopefully) unchanged files as they appear in the paper, while the root contains my modified, (hopefully) compileable files and a makefile.

Here is a list of my changes:
- Since the program was written before the C programming language was first standardized, it uses old style function declarations: the type of the function arguments used to be declared below the signature and before the opening braces (see [this SO question](https://stackoverflow.com/questions/13789450/variable-declaration-between-function-name-and-first-curly-brace)). I commented those lines and updated the signatures to modern standards.
- Included <stdlib.h>, so that the `exit` and `abort` functions are available.
- Updated/added headers with missing function prototypes.
- Declared global variables in `model.h` and defined them in `encode.c` and `decode.c`.
- Made changes so that the programs read from/write to files instead of stdin/stdout.

encode_f/decode_f use the fixed model, while encode_a/decode_a use the adaptive one. Run `make` to generate both pairs and `make fixed` or `make adaptive` to generate just one pair.

# Usage
To use the coder, run:
- `encode_X <infile> <encfile>`
- `decode_X <encfile> <decfile>`
where X stands for the model: either `f` (fixed) or `a` (adaptive).

(For a similar project implemented in C++, see [dmitrykravchenko2018/arithmetic_coding](https://github.com/dmitrykravchenko2018/arithmetic_coding).)

------------

# License
I am _not_ the copyright holder of this works. I simply copied the program and made minimal adjustments to have it play nicely with modern compilers. This was done for purely academic purposes. If you need a license for this software contact the author(s) and/or publisher(s).

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

**CAUTION:** The generator scripts in `util/` generates C++ source code from web api responses. Do
not use the script with an unknown account that might be controlled by an adversary.

We currently attempt to escape the inputs, but making this secure for an adversarial environment
has not been a priority.

To build `chaos_curl` remove `include/cryptolens/imports/curl/curl.h` from the main repo.

# Random commands for working with the tests

```
valgrind --error-exitcode=1
```

Change cmake compiler: https://gitlab.kitware.com/cmake/community/wikis/FAQ#how-do-i-use-a-different-compiler
```
cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++"
```

Changing cmake compiler flags: https://stackoverflow.com/a/44357387
```
CFLAGS="" CXXFLAGS="" cmake
```

Debug/Release for cmake
```
cmake -DCMAKE_BUILD_TYPE=Release
```

Compilation database for infer/cppcheck
```
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1
```

Infer
```
infer run --compilation-database build/compile_commands.json
```

Clang static analyzer
```
scan-build cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++"
scan-build make
```
https://baptiste-wicht.com/posts/2014/04/install-use-clang-static-analyzer-cmake.html

Cppcheck
```
cppcheck --force --enable=all --project=compile_commands.json > cppcheck.txt 2>&1
```

gcov
```
CFLAGS="-fprofile-arcs -ftest-coverage" CXXFLAGS="-fprofile-arcs -ftest-coverage" cmake
<run executable>
lcov --capture --directory . --output-file full_coverage.info
lcov --remove full_coverage.info -o coverage.info '/some/path/*'
genhtml coverage.info --output-directory gcov_html
```
Sources:
 * https://en.wikipedia.org/wiki/Gcov
 * http://ltp.sourceforge.net/coverage/lcov.php
 * https://stackoverflow.com/questions/38438219/how-to-remove-certain-directories-from-lcov-code-coverage-report

llvm coverage
``
CFLAGS="-fprofile-instr-generate -fcoverage-mapping" CXXFLAGS="-fprofile-instr-generate -fcoverage-mapping" cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++"
LLVM_PROFILE_FILE="cryptolens.profraw" ./executable
llvm-profdata merge -sparse cryptolens.profraw -o cryptolens.profdata
llvm-cov show ./executable -instr-profile=cryptolens.profdata
llvm-cov show ./executable -instr-profile=cryptolens.profdata -format=html > llvm_cov.html

# -ignore-filename-regex seems to require a fairly new clang/llvm
#llvm-cov show ./executable -instr-profile=cryptolens.profdata -format=html -ignore-filename-regex='*third_party*' > llvm_cov.html
```
https://clang.llvm.org/docs/SourceBasedCodeCoverage.html

ASan
```
CFLAGS="-fsanitize=address" CXXFLAGS="-fsanitize=address" cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++"
```

UBSan
```
CFLAGS="-fsanitize=undefined" CXXFLAGS="-fsanitize=undefined" cmake -DCMAKE_C_COMPILER="clang" -DCMAKE_CXX_COMPILER="clang++"
```
UBSan wants to use clang for linking, but supposedly this is what cmake already does

Merge queues of multiple fuzzers to new directory:
```
for file in "`ls -1 /path/afl_sync/*/queue/*`"; do new="`mktemp ./input_XXXXXXXX`"; cat "$file" >> "$new"; done
```

Build in hardened mode and using libdislocator:
```
# AFL_HARDEN doesnt seem to work in the CMakeList.txt
mkdir build
cd build
export AFL_HARDEN="1"
cmake -DCMAKE_C_COMPILER="afl-clang-fast" -DCMAKE_CXX_COMPILER="afl-clang-fast++" ../
AFL_PRELOAD="/usr/lib/afl/libdislocator.so" afl-fuzz -m 500 -i input/ -o output/ -- ./fuzz_curl
```

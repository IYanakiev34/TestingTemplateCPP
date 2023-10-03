# Setting up a projec to use CTest and GTest
CTest is a command line utility that helps us run out tests.
We simply need to `include(CTest)` package in our root CMakeLists.txt file.
GTest on the other side is a testing framework developed by google for testing source code.

## Project set up
We will make the standard `build` and `src` folders, however, to make it better we will also use
`include` to keep our header files and also create directory specifically for tests called `test`.
So now in order to hook everything up we will need to follow some steps.

### Step 1: Create test file
First we need a test file. It will be included in the test folder to test some functionality of
our code. Welll how to test the code though? We need to be able to link into the proper binaries
and have the righr include path?

### Step 2: Create testing library
We need to bundle our appliction code into a library this library can be static and we can
link both our application and the test code. Or we can configure Cmake to make the library only
when we set testing option to true. None the less, for testing `we must have a library`.

### Step 3: Hook up CMake to test the code
So now we have a test file and an application library to test some code. We will need to
set up the CMakeLists.txt in the test folder to register those tests and create test binaries to run.
We need to first find the `GTest` package. This will search if we have this package installed on the machine
there are other options like git submodules etc, those will need different approach in our case
I assume you have it on the machine. Then we will proceed to create an executable which
will hold our test. So this is the `test.cpp` file or whatever you named it. Then as with any target
we add the proper include paths and the libraries we need. Finally we will call the very smart
`gtest_discover_test` passing in the target which will automatically discover all tests.

### Step 4: Run the tests
So to run the tests we will do: `ctest --test-dir build --output-on-failure -j8`. We can also
set the `GTEST_COLOR=1` environment variable to color the output. 


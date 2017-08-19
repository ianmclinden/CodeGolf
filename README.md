CodeGolf
===

An automated test ramework for testing Scripts for [CodeGolf](https://codegolf.stackexchange.com/).

License:
---
[GNU GENERAL PUBLIC LICENSE, Version 3, 29 June 2007.](LICENSE.txt)

Overview:
---

Golfed functions are defined one-per-file, in C header files. The file includes a corresponding automated test, to verify behaviour of the golf script. Tests are constructed to run a golfed function through its paces. They may include assertions about test post conditions, equality checks, debug prints, etc. Assertions are built in order, and short-circuit exit upon failure. 

Static Test Values:
---

The file `test_values.h` is provided to store static test values such as strings, integers, etc. This keeps the golf files compact.

Automated C Testing:
---

The sample below illustrates the 'golfed' integer addtion function, `add()`.

Inside `integer_add.h`
```C

// Our 'golf' function - pretty version for readability
//
// int add(int a, int b) {
//     return a+b;
// }
//

// Our 'golfed' version
a(i,j){return i+j;}

static char * test_integer_add() {
    // Tell the console what's running
    printf("test_integer_add():");
    
    // Declare test variables
    int i, j;
    
    // Run the test code on a range of inputs
    for (i=-10; i<=10; i++) {
        for (j=-10; j<=10; j++) {
            int actual = a(i,j);
            int expected = i+j;
            
            // Assertions about code execution
            ASSERT("error, actual got really small",actual>-9999);
            ASSERT_INT_EQUAL("error, actual output differed from expected", actual, expected);
        }
    }

    // The function returns SUCCESS if no error occured during assertion
    return SUCCESS;
}
```

The test is run in main.c, by first including `integer_add.h`, then including `test_integer_add()` in `all_tests()` as seen below.
```C
static char * all_tests() {
    RUN_TEST(test_integer_add);
    return SUCCESS;
}
```

Automated Testing of 'Print-Only' Functions:
---

Sometimes a golf requires only printing the value. In this case, the framework provides a way of testing a print-only function. The following example illustrates automated validation of the golf 'challenge' of printing "racecar" plus two numbers to standard out. 

In `test_values.h` we'll add our expected output string.
```C
char racecar[] = "racecar19";
```

in `racecar.h` we'll define the 'golfed' function and automated test.
```C
void r(a,b){
    printf("racecar%i%i",a,b);
}

static char * test_capture() {
// Tell the console what's running
    printf("test_capture():");

    // Create a string to capture the function's output
    char output[strlen(racecar)*sizeof(char)];
    memset(output, 0, strlen(racecar)*sizeof(char));

    // Assert that the CAPTURE_PRINT_OUTPUT macro completed succesfully
    // This captures the output of r(1,9) as all arguments to CAPTURE_PRINT_OUTPUT after the function name
    // are considered arguments of the function
    ASSERT_SUCCESS("function did not run successfully", CAPTURE_PRINT_OUTPUT(r, output, 1, 9));

    // Assert that we got some output, and that it matches
    ASSERT_NOT_NULL("Output was null", output);
    ASSERT_STRING_NOT_EMPTY("Output was empty", output);
    ASSERT_STRING_N_EQUAL("Function did not have correct output", racecar, output, strlen(racecar));

    return SUCCESS;
}
```

Finally, in `main.c` we'll include `test_capture()` like any other automated test.
```C
static char * all_tests() {
    RUN_TEST(test_capture);
    return SUCCESS;
}
```

Automated Testing of External Build Systems:
---

The framework also includes rudimentary support for testing external build system golfs, like python. The process is similar to automating a C test. First, write a golfed script in a language-appropriate file. Then use the file testing framework to run the file, capturing the output. The example below illustrates a golf 'challenge' of printing "hellu?" to standard out, and we'll use python.


In `hellu.py` we'll write our golf script.
```Python
print("hellu?")
```

In `test_values.h` we'll add our expected output string
```C
char hellu[] = "hellu?";
```

In `hellu.h` we'll define our automated tests, using the PYTHON3_PATH defined in minunit.h
```C

static char * test_hellu() {
    printf("test_hellu():");
    
    // Create a string to capture the program's output
    char output[strlen(hellu)*sizeof(char)];
    memset(output, 0,strlen(hellu)*sizeof(char));

    // Assert that the CAPTURE_PRINT_OUTPUT macro completed succesfully
    ASSERT_SUCCESS("File did not run successfully", CAPTURE_RUN_OUTPUT("golfs/hellu.py", PYTHON3_PATH, output));

    // Assert that we got some output, and that it matches
    ASSERT_NOT_NULL("Output was null", output);
    ASSERT_STRING_NOT_EMPTY("Output was empty", output);
    ASSERT_STRING_N_EQUAL("File did not have correct output", hellu, output, strlen(hellu));

    return SUCCESS;
}
```

Finally, in `main.c` we'll include `hellu.h` and `test_hellu()` like any other automated test.
```C
static char * all_tests() {
    RUN_TEST(test_hellu);
    return SUCCESS;
}
```

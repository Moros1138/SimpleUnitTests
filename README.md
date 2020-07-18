# SimpleUnitTests

## But Why?
This little project was inspired by a joke, late one night while making a 2d vector class as a learning experience. That turned into running unit tests, without a framework and this is what I came up with.

## Who's Responsible?

I'd like to personally thank SaladinAkara and Gusgo99 for their contributtions and for their company on the night in question.

# Brass Tacks (aka Usage)

First you must include the SimpleUnitTests.h header file, like so:
```c++
// o------------------------------------------------------------------------------o
// | Required DEFINE and INCLUDE for SimpleUnitTests                              |
// o------------------------------------------------------------------------------o
#define SIMPLE_UNITTESTS
#include "SimpleUnitTests.h"
```

Then you set up your tests, like so: (See 2dVectorTest.cpp in Examples for full code)

In the example we are testing a custom 2d vector class.

```c++
class Vector2iTests : public sut::Tests
{
public:
    Vector2iTests()
    {
     
        // ... SET UP YOUR TESTS HERE ...

        // -------------------------------------------------------
        // | EXAMPLE CONSTRUCT TEST                              |
        // -------------------------------------------------------
        Test(
            "It constructs a vector with default values.",
            SUT_FUNC {
                Vector2i a;
                
                // Test that our vector has been constructed and initialized
                // To the default value of x = 0; y = 0;
                SUT_ASSERT(a.x == 0 && a.y == 0);
                
                // Always return TestResult
                return TestResult;
            }
        );

        // ... SET UP YOUR TESTS HERE ...

        // -------------------------------------------------------
        // | PERFORM THE TESTS                                   |
        // -------------------------------------------------------
        PerformTests();
    }
};
```

## Example Test Output (See 2dVectorTest.cpp in Examples)
```
It constructs a vector with default values...FAIL
It initializes a vector to the provided values...PASSED
It adds 2 vectors together...PASSED
It subtractions 1 vector from another vector...PASSED
It flips the vector...PASSED
It multiplies 1 vector by another vector...PASSED
It multiplies 1 vector by a unit...PASSED
It divides 1 vector by another vector...PASSED
It divides 1 vector by a unit...PASSED
It performs addition assignment between vectors...PASSED
It performs subtraction assignment between vectors...PASSED
It performs multiplcation assignment between vectors...PASSED
It performs multiplcation assignment between a vector and a unit...PASSED
It performs division assignment between vectors...PASSED
It performs division assignment between a vector and a unit...PASSED
It returns the vector as a string...PASSED
It calculates boolean equals...PASSED
It calculates boolean not equals...PASSED
It calculates boolean greater than...PASSED
It calculates boolean less than...PASSED
It calculates boolean greater than or equals...PASSED
It calculates boolean less than or equals...PASSED

ERRORS for failed tests.

(a.x == 0 && a.y == 0) failed at 2dVectorTest.cpp:79
```
# License

Copyright 2020 moros1138@gmail.com

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or
sell copies of the Software, and to permit persons to whom
the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall
be included in all copies or substantial portions of the Software.

**THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.**


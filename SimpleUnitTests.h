// o------------------------------------------------------------------------o
// | SimpleUnitTests v0.1                                                   |
// o------------------------------------------------------------------------o
// | Copyright 2020 moros1138@gmail.com                                     |
// |                                                                        |
// | Permission is hereby granted, free of charge, to any person            |
// | obtaining a copy of this software and associated documentation         |
// | files (the "Software"), to deal in the Software without                |
// | restriction, including without limitation the rights to use,           |
// | copy, modify, merge, publish, distribute, sublicense, and/or           |
// | sell copies of the Software, and to permit persons to whom             |
// | the Software is furnished to do so, subject to the                     |
// | following conditions:                                                  |
// |                                                                        |
// | The above copyright notice and this permission notice shall            |
// | be included in all copies or substantial portions of the Software.     |
// |                                                                        |
// | THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        |
// | EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     |
// | MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. |
// | IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR       |
// | ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF         |
// | CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION     |
// | WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.        |
// o------------------------------------------------------------------------o
#ifndef SIMPLE_UNITTESTS_H
#define SIMPLE_UNITTESTS_H

#include <iostream>
#include <functional>
#include <utility>
#include <vector>

#define SUT_FUNC [&](bool TestResult)
#define SUT_ASSERT(expr) if(!(expr)) { \
    TestResult = false; InsertError({ #expr, __FILE__, __LINE__ }); \
}

namespace sut
{

    struct Error
    {
        std::string expression;
        std::string file;
        int line;
    };

    class Tests
    {
    public:
        void InsertError(const Error &e);
        void PerformTests();
        void Test(std::string message, std::function<bool(bool)> func);
    
    private:
        std::vector<std::pair<std::string,std::function<bool(bool)>>> vecTests;
        std::vector<Error> vecErrors;
    };    
}

#ifdef SIMPLE_UNITTESTS
#undef SIMPLE_UNITTESTS

namespace sut
{
    void Tests::InsertError(const Error &e)
    {
        vecErrors.push_back(e);
    }

    void Tests::PerformTests()
    {
        for(auto &f : vecTests)
        {
                std::cout << f.first;
                
                if(f.second(true))
                    std::cout << "..PASSED" << std::endl;
                else
                    std::cout << "..FAIL" << std::endl;
        }
        
        std::cout << std::endl << "ERRORS for failed tests." << std::endl << std::endl;

        for(auto &error : vecErrors)
        {
            std:: cout << "(" << error.expression << ") failed at " << error.file << ":" << error.line << std::endl;
        }
        
        std:: cout << std::endl;
    }
    
    void Tests::Test(std::string message, std::function<bool(bool)> func)
    {
        vecTests.push_back({ message, func });
    }
}

#endif
#endif

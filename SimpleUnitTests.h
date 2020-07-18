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

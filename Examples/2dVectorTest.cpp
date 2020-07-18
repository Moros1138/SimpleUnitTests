// o------------------------------------------------------------------------------o
// | Required DEFINE and INCLUDE for SimpleUnitTests                              |
// o------------------------------------------------------------------------------o
#define SIMPLE_UNITTESTS
#include "SimpleUnitTests.h"

// o------------------------------------------------------------------------------o
// | Example 2d Vector Class.... to test                                          |
// o------------------------------------------------------------------------------o
#include <cstdint>
#include <cmath>

template <class T>
struct generic_2d_vector
{
    T x;
    T y;
    generic_2d_vector() : x(0), y(0)                                    {                                                                     }
    generic_2d_vector(T x, T y) : x(x), y(y)                            {                                                                     }
    
    // vector maths
    T                 mag         ()                                    { return std::sqrt(x * x + y * y);                                    }
    T                 mag2        ()                                    { return x * x + y * y;                                               }
    generic_2d_vector norm        ()                                    { T r = 1 / mag(); return generic_2d_vector(x * r, y * r);            }
    T                 dot         (const generic_2d_vector& rhs)        { return this->x * rhs.x + this->y * rhs.y;                           }
    T                 cross       (const generic_2d_vector& rhs)        { return this->x * rhs.x - this->y * rhs.y;                           }

    // arithmetic operators
    generic_2d_vector operator +  (const generic_2d_vector& rhs)  const { return generic_2d_vector( this->x + rhs.x, this->y + rhs.y );       }
    generic_2d_vector operator -  (const generic_2d_vector& rhs)  const { return generic_2d_vector( this->x - rhs.x, this->y - rhs.y );       }
    generic_2d_vector operator -  ()                              const { return generic_2d_vector( -this->x, -this->y );                     }
    generic_2d_vector operator *  (const T& rhs)                  const { return generic_2d_vector( this->x * rhs,   this->y * rhs );         }
    generic_2d_vector operator *  (const generic_2d_vector& rhs)  const { return generic_2d_vector( this->x * rhs.x, this->y * rhs.y );       }
    generic_2d_vector operator /  (const T& rhs)                  const { return generic_2d_vector( this->x / rhs,   this->y / rhs );         }
    generic_2d_vector operator /  (const generic_2d_vector& rhs)  const { return generic_2d_vector( this->x / rhs.x, this->y / rhs.y );       }
    generic_2d_vector operator += (const generic_2d_vector& rhs)        { this->x = this->x + rhs.x; this->y = this->y + rhs.y; return *this; }
    generic_2d_vector operator -= (const generic_2d_vector& rhs)        { this->x -= rhs.x; this->y -= rhs.y; return *this;                   }
    generic_2d_vector operator *= (const T& rhs)                        { this->x *= rhs;   this->y *= rhs;   return *this;                   }
    generic_2d_vector operator *= (const generic_2d_vector& rhs)        { this->x *= rhs.x; this->y *= rhs.y; return *this;                   }
    generic_2d_vector operator /= (const T& rhs)                        { this->x /= rhs;   this->y /= rhs;   return *this;                   }
    generic_2d_vector operator /= (const generic_2d_vector& rhs)        { this->x /= rhs.x; this->y /= rhs.y; return *this;                   }
    
    // boolean operators
    bool              operator == (const generic_2d_vector& rhs)        { return (this->x == rhs.x && this->y == rhs.y);                      }
    bool              operator != (const generic_2d_vector& rhs)        { return (this->x != rhs.x || this->y != rhs.y);                      }
    bool              operator >  (const generic_2d_vector& rhs)        { return (this->x > rhs.x && this->y > rhs.y);                        }
    bool              operator <  (const generic_2d_vector& rhs)        { return (this->x < rhs.x && this->y < rhs.y);                        }
    bool              operator >= (const generic_2d_vector& rhs)        { return (*this > rhs || *this == rhs);                               }
    bool              operator <= (const generic_2d_vector& rhs)        { return (*this < rhs || *this == rhs);                               }

    std::string       to_string   ()                                    { return std::to_string(x) + " " + std::to_string(y);                 }
};

typedef generic_2d_vector<int32_t> Vector2i;
typedef generic_2d_vector<float>   Vector2f;
typedef generic_2d_vector<double>  Vector2d;

// o------------------------------------------------------------------------------o
// | Setting Up The Tests                                                         |
// o------------------------------------------------------------------------------o

class Vector2iTests : public sut::Tests
{
public:
    Vector2iTests()
    {
        // -------------------------------------------------------
        // | CONSTRUCT TEST                                      |
        // -------------------------------------------------------
        Test(
            "It constructs a vector with default values.",
            SUT_FUNC {
                Vector2i a;
                
                // we insert this to break this test on purpose
                // for demonstration purposes
                a = {1, 0};

                SUT_ASSERT(a.x == 0 && a.y == 0);

                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | EQUALS TEST                                         |
        // -------------------------------------------------------
        Test(
            "It initializes a vector to the provided values.",
            SUT_FUNC {
                Vector2i a;
                
                a = { 1, 1 };

                SUT_ASSERT(a.x == 1 && a.y == 1);

                return TestResult;
            }
        );
        
        // -------------------------------------------------------
        // | ADDITION TEST                                       |
        // -------------------------------------------------------
        Test(
            "It adds 2 vectors together.",
            SUT_FUNC {
                Vector2i a, b, c;

                a = { 0, 0 };
                b = { 1, 1 };
                
                c = a + b;

                SUT_ASSERT(c.x == 1 && c.y == 1);

                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | SUBTRACTION TEST                                    |
        // -------------------------------------------------------
        Test(
            "It subtractions 1 vector from another vector.",
            SUT_FUNC {
                Vector2i a, b, c;

                a = { 0, 0 };
                b = { 1, 1 };
                
                c = a - b;

                SUT_ASSERT(c.x == -1 && c.y == -1);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | UNARY SUBTRACTION TEST                              |
        // -------------------------------------------------------
        Test(
            "It flips the vector.",
            SUT_FUNC {
                Vector2i a;

                a = { 1, 1 };
                
                a = -a;

                SUT_ASSERT(a.x == -1 && a.y == -1);
                
                return TestResult;
            }
        );


        // -------------------------------------------------------
        // | MULTIPLICATION TEST (V to V)                        |
        // -------------------------------------------------------
        Test(
            "It multiplies 1 vector by another vector.",
            SUT_FUNC {
                Vector2i a, b, c;

                a = { 1, 1 };
                b = { 5, 5 };
                
                c = a * b;

                SUT_ASSERT(c.x == 5 && c.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | MULTIPLICATION TEST (V to Unit)                     |
        // -------------------------------------------------------
        Test(
            "It multiplies 1 vector by a unit.",
            SUT_FUNC {
                Vector2i a, b;

                a = { 1, 1 };
                
                b = a * 5;

                SUT_ASSERT(b.x == 5 && b.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | DIVISION TEST (V to V)                              |
        // -------------------------------------------------------
        Test(
            "It divides 1 vector by another vector.",
            SUT_FUNC {
                Vector2i a, b, c;

                a = { 15, 15 };
                b = { 3, 3 };
                
                c = a / b;

                SUT_ASSERT(c.x == 5 && c.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | DIVISION TEST (V to Unit)                           |
        // -------------------------------------------------------
        Test(
            "It divides 1 vector by a unit.",
            SUT_FUNC {
                Vector2i a, b;

                a = { 15, 15 };
                
                b = a / 3;

                SUT_ASSERT(b.x == 5 && b.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | ADDITION ASSIGNMENT TEST                            |
        // -------------------------------------------------------
        Test(
            "It performs addition assignment between vectors.",
            SUT_FUNC {
                Vector2i a, b;

                a = {0, 0};
                
                a += {1, 1};

                SUT_ASSERT(a.x == 1 && a.y == 1);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | SUBTRACTION ASSIGNMENT TEST                         |
        // -------------------------------------------------------
        Test(
            "It performs subtraction assignment between vectors.",
            SUT_FUNC {
                Vector2i a;

                a = {1, 1};
                
                a -= {1, 1};

                SUT_ASSERT(a.x == 0 && a.y == 0);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | MULTIPLICATION ASSIGNMENT TEST (V to V)             |
        // -------------------------------------------------------
        Test(
            "It performs multiplcation assignment between vectors.",
            SUT_FUNC {
                Vector2i a;

                a = {1, 1};
                
                a *= {5, 5};

                SUT_ASSERT(a.x == 5 && a.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | MULTIPLICATION ASSIGNMENT TEST (V to Unit)          |
        // -------------------------------------------------------
        Test(
            "It performs multiplcation assignment between a vector and a unit.",
            SUT_FUNC {
                Vector2i a;

                a = {1, 1};
                
                a *= 5;

                SUT_ASSERT(a.x == 5 && a.y == 5);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | DIVISION ASSIGNMENT TEST (V to V)                   |
        // -------------------------------------------------------
        Test(
            "It performs division assignment between vectors.",
            SUT_FUNC {
                Vector2i a;

                a = {15, 15};
                
                a /= {5, 5};

                SUT_ASSERT(a.x == 3 && a.y == 3);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | DIVISION ASSIGNMENT TEST (V to Unit)                |
        // -------------------------------------------------------
        Test(
            "It performs division assignment between a vector and a unit.",
            SUT_FUNC {
                Vector2i a;

                a = {15, 15};
                
                a /= 5;

                SUT_ASSERT(a.x == 3 && a.y == 3);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | TO STRING TEST                                      |
        // -------------------------------------------------------
        Test(
            "It returns the vector as a string.",
            SUT_FUNC {
                Vector2i a;

                a = {15, 15};
                
                std::string test = std::to_string(a.x) + " " + std::to_string(a.y);
                
                SUT_ASSERT(a.to_string().compare(test) == 0);
                
                return TestResult;
            }
        );
        
        // -------------------------------------------------------
        // | BOOLEAN EQUALS                                      |
        // -------------------------------------------------------
        Test(
            "It calculates boolean equals.",
            SUT_FUNC {
                Vector2d a, b;

                a = {15, 15};
                b = {15, 15};

                SUT_ASSERT(a == b);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | BOOLEAN NOT EQUALS                                  |
        // -------------------------------------------------------
        Test(
            "It calculates boolean not equals.",
            SUT_FUNC {
                Vector2d a, b;

                a = {15, 15};
                b = {10, 10};

                SUT_ASSERT(a != b);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | BOOLEAN GREATER THAN                                |
        // -------------------------------------------------------
        Test(
            "It calculates boolean greater than.",
            SUT_FUNC {
                Vector2d a, b;

                a = {15, 15};
                b = {10, 10};

                SUT_ASSERT(a > b);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | BOOLEAN LESS THAN                                   |
        // -------------------------------------------------------
        Test(
            "It calculates boolean less than.",
            SUT_FUNC {
                Vector2d a, b;

                a = {10, 10};
                b = {15, 15};

                SUT_ASSERT(a < b);
                
                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | BOOLEAN GREATER THAN OR EQUALS                      |
        // -------------------------------------------------------
        Test(
            "It calculates boolean greater than or equals.",
            SUT_FUNC {
                Vector2d a, b;

                a = {15, 15};
                b = {10, 10};

                SUT_ASSERT(a >= b);

                b = {15, 15};

                SUT_ASSERT(a >= b);

                return TestResult;
            }
        );

        // -------------------------------------------------------
        // | BOOLEAN LESS THAN OR EQUALS                         |
        // -------------------------------------------------------
        Test(
            "It calculates boolean less than or equals.",
            SUT_FUNC {
                Vector2d a, b;

                a = {10, 10};
                b = {15, 15};

                SUT_ASSERT(a <= b);
                
                b = {10, 10};

                SUT_ASSERT(a <= b);

                return TestResult;
            }
        );

        PerformTests();




    }
};

int main()
{
    // Instance of our tests, runs automatically from here
    Vector2iTests a;
    return 0;
}

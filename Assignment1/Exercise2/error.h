#include <stdexcept>
using namespace std;

class BadValue: public runtime_error{
public:
    BadValue(): runtime_error("(b*b-4*a*c) is less than zero") {}
};

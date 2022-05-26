// wrap.cpp
#include <boost/python.hpp>
#include "hello_world.hpp"

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);
}
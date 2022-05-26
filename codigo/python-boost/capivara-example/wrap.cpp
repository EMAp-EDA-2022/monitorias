#include <boost/python.hpp>
#include "capivara.hpp"

BOOST_PYTHON_MODULE(capivara)
{
    using namespace boost::python;
    class_<CapiFrame>("CapiFrame", init<int>())
        .def("NewColumn", &CapiFrame::NewColumn)
        .def("GetNumberColumns", &CapiFrame::GetNumberColumns)
        .def_readonly("max_columns", &CapiFrame::max_columns);
}
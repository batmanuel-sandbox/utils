#include "pybind11/pybind11.h"

#include "lsst/utils/Backtrace.h"

namespace py = pybind11;

namespace lsst {
namespace utils {

PYBIND11_PLUGIN(backtrace) {
    py::module mod("backtrace");

    Backtrace &backtrace = Backtrace::get();

    // Trick to tell the compiler backtrace is used and should not be
    // optimized away, as well as convenient way to check if backtrace
    // is enabled.
    mod.def("isEnabled", [&backtrace]() -> bool { return backtrace.isEnabled(); });

    return mod.ptr();
}

}  // utils
}  // lsst

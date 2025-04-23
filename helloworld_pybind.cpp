#include "helloworld.h"
#include "pybind11_protobuf/native_proto_caster.h"
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;
PYBIND11_MODULE(helloworld_pybind, m) {
  pybind11_protobuf::ImportNativeProtoCasters();

  m.def("create", &create, "Trivial example");
}
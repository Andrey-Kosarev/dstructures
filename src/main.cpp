#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "trees/BinarySearchTree.h"

#define STRINGIFY(x) #x
#define MACRO_STRINGIFY(x) STRINGIFY(x)

namespace py = pybind11;

PYBIND11_MODULE(dstructures, m) {
    py::module_ tree_module = m.def_submodule("tree");
    py::class_<tree::BinarySearchTree>(tree_module, "BinarySearchTree")
        .def(py::init<const int&>())
        .def_readonly("left", &tree::BinarySearchTree::left)
        .def_readonly("right", &tree::BinarySearchTree::right)
        .def_readonly("value", &tree::BinarySearchTree::node_value)
        .def("insert", &tree::BinarySearchTree::insert)
        .def("search", &tree::BinarySearchTree::search);
}
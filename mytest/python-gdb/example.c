#include <Python.h>

static PyObject *example_hello(PyObject *self, PyObject *args) {
  PyObject *name = NULL;
  if (!PyArg_ParseTuple(args, "O", &name)) {
    return NULL;
  }
  return PyUnicode_FromFormat("Hello, %S!", name);
}

static PyMethodDef example_methods[] = {
    {"hello", example_hello, METH_VARARGS, "Say hello."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef example_module = {
    PyModuleDef_HEAD_INIT, "example", "Example module", -1, example_methods};

PyMODINIT_FUNC PyInit_example(void) { return PyModule_Create(&example_module); }

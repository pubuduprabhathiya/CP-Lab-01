// #include "graph.h"
// #include <Python.h>

// static const char *file_name = "file_name";
// static const char *create_ghaph_fun = "create_ghaph";

// int create_graph(char **src, PyObject *knl) {
//   PyObject *file_py = PyUnicode_FromString(file_name);
//   if (file_py) {
//     PyObject *module = PyImport_Import(file_py);
//     if (module) {
//       PyObject *funtion = PyObject_GetAttrString(module, create_ghaph_fun);
//       if (funtion) {
//         PyObject *filefun = PyObject_CallFunctionObjArgs(funtion, knl,
//         NULL);
//         //  Py_ssize_t size;
//         //   const char *src_ = PyUnicode_AsUTF8AndSize(filefun, &size);
//         // *src = tcalloc(char, size + 1);
//         // strncpy(*src, src_, size + 1);
//         Py_DECREF(filefun);
//         Py_DECREF(funtion);
//       }
//       Py_DECREF(module);
//     }
//     Py_DECREF(file_py);
//   }
//   return 0;
// }

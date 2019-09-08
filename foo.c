#include "Python.h"

#if PY_MAJOR_VERSION >= 3
#define IS_PY3K
#endif


static PyObject *
f1(PyObject *self, PyObject *args)
{
    int p1, p2, p3 = 3;

    if (!PyArg_ParseTuple(args, "ii|i:f1", &p1, &p2, &p3))
        return NULL;

    printf("%d %d %d\n", p1, p2, p3);

    Py_RETURN_NONE;
}

static PyMethodDef module_functions[] = {
    {"f1", (PyCFunction) f1, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

#ifdef IS_PY3K
static PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT, "foo", 0, -1, module_functions,
};
PyMODINIT_FUNC
PyInit_foo(void)
#else
PyMODINIT_FUNC
initfoo(void)
#endif
{
    PyObject *m;

#ifdef IS_PY3K
    m = PyModule_Create(&moduledef);
    if (m == NULL)
        return NULL;
    return m;
#else
    m = Py_InitModule3("foo", module_functions, 0);
    if (m == NULL)
        return;
#endif
}

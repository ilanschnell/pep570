#include "Python.h"


static PyObject *
f1(PyObject *self, PyObject *args)
{
    int p1, p2, p3 = 3;

    if (!PyArg_ParseTuple(args, "ii|i:f1", &p1, &p2, &p3))
        return NULL;

    printf("p1: %d\n", p1);
    printf("p2: %d\n", p2);
    printf("p3: %d\n", p3);

    Py_RETURN_NONE;
}

static PyMethodDef module_functions[] = {
    {"f1", (PyCFunction) f1, METH_VARARGS, NULL},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initfoo(void)
{
    Py_InitModule3("foo", module_functions, 0);
}

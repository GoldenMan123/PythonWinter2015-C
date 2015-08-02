#include <Python.h>

int main(int argc, char **argv) {
    PyObject *list, *sliced, *repeated, *tmp;
    int i, s, e, r;
    char *res;

    if (argc < 5) {
        fprintf(stderr,"Usage: <start> <end> <repeat> <list>\n\n\
    Print list[start:end]*repeat");
        exit(0);
    }
    s = atoi(argv[1]);
    e = atoi(argv[2]);
    r = atoi(argv[3]);
    list = PyList_New(0);
    for (i = 4; i < argc; ++i) {
        tmp = PyString_FromString(argv[i]);
        PyList_Append(list, tmp);
        //Py_CLEAR(tmp);
    }
    sliced = PyList_GetSlice(list, s, e);
    repeated = PySequence_Repeat(sliced, r);
    for (i = 0; i < PyList_Size(repeated); ++i) {
        res = PyString_AsString(PyList_GetItem(repeated, i));
        printf("%s ", res);
    }
    printf("\n");
    Py_CLEAR(repeated);
    Py_CLEAR(sliced);
    Py_CLEAR(list);
    return 0;
}

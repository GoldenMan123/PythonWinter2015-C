cimport ftw

__doc__ = 'ftw.h wrapper'

cdef __fn = None

cdef int fn_wrapper(const char *fpath, void *sb, int typeflag):
    return __fn(fpath, typeflag)

def pyftw(const char *dirpath, fn, int nopenfd):
    global __fn
    __fn = fn
    return ftw(dirpath, fn_wrapper, nopenfd)


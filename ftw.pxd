cdef extern from "ftw.h":
    ctypedef int (* fn_type) (const char *fpath, void *sb,
        int typeflag)

    int ftw(const char *dirpath, fn_type p, int nopenfd)

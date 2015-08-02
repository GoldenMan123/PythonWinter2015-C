import ftw

def fn(fpath, typeflag):
    print fpath, typeflag
    return 0 

ftw.pyftw(".", fn, 128)


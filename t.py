from foo import f1

f1(1, 2)


def f2(*args):
    la = len(args)
    if la < 2:
        raise TypeError("takes at least 2 arguments (%d given)" % la)
    elif la == 2:
        p1, p2 = args
        p3 = 3
    elif la == 3:
        p1, p2, p3 = args
    else:
        raise TypeError("takes at most 3 arguments (%d given)" % la)
    print p1, p2, p3


f2(1, 2)

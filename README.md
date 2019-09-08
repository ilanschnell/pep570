Before Python 3:
----------------

def f(a, b, c=3):

a and b are required, c is optional.
Any parameter is either positional or keyword.

Valid calls:
f(1, 2)
f(1, b=2)
f(1, 2, 4)
f(c=4, a=1, b=2)

Invalid calls:
f(1, a=1) -> f() got multiple values for keyword argument 'a'


There is no easy way specify which parameters are positional or keyword.


Python 3:
---------

Parameters after the * marker are keyword-only:

def f(a, b=2, *, c, d=4)

a and c are required, b and d are optional.
a and b are positional or keyword, c and d are keyword-only.

Valid calls:
f(a=1, c=3)
f(1, 7, c=8)

Invalid calls:
f(1, 7, 8) -> f() takes from 1 to 2 positional arguments but 3 were given

While there is way now to specify which parameters are keyword-only, there is
no way to specify which parameters are positional-only


Python 3.8: (see PEP 570)
-----------

Parameters before the / marker are positional-only:

def f(a, b=2, /, c=3):

a is required, b and c are optional.
a and b are positional-only, c is positional or keyword

Valid calls:
f(1)
f(1, 4)
f(1, 4, 5)
f(1, 4, c=5)
f(1, c=5)

Invalid calls:
f(1, b=3) -> f() got some positional-only arguments passed as keyword arguments: 'b'


General:
--------

def name(positional_only_parameters, /, positional_or_keyword_parameters,
         *, keyword_only_parameters):


Example functions:
------------------

divmod(x, y, /)

pow(x, y, z=None, /)

eval(source, globals=None, locals=None, /)

sorted(iterable, /, *, key=None, reverse=False)

sum(iterable, /, start=0)

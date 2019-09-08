from distutils.core import setup, Extension


setup(
    name = "foo",
    author = "Ilan Schnell",
    author_email = "ilanschnell@gmail.com",
    ext_modules = [Extension(name = "foo", sources = ["foo.c"])],
)

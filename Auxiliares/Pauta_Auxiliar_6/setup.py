from Cython.Build import cythonize
from setuptools import setup

setup(
    name="Auxiliar 6",
    ext_modules=cythonize("bst.pyx"),
)

# Available at setup time due to pyproject.toml
from pybind11.setup_helpers import Pybind11Extension, build_ext
import pybind11
from setuptools import setup
from pathlib import Path
import os

__version__ = "0.0.1"


ext_modules = [
    Pybind11Extension(
        name="dstructures", 
        sources = [
            'src/main.cpp',                   
            'src/trees/BinarySearchTree.cpp',
        ],
        define_macros=[("VERSION_INFO", __version__)],
        extra_compile_args=['-std=c++20'],  
    ),
]

setup(
    name="dstructures",
    version=__version__,
    author="Andrei Kosarev",
    url="https://github.com/Andrey-Kosarev/dstructures",
    description="A Collection of common datastructures",
    ext_modules=ext_modules,
    extras_require={"test": "pytest"},
    cmdclass={"build_ext": build_ext},
    zip_safe=False,
    python_requires=">=3.13",
    # headers=sorted([str(p) for p in Path('src').rglob('*.h')])
)
#!/usr/bin/env python
import os
import sys

env = SConscript("cpp/godot/SConstruct")

env.Append(CPPPATH=["cpp/src/"])
sources = Glob("cpp/src/*.cpp")

library = env.SharedLibrary(
        "main/addon/bin/addon{}{}".format(env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)

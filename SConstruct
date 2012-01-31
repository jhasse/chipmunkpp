env = Environment()
env.Append(CPPFLAGS="-std=c++0x", CPPPATH="./src", LIBS="chipmunk", LIBPATH=".")
env.Program(["test.cpp"] + Glob("src/*.cpp"))

#!/usr/bin/python

env = Environment()
try:
	import multiprocessing
	env.SetOption('num_jobs', multiprocessing.cpu_count())
except NotImplementedError:
	pass

debug = int(ARGUMENTS.get('debug', 0))

if env['PLATFORM'] == 'win32':
	env = Environment(tools=['mingw'])

if env['PLATFORM'] == 'darwin':
	env = Environment(CXX='clang++', CXXFLAGS='-stdlib=libc++ ', LINKFLAGS='-stdlib=libc++', CC='clang')

if debug:
	env.Append(CCFLAGS = '-g -Wall')
else:
	env.Append(CCFLAGS = '-O2 -DNDEBUG')

env.Append(CXXFLAGS="-std=c++0x",
           CFLAGS="-std=c99",
           CPPPATH=Split("include chipmunk"))
lib = env.Library(source=Glob("src/*.cpp")+Glob("chipmunk/*.c")+Glob("chipmunk/constraints/*.c"),
                  target="chipmunk++")

env.Program(source="test.cpp", LIBS=lib)
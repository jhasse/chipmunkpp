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
	env = Environment(CXX='clang++', CC='clang', CPPDEFINES=['CHIPMUNKPP_BOOST'], CPPPATH='/opt/local/include')

if debug:
	env.Append(CCFLAGS = '-g -Wall')
else:
	env.Append(CCFLAGS = '-O2 -DNDEBUG')

env.Append(CXXFLAGS="-std=c++0x",
           CFLAGS="-std=c99",
           CPPPATH=Split("include chipmunk/include/chipmunk"))
lib = env.Library(source=Glob("src/*.cpp"),
                  target="chipmunk++")
env.Program(source="test.cpp", LIBPATH='chipmunk/src', LIBS=[lib, 'chipmunk'])

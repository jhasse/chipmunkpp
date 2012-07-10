#!/usr/bin/python

env = Environment()
try:
	import multiprocessing
	env.SetOption('num_jobs', multiprocessing.cpu_count())
except NotImplementedError:
	pass

debug = int(ARGUMENTS.get('debug', 0))
unit_test = int(ARGUMENTS.get('unit_test', 0))

if env['PLATFORM'] == 'win32':
	env = Environment(tools=['mingw'])

if env['PLATFORM'] == 'darwin':
	env = Environment(CXX='clang++', CC='clang', CXXFLAGS='-stdlib=libc++ ', LINKFLAGS='-stdlib=libc++')

if debug:
	env.Append(CCFLAGS = '-g -Wall')
else:
	env.Append(CCFLAGS = '-O2 -DNDEBUG')

env.Append(CXXFLAGS="-std=c++0x",
           CFLAGS="-std=c99",
           CPPPATH=Split("src chipmunk/include/chipmunk"))
lib = env.Library(source=Glob("src/chipmunkpp/*.cpp"),
                  target="chipmunk++")
env.Append(LIBPATH='chipmunk/src', LIBS=[lib, 'chipmunk'])
env.Program(source="test.cpp")

if unit_test:
	env = env.Clone()
	env.Append(LIBS=['boost_unit_test_framework'], CCFLAGS='-DBOOST_TEST_DYN_LINK')
	env.Program(target="unit_test/unit_test", source=Glob("unit_test/*.cpp"))

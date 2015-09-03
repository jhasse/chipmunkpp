#!/usr/bin/python

import os

vars = Variables()
vars.Add(BoolVariable('debug', 'Enable debug build', 0))
vars.Add(BoolVariable('unit_test', 'Build unit tests', 0))
vars.Add(BoolVariable('verbose', 'Show verbose compiling output', 0))
vars.Add('chipmunk_dir', 'Path to the chipmunk source', 'chipmunk')

env = Environment(variables = vars)
env['ENV']['TERM'] = os.getenv('TERM')
if "CC" in os.environ:
	env["CC"] = os.getenv("CC")
if "CXX" in os.environ:
	env["CXX"] = os.getenv("CXX")
Help(vars.GenerateHelpText(env))
try:
	import multiprocessing
	env.SetOption('num_jobs', multiprocessing.cpu_count())
except NotImplementedError:
	pass

if env['PLATFORM'] == 'win32':
	env = Environment(tools=['mingw'], variables = vars)

if env['PLATFORM'] == 'darwin':
	env = Environment(CXX='clang++', CC='clang',
	                  CXXFLAGS='-stdlib=libc++ ', LINKFLAGS='-stdlib=libc++',
	                  variables = vars)

if env['debug']:
	env.Append(CCFLAGS = '-g -Wall -Wextra -pedantic')
else:
	env.Append(CCFLAGS = '-O2 -DNDEBUG')

if not env['verbose']:
	env['CCCOMSTR'] = env['CXXCOMSTR'] = "compiling: $TARGET"
	env['LINKCOMSTR'] = "linking: $TARGET"
	env['ARCOMSTR'] = "archiving: $TARGET"

env.Append(CXXFLAGS="-std=c++0x",
           CFLAGS="-std=c99",
           CPPPATH=["src", env['chipmunk_dir'] + "/include/chipmunk"])
lib = env.Library(source=Glob("src/*.cpp") + Glob("src/chipmunkpp/*.cpp"),
                  target="chipmunk++")
chipmunk = env.Command(os.path.join(env["chipmunk_dir"], "src/libchipmunk.a"), None,
	"cd " + env["chipmunk_dir"] + "; "
	"cmake -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF -D CMAKE_BUILD_TYPE=Release .; "
	"make -j{}".format(env.GetOption("num_jobs")))
env.Append(LIBPATH=['%s/src' % env['chipmunk_dir']], LIBS=[lib, chipmunk, 'pthread'])
env.Program(source="test.cpp")

if env['unit_test']:
	env = env.Clone()
	env.Append(CPPDEFINES = 'BOOST_TEST_DYN_LINK')
	if env['PLATFORM'] == 'posix':
		env.Append(LIBS=['boost_unit_test_framework'])
	if env['PLATFORM'] in ['win32', 'msys']:
		env.Append(LIBS=['boost_unit_test_framework-mt'])
	env.Program(target="unit_test/unit_test", source=Glob("unit_test/*.cpp"))

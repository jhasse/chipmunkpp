#!/usr/bin/python

vars = Variables()
vars.Add(BoolVariable('debug', 'Enable debug build', 0))
vars.Add(BoolVariable('unit_test', 'Build unit tests', 0))
vars.Add(BoolVariable('verbose', 'Show verbose compiling output', 0))
vars.Add('chipmunk_dir', 'Path to the chipmunk source', 'chipmunk')

env = Environment(variables = vars)
Help(vars.GenerateHelpText(env))
try:
	import multiprocessing
	env.SetOption('num_jobs', multiprocessing.cpu_count())
except NotImplementedError:
	pass

if env['PLATFORM'] == 'win32':
	env = Environment(tools=['mingw'], variables = vars)

if env['PLATFORM'] == 'darwin':
	env = Environment(CXX='clang++', CC='clang', CXXFLAGS='-stdlib=libc++ ', LINKFLAGS='-stdlib=libc++',
	                  variables = vars, LIBPATH='../boost-libs/lib/mac')

if env['PLATFORM'] == 'posix':
	env.Append(CPPPATH='/usr/include/chipmunk')

if env['debug']:
	env.Append(CCFLAGS = '-g -Wall')
else:
	env.Append(CCFLAGS = '-O2 -DNDEBUG')

if not env['verbose']:
	env['CCCOMSTR'] = env['CXXCOMSTR'] = "compiling: $TARGET"
	env['LINKCOMSTR'] = "linking: $TARGET"
	env['ARCOMSTR'] = "archiving: $TARGET"

env.Append(CXXFLAGS="-std=c++0x",
           CFLAGS="-std=c99",
           CPPPATH=Split("src %s/include/chipmunk" % env['chipmunk_dir']))
lib = env.Library(source=Glob("src/*.cpp") + Glob("src/chipmunkpp/*.cpp"),
                  target="chipmunk++")
env.Append(LIBPATH=['%s/src' % env['chipmunk_dir']], LIBS=[lib, 'chipmunk'])
env.Program(source="test.cpp")

if env['unit_test']:
	env = env.Clone()
	env.Append(CPPDEFINES = 'BOOST_TEST_DYN_LINK')
	if env['PLATFORM'] == 'posix':
		env.Append(LIBS=['boost_unit_test_framework'])
	if env['PLATFORM'] in ['win32', 'msys']:
		env.Append(LIBS=['boost_unit_test_framework-mt'])
	env.Program(target="unit_test/unit_test", source=Glob("unit_test/*.cpp"))

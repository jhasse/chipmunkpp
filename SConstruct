env = Environment()
if env['PLATFORM'] == 'win32':
	env = Environment(tools=['mingw'])
env.SetOption('num_jobs', 4)
env.Append(CXXFLAGS="-std=c++0x", CFLAGS="-std=c99", CPPFLAGS="-O2 -s", CPPPATH=Split("./src chipmunk"))
lib = env.SharedLibrary(source=Glob("src/*.cpp")+Glob("chipmunk/*.c")+Glob("chipmunk/constraints/*.c"), target="chipmunk++")
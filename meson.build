project('chipmunkpp', ['cpp'], default_options : ['cpp_std=c++14'])

cxx = meson.get_compiler('cpp')

include = include_directories('src')
lib = static_library('chipmunkpp', include_directories : [
	include_directories('chipmunk/include/chipmunk')
], dependencies : [
	cxx.find_library('chipmunk'),
], sources : [
	'src/chipmunk.cpp',
	'src/chipmunkpp/arbiter.cpp',
	'src/chipmunkpp/bb.cpp',
	'src/chipmunkpp/body.cpp',
	'src/chipmunkpp/circleshape.cpp',
	'src/chipmunkpp/polyshape.cpp',
	'src/chipmunkpp/segmentshape.cpp',
	'src/chipmunkpp/shape.cpp',
	'src/chipmunkpp/space.cpp',
	'src/chipmunkpp/types.cpp',
	'src/chipmunkpp/vect.cpp',
])

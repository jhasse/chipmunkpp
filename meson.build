project('chipmunkpp', ['cpp'], default_options : ['cpp_std=c++14'])

cxx = meson.get_compiler('cpp')

chipmunk_dep = subproject('chipmunk').get_variable('chipmunk_dep')
include = include_directories('src')
lib = static_library('chipmunkpp', dependencies : [
	chipmunk_dep
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

chipmunkpp_dep = declare_dependency(include_directories : include, link_with : lib,
                                    dependencies : chipmunk_dep)

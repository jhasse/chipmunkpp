Chipmunk++
==========

C++11 wrapper for [Chipmunk](http://chipmunk-physics.net/).


Build
-----

First you'll need to set up Chipmunk itself. On Linux you can simply install it
using your package manager (e.g. `sudo apt-get install chipmunk-dev`) and skip
the next step.

On Windows or OSX you'll need to run

```
git submodule update --init
```

which clones the last Chipmunk release into a folder called *chipmunk*. Now compile Chipmunk:

```
cd chipmunk
cmake -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF -D CMAKE_BUILD_TYPE=Release .
make
```

To compile Chipmunk on Windows using [MSYS2](http://msys2.sourceforge.net/):

```
pacman -S make mingw-w64-x86_64-cmake
cmake -G "MSYS Makefiles" -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF -D CMAKE_BUILD_TYPE=Release .
make
```

Finally run [scons](http://scons.org/) in Chipmunk++'s folder.

Unit Tests
----------

```
scons unit_test=1
./unit_test/unit_test
```

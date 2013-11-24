Chipmunk++
==========

C++11 wrapper for [Chipmunk](http://chipmunk-physics.net/).


Build
-----

First you'll need to set up Chipmunk itself. On Linux you can simply install it
using your package manager (e.g. `sudo apt-get install chipmunk-dev`) and skip
the next step.

Extract the [latest version of Chipmunk](http://chipmunk-physics.net/release/ChipmunkLatest.tgz) to a folder called
*chipmunk*. Run `cmake -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF -D CMAKE_BUILD_TYPE=Release .` and `make` inside that
folder.

To compile Chipmunk on Windows using MinGW:
```
cmake -G "MinGW Makefiles" -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF -D CMAKE_BUILD_TYPE=Release .
mingw32-make
```

Run [scons](http://scons.org/) in Chipmunk++'s folder.

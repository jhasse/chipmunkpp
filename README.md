Chipmunk++
==========

C++11 wrapper for [Chipmunk](http://chipmunk-physics.net/).


Build
-----

Extract the [latest version of Chipmunk](http://chipmunk-physics.net/release/ChipmunkLatest.tgz) to a
folder called *chipmunk*. Run `cmake -D BUILD_DEMOS=OFF -D BUILD_SHARED=OFF .` and `make` inside that folder.

To compile Chipmunk on Windows using MinGW:
```
cmake -G "MinGW Makefiles" -D BUILD_DEMOS=OFF BUILD_SHARED=OFF .
mingw32-make
```

Run [scons](http://scons.org/) in Chipmunk++'s folder.

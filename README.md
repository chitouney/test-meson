#### Project: test-meson

Goal is to play and learn more about meson build.

The main idea is to compile a program that depends on a library that is based on boost and using meson-build to generate it.
If "meson builddir" is used from top project directory library "a" poject will be managed has a subproject.
Note that library "a" can also be generate alone by running "meson builddir" directly in "a" basedir.
The idea is to look, if a smooth migration from proprietary buidsystem can be done using meson.
    
The project contains:
  - "program" executable that depends on "a" dynamic library
  - "a" library that use boost library.
    Since some boost symboles are exposed in the public interface,
    it should accessible by transitivity for "a" library users  -> "program"
    
#### How to build

```
mkdir builddir'
meson builddir && cd builddir
ninja -v
```

#### How to install

```
DESTDIR=[destination] ninja -v
```

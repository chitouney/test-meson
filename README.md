#### Project: test-meson

Goal is to play and learn with meson build.
The main idea is to compile a program that depends on a library that is based on boost and using meson-build to genrate it.
    
The project contains:
  - "program" executable that depends on "a" dynamic library
  - "a" library that use boost library.
    Since some boost symboles are exposed in the public interface,
    it should accessible by transitivity for "a" library users  -> "program"
    
#### How to build

```
mkdir builddir'
LDFLAGS='-Wl,--no-undefined' meson builddir && cd builddir
ninja -v
```

#### How to install

```
DESTDIR=[destination] ninja -v
```
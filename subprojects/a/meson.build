project('a library', 'c', 'cpp',
                     version : '1.0.0',
                     license : 'MIT',
                     default_options : ['c_std=c11',
                                        'cpp_std=c++11',
                                        'warning_level=1'])

# we use LDFLAGS in the meson config command line since
# only available starting meson 0.42.0 
# add_global_link_arguments('-Wl,--no-undefined')

boost_dep = dependency('boost',
                       modules : ['thread', 'chrono', 'system'],
                       required : true)

a_inc = include_directories('include')

a_src = ['src/a.cpp']

a_lib = shared_library('a',
                      a_src,
                      include_directories : a_inc,
                      dependencies : boost_dep,
                      install : true)

# installation
install_headers('include/a/a.h', subdir : 'a')

#  dependencies
a_dep = declare_dependency(include_directories : a_inc,
                           link_with : a_lib,
                           dependencies: [boost_dep])

# we should use configure_file since required/required.private & co
# are not supported yet by pkg_mod

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : a_lib,
                 version : '1.0',
                 name : 'a',
                 filebase : 'a',
                 description : 'a Library to get current date')

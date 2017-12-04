project('b library', 'c', 'cpp',
                     version : '1.0.0',
                     license : 'MIT',
                     default_options : ['c_std=c11',
                                        'cpp_std=c++11',
                                        'warning_level=1'])

boost_dep = dependency('boost',
                       modules : ['thread', 'chrono', 'system'],
                       required : true)

b_inc = include_directories('include')

b_src = ['src/b.cpp']

b_lib = shared_library('b',
                      b_src,
                      include_directories : b_inc,
                      dependencies : boost_dep,
                      install : true)
                      #cpp_args : '-DBOOST_STATECHART_USE_NATIVE_RTTI')

# installation
install_headers('include/b/b.h', subdir : 'b')

#  dependencies
b_dep = declare_dependency(include_directories : b_inc,
                           link_with : b_lib,
                           dependencies: [boost_dep])

# we should use configure_file since required/required.private & co
# are not supported yet by pkg_mod

pkg_mod = import('pkgconfig')
pkg_mod.generate(libraries : b_lib,
                 version : '1.0',
                 name : 'b',
                 filebase : 'b',
                 description : 'b Library to test boost statechart')

project('c++ program', 'c', 'cpp',
                    version : '1.0.0',
                    license : 'MIT',
                    default_options : ['c_std=c11',
                                       'cpp_std=c++11',
                                       'warning_level=1'])
add_global_arguments(language : 'cpp')

a_sp = subproject('a')
a_inc = a_sp.get_variable('a_inc')
a_link = a_sp.get_variable('a_lib')
a_dep = a_sp.get_variable('a_dep')

executable('program', 'src/main.cpp', include_directories : a_inc,
                                      link_with : a_link,
                                      dependencies : a_dep,
                                      install : true)

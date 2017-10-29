project('c++ program', 'c', 'cpp',
                    version : '1.0.0',
                    license : 'MIT',
                    default_options : ['c_std=c11',
                                       'cpp_std=c++11',
                                       'warning_level=1'])

# check meson version
meson_min_version ='0.42.0'
mmeson = find_program('meson', required : true)
if mmeson.found()
    v = run_command('meson', '--version').stdout().strip()
    m = 'meson version found ' + v + ' (required: '  + meson_min_version + ')'
    assert(v.version_compare('>=' + meson_min_version), m)
    message(m)
endif
                                       
add_global_arguments(language : 'cpp')
add_global_link_arguments('-Wl,--no-undefined' , language : 'cpp')

a_sp = subproject('a')
a_inc = a_sp.get_variable('a_inc')
a_link = a_sp.get_variable('a_lib')
a_dep = a_sp.get_variable('a_dep')

executable('program', 'src/main.cpp', include_directories : a_inc,
                                      link_with : a_link,
                                      dependencies : a_dep,
                                      install : true)

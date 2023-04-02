project('cstm', 'cpp', default_options : ['cpp_std=c++20'])

add_project_arguments('-Wall', '-Wextra', '-Wshadow', '-Wconversion', '-Wpedantic', '-Werror', language : 'cpp')

libcstm = static_library('cstm', 'include/cstm/vector.hpp')
libcstm_dep = declare_dependency(include_directories : 'include', link_with : libcstm)

subdir('tests')
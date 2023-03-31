project('cstm', 'cpp')

libcstm = static_library('cstm', 'include/cstm/vector.hpp')
libcstm_dep = declare_dependency(include_directories : 'include', link_with : libcstm)

subdir('tests')
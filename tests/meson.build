gtest_dep = dependency('gtest', version : '>=1.13.0')
test_vector = executable('test.vector', 'vector.test.cpp', dependencies: [libcstm_dep, gtest_dep])
test('test.vector', test_vector)
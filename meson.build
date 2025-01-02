project('xyz', 'cpp', default_options : ['cpp_std=c++23'])

xyz = include_directories('src')

test_math = executable('test_math', 'tests/test_math.cpp', include_directories : xyz)
test('math', test_math)

test_vector2 = executable('test_vector2', 'tests/test_vector2.cpp', include_directories : xyz)
test('vector2', test_vector2)

test_grid = executable('test_grid', 'tests/test_grid.cpp', include_directories : xyz)
test('grid', test_grid)

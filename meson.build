project('xyz', 'cpp', default_options : ['cpp_std=c++23'])

xyz = include_directories('src')

test_math = executable('test_math', 'tests/test_math.cpp', include_directories : xyz)
test('math', test_math)

test_vector2 = executable('test_vector2', 'tests/test_vector2.cpp', include_directories : xyz)
test('vector2', test_vector2)

test_array = executable('test_array', 'tests/test_array.cpp', include_directories : xyz)
test('array', test_array)

test_grid = executable('test_grid', 'tests/test_grid.cpp', include_directories : xyz)
test('grid', test_grid)

test_bitfield = executable('test_bitfield', 'tests/test_bitfield.cpp', include_directories : xyz)
test('bitfield', test_bitfield)

test_option = executable('test_option', 'tests/test_option.cpp', include_directories : xyz)
test('option', test_option)

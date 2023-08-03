project('url-to-pdf', 'cpp',
  default_options : ['cpp_std=c++17'])

# general deps

general_deps = [
  dependency('absl_flags'),
  dependency('absl_flags_parse'),
  dependency('absl_strings')
]

# artifacts

test_exe = executable(
  'test1',
  'main.cpp',
  dependencies : general_deps
)

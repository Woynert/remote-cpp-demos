project('url-to-pdf', 'cpp',
  default_options : ['cpp_std=c++17'])

# general deps

general_deps = [
  dependency('absl_flags'),
  dependency('absl_flags_parse'),
  dependency('absl_strings')
]

source_files = [
  'main.cpp',
  'cli.cpp',
  'pdf.cpp'
]

# artifacts

test_exe = executable(
  'test1',
  source_files,
  dependencies : general_deps,
  include_directories : include_directories('./')
)

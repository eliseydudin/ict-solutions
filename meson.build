project(
  'informatics',
  ['cpp', 'c'],
  default_options: [
    'cpp_std=c++23',
    'b_ndebug=if-release',
    'buildtype=debugoptimized',
  ],
)

# disables errors on vla: creating an array of a variable size
add_project_arguments('-Wno-vla-cxx-extension', language: 'cpp')

fs = import('fs')

subdir('acmp')
subdir('codeforces')
subdir('informatics')
subdir('leetcode')
subdir('mosh_ict_2025')
subdir('yandex_training')
subdir('timus')
subdir('tbank_otbor_2025')

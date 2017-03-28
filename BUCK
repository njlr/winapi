include_defs('//BUCKAROO_DEPS')

prebuilt_cxx_library(
  name = 'winapi',
  header_only = True,
  header_namespace = 'boost/detail',
  exported_headers = subdir_glob([
    ('include/boost/detail', '**/*.hpp'),
  ]),
  visibility = [
    'PUBLIC',
  ],
  deps = BUCKAROO_DEPS,
)

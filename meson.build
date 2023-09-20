project('comms', 'cpp',
  version: '0.1', 
  meson_version: '>=0.58.0',
  default_options: [
                    'warning_level=3',
                    'werror=true',
                    'cpp_std=c++20',
                   ])

sdbusplus_dep = dependency('sdbusplus', version : '>=1.0')
boost_dep     = dependency('boost', version : '>=1.79.0', required : false, include_type: 'system')
openssl_dep   = dependency('openssl', required : false, include_type : 'system', static : false)

executable('comms',
            sources : [ 'comms.cpp', 'http.cpp' ],
            dependencies : [ sdbusplus_dep, boost_dep, openssl_dep ],
            install : true)

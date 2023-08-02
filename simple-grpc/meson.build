project('test-woy-1', 'cpp')

# proto compiler generator

grpc_cpp_plugin = find_program('grpc_cpp_plugin')
protoc = find_program('protoc')
gen = generator(
  protoc,
  output    : [
    '@BASENAME@.pb.cc',
    '@BASENAME@.pb.h',
    '@BASENAME@.grpc.pb.cc',
    '@BASENAME@.grpc.pb.h'
  ],
  arguments : [
    '--proto_path=@CURRENT_SOURCE_DIR@',
    '--cpp_out=@BUILD_DIR@',
    '--grpc_out=@BUILD_DIR@',
    '--plugin=protoc-gen-grpc=' + grpc_cpp_plugin.full_path(),
    '@INPUT@'
  ]
)

# general deps

proto_dep = dependency('protobuf')
grpc_dep = dependency('grpc++')

# generate proto files

generated = gen.process(['music_storage.proto'])
proto_interface = declare_dependency(
  sources : generated,
  dependencies : proto_dep
)

# artifacts

test_exe = executable(
  'server',
  'server.cc',
  dependencies : [
    proto_interface,
    grpc_dep
  ]
)

test_exe = executable(
  'client',
  'client.cc',
  dependencies : [
    proto_interface,
    grpc_dep
  ]
)


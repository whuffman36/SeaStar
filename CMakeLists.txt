cmake_minimum_required(VERSION 3.22)
project(sea_dsa VERSION 1.0)

set(gcc_like_c "$<COMPILE_LANG_AND_ID:C,ARMClang,AppleClang,Clang,GNU,>")
set(msvc_c "$<COMPILE_LANG_AND_ID:C,MSVC>")

add_executable(main main.c)
add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE c_std_11)
target_compile_options(compiler_flags INTERFACE
  "$<${gcc_like_c}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
  "$<${msvc_c}:$<BUILD_INTERFACE:-W3>>"
)
target_link_libraries(main PUBLIC compiler_flags)




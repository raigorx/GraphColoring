add_executable(main "main.cpp")

add_library(graphColoring STATIC "main.cpp")
target_compile_definitions(graphColoring PRIVATE "_LIB")

option(${PROJECT_NAME}_ENABLE_ASAN
       "Enable Address Sanitize to detect memory error." OFF)
if(${PROJECT_NAME}_ENABLE_ASAN)
  if(MSVC)
    target_compile_options(main PRIVATE /fsanitize=address)
    target_link_options(main PRIVATE /INCREMENTAL:NO)
    # add_link_options(/INCREMENTAL:NO)
  else()
    target_compile_options(main PRIVATE -fsanitize=address)
    target_link_options(main PRIVATE -fsanitize=address)
  endif()
endif()

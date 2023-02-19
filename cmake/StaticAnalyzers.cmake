if(${PROJECT_NAME}_ENABLE_CLANG_TIDY)
  find_program(CLANGTIDY clang-tidy)
  if(CLANGTIDY)
    # set(CMAKE_CXX_CLANG_TIDY
    # "${CLANGTIDY};-header-filter=${CMAKE_CURRENT_SOURCE_DIR}")
    if(MSVC_IDE)
      set_target_properties(
        "main"
        PROPERTIES VS_GLOBAL_RunCodeAnalysis true
                   # Use visual studio core guidelines
                   VS_GLOBAL_EnableMicrosoftCodeAnalysis true
                   # Use clangtidy
                   VS_GLOBAL_EnableClangTidyCodeAnalysis true)
    else()
      set_target_properties("main" PROPERTIES CXX_CLANG_TIDY "${CLANGTIDY}")
    endif()
    message("Clang-Tidy finished setting up.")
  else()
    message(SEND_ERROR "Clang-Tidy requested but executable not found.")
  endif()
endif()

if(${PROJECT_NAME}_ENABLE_CPPCHECK)
  find_program(CPPCHECK cppcheck)
  if(CPPCHECK)
    set(CMAKE_CXX_CPPCHECK ${CPPCHECK} --enable=all --inline-suppr
                           --inconclusive)
    message("Cppcheck finished setting up.")
  else()
    message(SEND_ERROR "Cppcheck requested but executable not found.")
  endif()
endif()

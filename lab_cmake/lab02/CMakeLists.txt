cmake_minimum_required(VERSION 3.22) 
project ("HELLOAPP" VERSION 1.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_FILE 
    main.cpp 
    src/calc.cpp)

# message(STATUS "SRC file has ${SRC_FILE}")
# message(STATUS "path is ${CMAKE_SOURCE_DIR}")

# if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
#     message("File exists")
# else()
#     message(FATAL_ERROR "File doesn't exist")
# endif()

add_executable("hellobinary" ${SRC_FILE})

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

target_include_directories(hellobinary PUBLIC "include/" "lib/")

target_link_libraries(hellobinary PUBLIC "wifi_lib")

# message(STATUS "CMAKE generator ${CMAKE_GENERATOR}")
# message(STATUS "CMAKE_CXX_STANDARD ${CMAKE_CXX_STANDARD}")
# message(STATUS "CMAKE_CXX_STANDARD_REQUIRED ${CMAKE_CXX_STANDARD_REQUIRED}")

set(PRODUCT_YEAR "2024")
configure_file(defaultconfig.h.in defaultconfig.h)
target_include_directories(hellobinary PUBLIC ${PROJECT_BINARY_DIR})

target_compile_definitions(hellobinary PUBLIC "STD_CXX=17")

install(FILES "${PROJECT_BINARY_DIR}/hellobinary"
DESTINATION "${PROJECT_BINARY_DIR}/executable"
)

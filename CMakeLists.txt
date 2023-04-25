cmake_minimum_required(VERSION 3.24)
project(lab3)

set(CMAKE_CXX_STANDARD 23)

if (WIN32)
    list(APPEND cpp.flags "/w4" "/WX" "/premissive-")
else ()
    list(APPEND cpp.flags "-Werror" "-Wall" "-Wextra" "-Wpedantic"
            "-fPIC")
endif()

add_compile_options(-std=c++11)
add_library(Lincked_list Libaries/Lincked_list/Lincked_list.cpp)
add_library(Dynamic_array Libaries/Dynamic_array/Dynamic_array.cpp)


add_executable(list tasks/Task1.cpp)
target_link_libraries(list Lincked_list)
target_compile_options (list PRIVATE)

add_executable(Dynamic_array1 tasks/Task2.1.cpp)
target_link_libraries(Dynamic_array1 Dynamic_array)
target_compile_options (Dynamic_array1 PRIVATE)


add_executable(Dynamic_array2 tasks/task2.2.cpp)
target_link_libraries(Dynamic_array2 Dynamic_array)
target_compile_options (Dynamic_array2 PRIVATE)

add_executable(Dynamic_array3 tasks/task2.3.cpp)
target_link_libraries(Dynamic_array3 Dynamic_array)
target_compile_options (Dynamic_array3 PRIVATE)


add_executable(test test.cpp)
target_link_libraries(test Dynamic_array)
target_compile_options (test PRIVATE)
project(PID_Control)

cmake_minimum_required (VERSION 3.5)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(sources src/main.cpp src/PID.cpp)


# if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 
if(CMAKE_SYSTEM_NAME STREQUAL Linux)

  include_directories(/usr/local/include)
  include_directories(/usr/local/opt/openssl/include)
  include_directories(../includes/Eigen)
  link_directories(/usr/local/lib)
  link_directories(/usr/local/opt/openssl/lib)
  link_directories(/usr/local/Cellar/libuv/1.11.0/lib)
  link_directories(/usr/include/uWS)

endif(CMAKE_SYSTEM_NAME STREQUAL Linux)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

  include_directories(/usr/local/opt/openssl/include)
  link_directories(/usr/local/opt/openssl/lib)
  link_directories(/usr/local/Cellar/libuv/1*/lib)

endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

# endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") 

add_executable(pid_control ${sources})

target_link_libraries(pid_control z ssl uv uWS)

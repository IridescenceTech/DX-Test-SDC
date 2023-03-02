cmake_minimum_required(VERSION 3.17)
project(DXTest)

set(CMAKE_CXX_STANDARD 17)

if(WIN32)
    add_compile_definitions(BUILD_PLAT=0)
elseif(PSP)
    add_compile_definitions(BUILD_PLAT=2)
elseif(VITA)
    add_compile_definitions(BUILD_PLAT=3)
elseif(3DS)
    add_compile_definitions(BUILD_PLAT=7)
else()
    add_compile_definitions(BUILD_PLAT=1)
endif()

add_subdirectory(./ext/SDC/)

add_executable(DXTest src/test.cpp)
target_include_directories(DXTest PUBLIC ../include/ ../ext/glm/glm/)
target_link_libraries(DXTest SC-Entry Stardust-Celeste)

if(WIN32)
    target_link_libraries(DXTest ws2_32 stdc++ d3d11 d3dcompiler d3dx11)
endif()
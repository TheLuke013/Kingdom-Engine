cmake_minimum_required(VERSION 3.0.0)
project(KingdomEngine VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

file(GLOB SOURCE_FILES
    "src/main.cpp"
    "src/Modules/Core/*.cpp"
    "src/Modules/Core/Nodes/*.cpp"
    "src/Modules/LuaScript/*.cpp"
)
add_executable(KingdomEngine ${SOURCE_FILES})

target_include_directories(KingdomEngine PRIVATE
    "ThirdParty/Irrlicht/include"
    "ThirdParty/Lua542/include"
    "ThirdParty/LuaBridge"
    "src/Modules/Core"
    "src/Modules/LuaScript"
)

target_link_libraries(KingdomEngine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Irrlicht/lib/Irrlicht.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Lua542/lib/lua54.lib
)

if(MSVC)
    set_target_properties(KingdomEngine PROPERTIES LINK_FLAGS /NODEFAULTLIB:LIBCMT)
endif()

add_custom_command(TARGET KingdomEngine POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       "${CMAKE_SOURCE_DIR}\\ThirdParty\\Irrlicht\\lib\\Irrlicht.dll"
                       $<TARGET_FILE_DIR:KingdomEngine>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

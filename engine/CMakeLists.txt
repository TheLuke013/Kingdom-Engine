cmake_minimum_required(VERSION 3.0.0)
project(KingdomEngineCore VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)

file(GLOB SOURCE_FILES
    "Core/src/*.cpp"
    "LuaScript/src/*.cpp"
)
add_executable(KingdomEngineCore ${SOURCE_FILES})

target_link_libraries(KingdomEngineCore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Irrlicht/lib/Irrlicht.lib)
target_link_libraries(KingdomEngineCore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/ThirdParty/Lua542/lib/lua54.lib)

add_custom_command(TARGET KingdomEngineCore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       "${CMAKE_SOURCE_DIR}\\ThirdParty\\Irrlicht\\lib\\Irrlicht.dll"
                       $<TARGET_FILE_DIR:KingdomEngineCore>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

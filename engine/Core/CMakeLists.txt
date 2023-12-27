cmake_minimum_required(VERSION 3.0.0)
project(KingdomEngineCore VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../../bin)

add_executable(KingdomEngineCore src/main.cpp src/Game.cpp)

target_link_libraries(KingdomEngineCore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../ThirdParty/Irrlicht/lib/Irrlicht.lib)

add_custom_command(TARGET KingdomEngineCore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                       "${CMAKE_SOURCE_DIR}\\..\\ThirdParty\\Irrlicht\\lib\\Irrlicht.dll"
                       $<TARGET_FILE_DIR:KingdomEngineCore>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

CMAKE_MINIMUM_REQUIRED(VERSION 3.14)

PROJECT(true_boolean_game)

SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_REQUIRED ON)

IF (${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Darwin")
    IF (${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "x86_64")
        SET(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/SDL2/macos_x86_64)
    ELSEIF(${CMAKE_HOST_SYSTEM_PROCESSOR} STREQUAL "arm64")
        SET(SDL2_LIB_DIR ${CMAKE_SOURCE_DIR}/lib/SDL2/macos_arm64)
    ENDIF()
    
    SET(SDL2_LIBRARY ${SDL2_LIB_DIR}/libSDL2.a)
    SET(SDL2_IMAGE_LIBRARY ${SDL2_LIB_DIR}/libSDL2_image.a)

ELSEIF(${CMAKE_HOST_SYSTEM_NAME} STREQUAL "Windows")
    # Nothing done yet.
ELSE()
    MESSAGE(FATAL_ERROR "Unsupported platform: ${CMAKE_HOST_SYSTEM_NAME}")
ENDIF()

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)

TARGET_LINK_LIBRARIES(
    ${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY}
    "-framework Cocoa" 
    "-framework IOKit" 
    "-framework CoreFoundation" 
    "-framework CoreVideo"
    "-framework AudioToolbox"
    "-framework CoreAudio"
    "-framework AVFoundation"
    "-framework GameController"
    "-framework Metal"
    "-framework Foundation"
    "-framework ForceFeedback"
    "-framework CoreHaptics"
    "-framework Carbon")


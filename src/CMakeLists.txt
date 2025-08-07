cmake_minimum_required(VERSION 3.10)

project(flashlight_driver)

add_library(flashlight_driver MODULE flashlight_driver.c)

target_include_directories(flashlight_driver PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

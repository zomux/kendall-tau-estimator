cmake_minimum_required(VERSION 2.8.4)
project(kendall_tau)

set(SOURCE_FILES kendall.cc)
add_executable(kendall_tau ${SOURCE_FILES})
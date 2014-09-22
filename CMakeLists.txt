cmake_minimum_required(VERSION 2.8.4)
project(kendall_tau)

find_package(Boost 1.36.0 COMPONENTS regex)

set(SOURCE_FILES1 average_tau.cc estimator.cc)
add_executable(average_tau ${SOURCE_FILES1})
target_link_libraries(average_tau ${Boost_LIBRARIES})

set(SOURCE_FILES2 estimator.cc test_kendall_tau.cc)
add_executable(test_kendall_tau ${SOURCE_FILES2})
target_link_libraries(test_kendall_tau ${Boost_LIBRARIES})
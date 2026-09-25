cmake_minimum_required(VERSION 3.17)
project(nanotekspice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(LIB_SOURCES
    src/Circuit.cpp
    src/Parser.cpp
    src/Factory.cpp
    src/special_comp/Input.cpp
    src/special_comp/Output.cpp
    src/special_comp/Clock.cpp
    src/special_comp/True.cpp
    src/special_comp/False.cpp
    src/elementary_comp/AndGate.cpp
    src/elementary_comp/OrGate.cpp
    src/elementary_comp/XorGate.cpp
    src/elementary_comp/NotGate.cpp
    src/elementary_comp/NorGate.cpp
    src/elementary_comp/NandGate.cpp
    src/gates_comp/Chip4001.cpp
    src/gates_comp/Chip4011.cpp
    src/gates_comp/Chip4030.cpp
    src/gates_comp/Chip4069.cpp
    src/gates_comp/Chip4071.cpp
    src/gates_comp/Chip4081.cpp

    src/advanced_comp/Chip4040.cpp
    src/advanced_comp/Chip4008.cpp
)

add_library(nanotekspice_lib STATIC ${LIB_SOURCES})
target_include_directories(nanotekspice_lib PUBLIC
    include
    include/elementary_comp
    include/gates_comp
    include/special_comp
)

add_executable(nanotekspice src/main.cpp)
target_link_libraries(nanotekspice PRIVATE nanotekspice_lib)

enable_testing()
add_executable(unit_tests tests/test_main.cpp
                            tests/test_circuit.cpp
                            tests/test_factory.cpp
                            tests/test_exceptions.cpp
                            tests/test_gates.cpp
                            tests/test_clock.cpp
                            tests/test_input.cpp
                            tests/test_output.cpp
                            tests/test_trueComp.cpp
                            tests/test_falseComp.cpp
                            tests/test_andGate.cpp
                            tests/test_orGate.cpp
                            tests/test_xorGate.cpp
                            tests/test_notGate.cpp
                            tests/test_nandGate.cpp
                            tests/test_norGate.cpp
)

target_include_directories(unit_tests PRIVATE
    include
    include/elementary_comp
    include/gates_comp
    include/special_comp
)
target_link_libraries(unit_tests PRIVATE nanotekspice_lib criterion)
add_test(NAME unit_tests COMMAND unit_tests)

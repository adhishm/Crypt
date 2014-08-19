project(crypt)

add_executable(crypt lookupTable.cpp main.cpp)

install(TARGETS crypt RUNTIME DESTINATION bin)

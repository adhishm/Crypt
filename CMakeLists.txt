project(crypt)

add_executable(crypt encryptedMessage.cpp lookupTable.cpp main.cpp)

install(TARGETS crypt RUNTIME DESTINATION bin)

#ADD_EXECUTABLE(test_c test/test_c.c)
ADD_EXECUTABLE(test_s test/test_s.c)
TARGET_LINK_LIBRARIES(test_s pthread)
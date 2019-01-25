INCLUDE_DIRECTORIES(include)
AUX_SOURCE_DIRECTORY(src/alsa SRCS_ALSA)
AUX_SOURCE_DIRECTORY(src/v4l2 SRCS_V4L2)
AUX_SOURCE_DIRECTORY(test SRCS_TEST)

#ADD_EXECUTABLE(test_recorder test/test_recorder.c ${SRCS_ALSA})
#TARGET_LINK_LIBRARIES(test_recorder asound)

ADD_EXECUTABLE(test_player test/test_player.c ${SRCS_ALSA})
TARGET_LINK_LIBRARIES(test_player asound)

ADD_EXECUTABLE(test_video_capture test/test_video_capture.c ${SRCS_V4L2})
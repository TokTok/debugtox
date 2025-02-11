cmake_minimum_required(VERSION 3.10)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

project(
  DebugTox
  VERSION 0.0.1
  LANGUAGES CXX)

# Project name lowercase
string(TOLOWER ${PROJECT_NAME} BINARY_NAME)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_UNITY_BUILD ON)
set(CMAKE_UNITY_BUILD_BATCH_SIZE 8)

add_definitions(-DQT_NO_CAST_FROM_BYTEARRAY)
add_definitions(-DQT_NO_CAST_TO_ASCII)
add_definitions(-DQT_NO_CAST_FROM_ASCII)
add_definitions(-DQT_NO_NARROWING_CONVERSIONS_IN_CONNECT)
add_definitions(-DQT_NO_URL_CAST_FROM_STRING)
add_definitions(-DQT_NO_CONTEXTLESS_CONNECT)
add_definitions(-DQT_MESSAGELOGCONTEXT=1)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

find_package(PkgConfig REQUIRED)
pkg_check_modules(TOXCORE REQUIRED toxcore)
pkg_check_modules(LIBSODIUM REQUIRED libsodium)

set(PROJECT_SOURCES
    src/models/enums/conferencetype.cpp
    src/models/enums/conferencetype.h
    src/models/enums/conferencetype_p.h
    src/models/enums/connection.cpp
    src/models/enums/connection.h
    src/models/enums/connection_p.h
    src/models/enums/filecontrol.cpp
    src/models/enums/filecontrol.h
    src/models/enums/filecontrol_p.h
    src/models/enums/groupexittype.cpp
    src/models/enums/groupexittype.h
    src/models/enums/groupexittype_p.h
    src/models/enums/groupjoinfail.cpp
    src/models/enums/groupjoinfail.h
    src/models/enums/groupjoinfail_p.h
    src/models/enums/groupmodevent.cpp
    src/models/enums/groupmodevent.h
    src/models/enums/groupmodevent_p.h
    src/models/enums/groupprivacystate.cpp
    src/models/enums/groupprivacystate.h
    src/models/enums/groupprivacystate_p.h
    src/models/enums/grouptopiclock.cpp
    src/models/enums/grouptopiclock.h
    src/models/enums/grouptopiclock_p.h
    src/models/enums/groupvoicestate.cpp
    src/models/enums/groupvoicestate.h
    src/models/enums/groupvoicestate_p.h
    src/models/enums/messagetype.cpp
    src/models/enums/messagetype.h
    src/models/enums/messagetype_p.h
    src/models/enums/userstatus.cpp
    src/models/enums/userstatus.h
    src/models/enums/userstatus_p.h
    src/models/bytes/bytearray.cpp
    src/models/bytes/bytearray.h
    src/models/bytes/publickey.cpp
    src/models/bytes/publickey.h
    src/models/events/conferenceconnected.cpp
    src/models/events/conferenceconnected.h
    src/models/events/conferenceinvite.cpp
    src/models/events/conferenceinvite.h
    src/models/events/conferencemessage.cpp
    src/models/events/conferencemessage.h
    src/models/events/conferencepeerlistchanged.cpp
    src/models/events/conferencepeerlistchanged.h
    src/models/events/conferencepeername.cpp
    src/models/events/conferencepeername.h
    src/models/events/conferencetitle.cpp
    src/models/events/conferencetitle.h
    src/models/events/dhtgetnodesresponse.cpp
    src/models/events/dhtgetnodesresponse.h
    src/models/events/filechunkrequest.cpp
    src/models/events/filechunkrequest.h
    src/models/events/filerecv.cpp
    src/models/events/filerecv.h
    src/models/events/filerecvchunk.cpp
    src/models/events/filerecvchunk.h
    src/models/events/filerecvcontrol.cpp
    src/models/events/filerecvcontrol.h
    src/models/events/friendconnectionstatus.cpp
    src/models/events/friendconnectionstatus.h
    src/models/events/friendlosslesspacket.cpp
    src/models/events/friendlosslesspacket.h
    src/models/events/friendlossypacket.cpp
    src/models/events/friendlossypacket.h
    src/models/events/friendmessage.cpp
    src/models/events/friendmessage.h
    src/models/events/friendname.cpp
    src/models/events/friendname.h
    src/models/events/friendreadreceipt.cpp
    src/models/events/friendreadreceipt.h
    src/models/events/friendrequest.cpp
    src/models/events/friendrequest.h
    src/models/events/friendstatus.cpp
    src/models/events/friendstatus.h
    src/models/events/friendstatusmessage.cpp
    src/models/events/friendstatusmessage.h
    src/models/events/friendtyping.cpp
    src/models/events/friendtyping.h
    src/models/events/groupcustompacket.cpp
    src/models/events/groupcustompacket.h
    src/models/events/groupcustomprivatepacket.cpp
    src/models/events/groupcustomprivatepacket.h
    src/models/events/groupinvite.cpp
    src/models/events/groupinvite.h
    src/models/events/groupjoinfail.cpp
    src/models/events/groupjoinfail.h
    src/models/events/groupmessage.cpp
    src/models/events/groupmessage.h
    src/models/events/groupmoderation.cpp
    src/models/events/groupmoderation.h
    src/models/events/grouppassword.cpp
    src/models/events/grouppassword.h
    src/models/events/grouppeerexit.cpp
    src/models/events/grouppeerexit.h
    src/models/events/grouppeerjoin.cpp
    src/models/events/grouppeerjoin.h
    src/models/events/grouppeerlimit.cpp
    src/models/events/grouppeerlimit.h
    src/models/events/grouppeername.cpp
    src/models/events/grouppeername.h
    src/models/events/grouppeerstatus.cpp
    src/models/events/grouppeerstatus.h
    src/models/events/groupprivacystate.cpp
    src/models/events/groupprivacystate.h
    src/models/events/groupprivatemessage.cpp
    src/models/events/groupprivatemessage.h
    src/models/events/groupselfjoin.cpp
    src/models/events/groupselfjoin.h
    src/models/events/grouptopic.cpp
    src/models/events/grouptopic.h
    src/models/events/grouptopiclock.cpp
    src/models/events/grouptopiclock.h
    src/models/events/groupvoicestate.cpp
    src/models/events/groupvoicestate.h
    src/models/events/selfconnectionstatus.cpp
    src/models/events/selfconnectionstatus.h
    src/models/coreevent.cpp
    src/models/coreevent.h
    src/views/commandview.cpp
    src/views/commandview.h
    src/views/commandview.ui
    src/views/logview.cpp
    src/views/logview.h
    src/views/logview.ui
    src/core.cpp
    src/core.h
    src/coreoptions.cpp
    src/coreoptions.h
    src/debugtox.cpp
    src/debugtox.h
    src/debugtox.ui
    src/logger.cpp
    src/logger.h
    src/main.cpp)

if(COMMAND qt_policy)
  # set QTP0002 policy: target properties that specify Android-specific paths
  # may contain generator expressions
  qt_policy(SET QTP0002 NEW)
endif()

qt_add_executable(${BINARY_NAME} ${PROJECT_SOURCES})

target_link_libraries(${BINARY_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

foreach(pkg in TOXCORE LIBSODIUM)
  target_link_libraries(${BINARY_NAME} PRIVATE ${${pkg}_LIBRARIES})
  target_link_directories(${BINARY_NAME} PRIVATE ${${pkg}_LIBRARY_DIRS})
  target_include_directories(${BINARY_NAME} PRIVATE ${${pkg}_INCLUDE_DIRS})
  target_compile_options(${BINARY_NAME} PRIVATE ${${pkg}_CFLAGS_OTHER})
endforeach()

target_include_directories(${BINARY_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(
  ${BINARY_NAME}
  PROPERTIES QT_ANDROID_TARGET_SDK_VERSION 34
             QT_ANDROID_MIN_SDK_VERSION 24
             QT_ANDROID_PACKAGE_SOURCE_DIR
             "${CMAKE_CURRENT_SOURCE_DIR}/platform/android/${Qt6Core_VERSION}")

include(Installation)

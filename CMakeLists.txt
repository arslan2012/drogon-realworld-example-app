cmake_minimum_required (VERSION 3.5)
project(arslanTech CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(${PROJECT_NAME} main.cc)

##########
# If you include the drogon source code locally in your project, use this method to add drogon
# add_subdirectory(external/drogon)
# target_link_libraries(${PROJECT_NAME} PRIVATE drogon)
##########

find_package(Drogon CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE Drogon::Drogon)

##########
# https://github.com/Thalhammer/jwt-cpp
# project config.cmake installs onto wrong dir
# had to be linked locally
add_subdirectory(external/jwt-cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE jwt-cpp)
##########

##########
# https://github.com/trusch/libbcrypt
# project doesn't have config.cmake file
# linking locally is easier
add_subdirectory(external/libbcrypt)
target_link_libraries(${PROJECT_NAME} PRIVATE bcrypt)
##########

aux_source_directory(controllers CTL_SRC)
aux_source_directory(filters FILTER_SRC)
aux_source_directory(plugins PLUGIN_SRC)
aux_source_directory(models MODEL_SRC)
aux_source_directory(utils UTIL_SRC)

file(GLOB_RECURSE SCP_LIST ${CMAKE_CURRENT_SOURCE_DIR}/views/*.csp)
foreach(cspFile ${SCP_LIST})
    message(STATUS "cspFile:" ${cspFile})
    get_filename_component(classname ${cspFile} NAME_WE)
    message(STATUS "view classname:" ${classname})
    ADD_CUSTOM_COMMAND(OUTPUT ${classname}.h ${classname}.cc
            COMMAND drogon_ctl
            ARGS create view ${cspFile}
            DEPENDS ${cspFile}
            VERBATIM )
    set(VIEWSRC ${VIEWSRC} ${classname}.cc)
endforeach()

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/models)
target_sources(${PROJECT_NAME} PRIVATE ${SRC_DIR} ${CTL_SRC} ${FILTER_SRC} ${VIEWSRC} ${PLUGIN_SRC} ${MODEL_SRC} ${UTIL_SRC})

add_library(everest_staging_util INTERFACE)
add_library(everest::staging::util ALIAS everest_staging_util)
ev_register_library_target(everest_staging_helpers)

target_include_directories(everest_staging_util
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif()

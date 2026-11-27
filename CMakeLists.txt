cmake_minimum_required(VERSION 3.20)
project(Claudaris VERSION 0.1.0 LANGUAGES C)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(CLAUDARIS_BUILD_TESTS "Build Claudaris validation tests" OFF)
option(CLAUDARIS_STRICT_WARNINGS "Enable strict warnings for Claudaris targets" ON)

set(CLAUDARIS_SOURCES
    src/claudaris_abs_diff_i64_u64.c
    src/claudaris_abs_i64_safe_u64.c
    src/claudaris_accumulate_abs_i32.c
    src/claudaris_align_down_u32.c
    src/claudaris_align_up_u32.c
    src/claudaris_ceil_to_multiple_i32.c
    src/claudaris_checked_abs_i64.c
    src/claudaris_checked_add_i64.c
    src/claudaris_checked_add_u64.c
    src/claudaris_checked_mul_i64.c
    src/claudaris_checked_mul_u64.c
    src/claudaris_checked_neg_i64.c
    src/claudaris_checked_shl_i32.c
    src/claudaris_checked_shl_u32.c
    src/claudaris_checked_sub_i64.c
    src/claudaris_checked_sub_u64.c
    src/claudaris_floor_to_multiple_i32.c
    src/claudaris_fraction_compare_i32.c
    src/claudaris_is_aligned_u32.c
    src/claudaris_lookup_clamped_i32.c
    src/claudaris_mask_range_u64.c
    src/claudaris_nearest_multiple_u32.c
    src/claudaris_offset_range_check_u32.c
    src/claudaris_period_align_u32.c
    src/claudaris_period_floor_u32.c
    src/claudaris_range_center_i32.c
    src/claudaris_range_intersects_i32.c
    src/claudaris_range_shrink_i32.c
    src/claudaris_ratio_between_u32.c
    src/claudaris_ratio_ceil_u32.c
    src/claudaris_ratio_round_even_u32.c
    src/claudaris_round_to_multiple_i32.c
    src/claudaris_saturating_add_i64.c
    src/claudaris_saturating_add_u64.c
    src/claudaris_saturating_cast_i64_i32.c
    src/claudaris_saturating_cast_u64_u32.c
    src/claudaris_saturating_mul_u64.c
    src/claudaris_saturating_sub_i64.c
    src/claudaris_saturating_sub_u64.c
    src/claudaris_size_add_checked_u32.c
    src/claudaris_size_mul_checked_u32.c
    src/claudaris_time_convert_ceil_u64.c
    src/claudaris_time_convert_floor_u64.c
    src/claudaris_time_duration_absdiff_u64.c
    src/claudaris_time_duration_clamp_u64.c
    src/claudaris_time_ratio_internal.c
    src/claudaris_time_scale_ratio_u64.c
)

add_library(claudaris STATIC ${CLAUDARIS_SOURCES})
add_library(Claudaris::Claudaris ALIAS claudaris)
target_compile_features(claudaris PUBLIC c_std_99)
target_include_directories(claudaris PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
set_target_properties(claudaris PROPERTIES
    EXPORT_NAME Claudaris
    POSITION_INDEPENDENT_CODE OFF
)

if(CLAUDARIS_STRICT_WARNINGS)
    if(MSVC)
        target_compile_options(claudaris PRIVATE /W4 /WX)
    else()
        target_compile_options(claudaris PRIVATE -Wall -Wextra -Wpedantic -Werror)
    endif()
endif()

if(CLAUDARIS_BUILD_TESTS)
    enable_testing()
    include(CheckLanguage)
    check_language(CXX)
    file(GLOB CLAUDARIS_TEST_SOURCES CONFIGURE_DEPENDS tests/*.c)
    foreach(test_source IN LISTS CLAUDARIS_TEST_SOURCES)
        get_filename_component(test_name "${test_source}" NAME_WE)
        set(test_target "claudaris_${test_name}")
        add_executable("${test_target}" "${test_source}")
        target_link_libraries("${test_target}" PRIVATE Claudaris::Claudaris)
        if(CLAUDARIS_STRICT_WARNINGS)
            if(MSVC)
                target_compile_options("${test_target}" PRIVATE /W4 /WX /UNDEBUG)
            else()
                target_compile_options("${test_target}" PRIVATE -Wall -Wextra -Wpedantic -Werror -UNDEBUG)
            endif()
        elseif(MSVC)
            target_compile_options("${test_target}" PRIVATE /UNDEBUG)
        else()
            target_compile_options("${test_target}" PRIVATE -UNDEBUG)
        endif()
        add_test(NAME "claudaris.${test_name}" COMMAND "${test_target}")
    endforeach()
    if(CMAKE_CXX_COMPILER)
        enable_language(CXX)
        add_executable(claudaris_public_headers_cpp tests/public_headers_cpp.cpp)
        target_link_libraries(claudaris_public_headers_cpp PRIVATE Claudaris::Claudaris)
        set_target_properties(claudaris_public_headers_cpp PROPERTIES
            CXX_STANDARD 11 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)
        add_test(NAME claudaris.public_headers_cpp COMMAND claudaris_public_headers_cpp)
    endif()
endif()

install(TARGETS claudaris EXPORT ClaudarisTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include/claudaris DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(EXPORT ClaudarisTargets NAMESPACE Claudaris::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Claudaris)
configure_package_config_file(cmake/ClaudarisConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ClaudarisConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Claudaris)
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/ClaudarisConfigVersion.cmake
    VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion)
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ClaudarisConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ClaudarisConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Claudaris)

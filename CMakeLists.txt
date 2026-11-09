cmake_minimum_required(VERSION 3.20)
project(claudaris VERSION 0.1.0 LANGUAGES C)

option(CLAUDARIS_BUILD_TESTS "Build the migrated unit tests" ON)

add_library(claudaris STATIC
    src/pc_abs_diff_i64_u64.c
    src/pc_abs_i64_safe_u64.c
    src/pc_accumulate_abs_i32.c
    src/pc_align_down_u32.c
    src/pc_align_up_u32.c
    src/pc_ceil_to_multiple_i32.c
    src/pc_checked_abs_i64.c
    src/pc_checked_add_i64.c
    src/pc_checked_add_u64.c
    src/pc_checked_mul_i64.c
    src/pc_checked_mul_u64.c
    src/pc_checked_neg_i64.c
    src/pc_checked_shl_i32.c
    src/pc_checked_shl_u32.c
    src/pc_checked_sub_i64.c
    src/pc_checked_sub_u64.c
    src/pc_floor_to_multiple_i32.c
    src/pc_fraction_compare_i32.c
    src/pc_is_aligned_u32.c
    src/pc_lookup_clamped_i32.c
    src/pc_mask_range_u64.c
    src/pc_nearest_multiple_u32.c
    src/pc_offset_range_check_u32.c
    src/pc_period_align_u32.c
    src/pc_period_floor_u32.c
    src/pc_range_center_i32.c
    src/pc_range_intersects_i32.c
    src/pc_range_shrink_i32.c
    src/pc_ratio_between_u32.c
    src/pc_ratio_ceil_u32.c
    src/pc_ratio_round_even_u32.c
    src/pc_round_to_multiple_i32.c
    src/pc_saturating_add_i64.c
    src/pc_saturating_add_u64.c
    src/pc_saturating_cast_i64_i32.c
    src/pc_saturating_cast_u64_u32.c
    src/pc_saturating_mul_u64.c
    src/pc_saturating_sub_i64.c
    src/pc_saturating_sub_u64.c
    src/pc_saturating_sub_u64.c
    src/pc_size_add_checked_u32.c
    src/pc_size_mul_checked_u32.c
    src/pc_time_convert_ceil_u64.c
    src/pc_time_convert_floor_u64.c
    src/pc_time_duration_absdiff_u64.c
    src/pc_time_duration_clamp_u64.c
    src/pc_time_ratio_internal.c
    src/pc_time_scale_ratio_u64.c
)

target_include_directories(claudaris PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/claudaris/arithmetic>
    $<INSTALL_INTERFACE:include>
)
target_compile_features(claudaris PUBLIC c_std_99)
set_target_properties(claudaris PROPERTIES POSITION_INDEPENDENT_CODE OFF)

if(CLAUDARIS_BUILD_TESTS)
    enable_testing()
    file(GLOB CLAUDARIS_TEST_SOURCES CONFIGURE_DEPENDS tests/*.c)
    foreach(test_source IN LISTS CLAUDARIS_TEST_SOURCES)
        get_filename_component(test_name "${test_source}" NAME_WE)
        add_executable("claudaris_${test_name}" "${test_source}")
        target_include_directories("claudaris_${test_name}" PRIVATE
            ${CMAKE_CURRENT_SOURCE_DIR}/include/claudaris/arithmetic)
        target_link_libraries("claudaris_${test_name}" PRIVATE claudaris)
        add_test(NAME "${test_name}" COMMAND "claudaris_${test_name}")
    endforeach()
endif()

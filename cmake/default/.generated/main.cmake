include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(__default_library_list )

set(OUTPUT_SUFFIX elf)
# Handle files with suffix s, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_assemble)
add_library(A___default_default_AVR_GCC_assemble OBJECT ${__default_default_AVR_GCC_FILE_TYPE_assemble})
    A___default_default_AVR_GCC_assemble_rule(A___default_default_AVR_GCC_assemble)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_assemble>")

endif()

# Handle files with suffix S, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_assembleWithPreprocess)
add_library(A___default_default_AVR_GCC_assembleWithPreprocess OBJECT ${__default_default_AVR_GCC_FILE_TYPE_assembleWithPreprocess})
    A___default_default_AVR_GCC_assembleWithPreprocess_rule(A___default_default_AVR_GCC_assembleWithPreprocess)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_compile)
add_library(A___default_default_AVR_GCC_compile OBJECT ${__default_default_AVR_GCC_FILE_TYPE_compile})
    A___default_default_AVR_GCC_compile_rule(A___default_default_AVR_GCC_compile)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_compile>")

endif()

# Handle files with suffix cpp, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_compile_cpp)
add_library(A___default_default_AVR_GCC_compile_cpp OBJECT ${__default_default_AVR_GCC_FILE_TYPE_compile_cpp})
    A___default_default_AVR_GCC_compile_cpp_rule(A___default_default_AVR_GCC_compile_cpp)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_compile_cpp>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_ihex)
add_library(A___default_default_AVR_GCC_objcopy_ihex OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_ihex})
    A___default_default_AVR_GCC_objcopy_ihex_rule(A___default_default_AVR_GCC_objcopy_ihex)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_ihex>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_eep)
add_library(A___default_default_AVR_GCC_objcopy_eep OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_eep})
    A___default_default_AVR_GCC_objcopy_eep_rule(A___default_default_AVR_GCC_objcopy_eep)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_eep>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_lss)
add_library(A___default_default_AVR_GCC_objcopy_lss OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_lss})
    A___default_default_AVR_GCC_objcopy_lss_rule(A___default_default_AVR_GCC_objcopy_lss)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_lss>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_srec)
add_library(A___default_default_AVR_GCC_objcopy_srec OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_srec})
    A___default_default_AVR_GCC_objcopy_srec_rule(A___default_default_AVR_GCC_objcopy_srec)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_srec>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_sig)
add_library(A___default_default_AVR_GCC_objcopy_sig OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_sig})
    A___default_default_AVR_GCC_objcopy_sig_rule(A___default_default_AVR_GCC_objcopy_sig)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_sig>")

endif()

# Handle files with suffix elf, for group default-AVR-GCC
if(__default_default_AVR_GCC_FILE_TYPE_objcopy_memusage)
add_library(A___default_default_AVR_GCC_objcopy_memusage OBJECT ${__default_default_AVR_GCC_FILE_TYPE_objcopy_memusage})
    A___default_default_AVR_GCC_objcopy_memusage_rule(A___default_default_AVR_GCC_objcopy_memusage)
    list(APPEND __default_library_list "$<TARGET_OBJECTS:A___default_default_AVR_GCC_objcopy_memusage>")

endif()


# Main target for this project
add_executable(__default_image_ibBJG6UR ${__default_library_list})

set_target_properties(__default_image_ibBJG6UR PROPERTIES
    OUTPUT_NAME "default"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${__default_output_dir}")
target_link_libraries(__default_image_ibBJG6UR PRIVATE ${__default_default_AVR_GCC_FILE_TYPE_link})
# Add the link options from the rule file.
A___default_link_rule( __default_image_ibBJG6UR)


#Add objcopy steps
A___default_objcopy_ihex_rule(__default_image_ibBJG6UR)
A___default_objcopy_eep_rule(__default_image_ibBJG6UR)
A___default_objcopy_lss_rule(__default_image_ibBJG6UR)
A___default_objcopy_srec_rule(__default_image_ibBJG6UR)
A___default_objcopy_sig_rule(__default_image_ibBJG6UR)
A___default_objcopy_memusage_rule(__default_image_ibBJG6UR)


generate_bin_name(LIB)
message("library name is [${LIB}]")

#[[ add_definitions("-fdeclspec") ]]
koll_add_lib(
LIB_NAME
    ${LIB}
PRIVATE
    kTimerManager.cc
)
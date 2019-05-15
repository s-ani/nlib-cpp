
load(
    "//nlib:build_config/default_config.bzl",
    "NLIB_GCC_EXCEPTIONS_FLAGS",
    "NLIB_GCC_FLAGS",
    "NLIB_GCC_TEST_FLAGS",
    "NLIB_MSVC_EXCEPTIONS_FLAGS",
    "NLIB_MSVC_FLAGS",
    "NLIB_MSVC_LINKOPTS",
    "NLIB_MSVC_TEST_FLAGS",
)

NLIB_DEFAULT_COPTS = select({
    "//nlib:windows": NLIB_MSVC_FLAGS,
    "//conditions:default": NLIB_GCC_FLAGS,
})


NLIB_TEST_COPTS = NLIB_DEFAULT_COPTS + select({
    "//nlib:windows": NLIB_MSVC_TEST_FLAGS,
    "//conditions:default": NLIB_GCC_TEST_FLAGS,
})

NLIB_EXCEPTIONS_FLAG = select({
    "//nlib:windows": NLIB_MSVC_EXCEPTIONS_FLAGS,
    "//conditions:default": NLIB_GCC_EXCEPTIONS_FLAGS,
})

NLIB_EXCEPTIONS_FLAG_LINKOPTS = select({
    "//conditions:default": [],
})

NLIB_DEFAULT_LINKOPTS = select({
    "//nlib:windows": NLIB_MSVC_LINKOPTS,
    "//conditions:default": [],
})

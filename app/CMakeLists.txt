# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_definitions(-DPHYSFS_NO_CDROM_SUPPORT)

include_directories(
    ../src
    )

add_library( # Sets the name of the library.
             physfs-lib

             # Sets the library as a shared library.
             SHARED

             # Provides a relative path to your source file(s).
             ../src/physfs_jni.cpp
             ../src/physfs_byteorder.c
             ../src/physfs_unicode.c
             ../src/physfs.c
             ../src/platform/android.c
             ../src/platform/posix.c
             ../src/platform/unix.c
             ../src/archivers/dir.c
             ../src/archivers/grp.c
             ../src/archivers/hog.c
             ../src/archivers/mvl.c
             ../src/archivers/qpak.c
             ../src/archivers/wad.c
             ../src/archivers/zip.c )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       physfs-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )
LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libphysfs

LOCAL_CFLAGS := -fsigned-char \
-D_REENTRANT -D_THREAD_SAFE -DPHYSFS_SUPPORTS_ZIP=1 \
-DPHYSFS_SUPPORTS_GRP=1 \
-DPHYSFS_SUPPORTS_WAD=1 -DPHYSFS_SUPPORTS_HOG=1 \
-DPHYSFS_SUPPORTS_MVL=1 -DPHYSFS_SUPPORTS_QPAK=1 \
-DPHYSFS_NO_CDROM_SUPPORT=1

LOCAL_CPPFLAGS := $(LOCAL_CFLAGS)

PHYSFS_SRC_DIR := $(LOCAL_PATH)/../src


PHYSFS_SRCS := $(PHYSFS_SRC_DIR)/physfs.c \
$(PHYSFS_SRC_DIR)/physfs_byteorder.c \
$(PHYSFS_SRC_DIR)/physfs_unicode.c \
$(PHYSFS_SRC_DIR)/platform/unix.c \
$(PHYSFS_SRC_DIR)/platform/posix.c \
$(PHYSFS_SRC_DIR)/platform/android.c \
$(PHYSFS_SRC_DIR)/archivers/dir.c \
$(PHYSFS_SRC_DIR)/archivers/grp.c \
$(PHYSFS_SRC_DIR)/archivers/hog.c \
$(PHYSFS_SRC_DIR)/archivers/mvl.c \
$(PHYSFS_SRC_DIR)/archivers/qpak.c \
$(PHYSFS_SRC_DIR)/archivers/wad.c \
$(PHYSFS_SRC_DIR)/archivers/zip.c \
$(LOCAL_PATH)/com_physfs_PhysFSWrapper.cpp

LOCAL_SRC_FILES :=  $(PHYSFS_SRCS)


LOCAL_C_INCLUDES := $(PHYSFS_SRC_DIR) 

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_C_INCLUDES)

LOCAL_LDLIBS := -lz -llog

include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)

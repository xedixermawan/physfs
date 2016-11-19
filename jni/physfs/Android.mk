LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libphysfs

LOCAL_SRC_FILES :=  $(LOCAL_PATH)/com_physfs_PhysFSWrapper.cpp

LOCAL_STATIC_LIBRARIES := physfs_static

LOCAL_LDLIBS := -llog

include $(BUILD_SHARED_LIBRARY)
include $(CLEAR_VARS)

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := libcurl_static
LOCAL_SRC_FILES := $(TARGET_ARCH_ABI)/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include

include $(PREBUILT_STATIC_LIBRARY)

include $(CLEAR_VARS)

LOCAL_MODULE := libcurl
LOCAL_SHARED_LIBRARIES := openssl opencrypto
LOCAL_STATIC_LIBRARIES := libcurl_static
LOCAL_C_INCLUDES += $(LOCAL_PATH)/include

#include $(BUILD_SHARED_LIBRARY)
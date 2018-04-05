LOCAL_PATH := $(call my-dir)

#Test Library
include $(CLEAR_VARS)
LOCAL_MODULE := libcurl
LOCAL_SRC_FILES := native/testlibrary.cpp
LOCAL_STATIC_LIBRARIES := libcurl_static
COMMON_CFLAGS := -Werror -DANDROID 

ifeq ($(TARGET_ARCH),arm)
  LOCAL_CFLAGS := -mfpu=vfp -mfloat-abi=softfp -fno-short-enums
endif

LOCAL_CFLAGS += $(COMMON_CFLAGS)
LOCAL_LDLIBS := -lz -llog -Wl,-s
LOCAL_CPPFLAGS += -std=gnu++0x
LOCAL_C_INCLUDES += \
  $(NDK_PATH)/platforms/$(TARGET_PLATFORM)/arch-$(TARGET_ARCH)/usr/include \
  $(LOCAL_PATH)/../libcurl/include

include $(BUILD_SHARED_LIBRARY)
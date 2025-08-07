LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := flashlight_driver
LOCAL_SRC_FILES := flashlight_driver.c
LOCAL_MODULE_TAGS := optional
LOCAL_MODULE_CLASS := misc
LOCAL_MODULE_SUFFIX := .ko
LOCAL_LICENSE := GPL

include $(BUILD_MODULE)

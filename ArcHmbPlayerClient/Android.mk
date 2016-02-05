LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE_TAGS := optional
LOCAL_SHARED_LIBRARIES := libutils libcutils libbinder

LOCAL_SRC_FILES := ../ArcHmbPlayerInterface/ArcHmbPlayerInterface.cpp 
LOCAL_SRC_FILES += ArcHmbPlayerBinderProxy.cpp ArcHmbPlayerClient.cpp

LOCAL_C_INCLUDES += frameworks/native/include \
					system/core/include
					
LOCAL_MODULE := arcplayer_client
					
include $(BUILD_EXECUTABLE)




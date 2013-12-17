#!/bin/sh
echo 'LOCAL_PATH := $(call my-dir)'
echo ""
echo 'include $(CLEAR_VARS)'
echo ""
echo 'LOCAL_MODULE := cocos2dcpp_shared'
echo ""
echo 'LOCAL_MODULE_FILENAME := libcocos2dcpp'
echo ""
echo "LOCAL_SRC_FILES := hellocpp/main.cpp \\"
while read data; do
    echo "                   ../$data \\"
done
echo ""
echo 'LOCAL_C_INCLUDES := $(LOCAL_PATH)/../Classes'
echo ""
echo 'LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static'
echo 'LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static'
echo 'LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static'
echo 'LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static'
echo 'LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static'
echo ""
echo 'include $(BUILD_SHARED_LIBRARY)'
echo ""
echo '$(call import-module,cocos2dx)'
echo '$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)'
echo '$(call import-module,CocosDenshion/android)'
echo '$(call import-module,extensions)'
echo '$(call import-module,external/Box2D)'
echo '$(call import-module,external/chipmunk)'

LOCAL_PATH := $(call my-dir)

LOCAL_BASE_MODULES := $(call all-makefiles-under,$(LOCAL_PATH)/$(MTK_BASE_PROJECT))
LOCAL_PLATFORM_MODULES := $(call all-makefiles-under, $(LOCAL_PATH)/$(shell echo $(MTK_PLATFORM) | tr '[A-Z]' '[a-z]'))

define all-c-cpp-files-under
$(patsubst ./%,%, \
  $(shell cd $(LOCAL_PATH) ; \
          find $(1) -maxdepth 1 \( -name "*.c" -or -name "*.cpp" \) -and -not -name ".*") \
 )
endef

ifneq ($(MTK_EMULATOR_SUPPORT), yes)
include $(LOCAL_BASE_MODULES) $(LOCAL_PLATFORM_MODULES)
else
include $(LOCAL_BASE_MODULES)
endif

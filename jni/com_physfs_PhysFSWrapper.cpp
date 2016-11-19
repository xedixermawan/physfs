#include "com_physfs_PhysFSWrapper.h"

#include <linux/limits.h>
#include <cstring>
#include <android/log.h>

extern char PHYSFS_android_platform_base_dir[PATH_MAX];
extern char PHYSFS_android_platform_user_dir[PATH_MAX];

JNIEXPORT void JNICALL Java_com_physfs_PhysFSWrapper_setDirs
  (JNIEnv *env, jobject obj, jstring base_dir, jstring user_dir){
	  const char *base_dir_str = env->GetStringUTFChars(base_dir, 0);
	  if(base_dir_str){
		  strncpy(PHYSFS_android_platform_base_dir, base_dir_str, env->GetStringUTFLength(base_dir));
		  env->ReleaseStringUTFChars(base_dir, base_dir_str);
	  }
	  const char *user_dir_str = env->GetStringUTFChars(user_dir, 0);
	  if(user_dir_str){
		  strncpy(PHYSFS_android_platform_user_dir, user_dir_str, env->GetStringUTFLength(user_dir));
		  env->ReleaseStringUTFChars(user_dir, user_dir_str);
	  }
	  __android_log_print(ANDROID_LOG_DEBUG, "physfs", "PHYSFS_android_platform_base_dir: %s", PHYSFS_android_platform_base_dir);
	  __android_log_print(ANDROID_LOG_DEBUG, "physfs", "PHYSFS_android_platform_user_dir: %s", PHYSFS_android_platform_user_dir);
  }

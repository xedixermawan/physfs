#include "com_physfs_PhysFSWrapper.h"

#include <linux/limits.h>
#include <cstring>
#include <android/log.h>

#include "physfs.h"

extern "C" void __PHYSFS_android_platform_SetBaseDir(const char *base_dir);
extern "C" void __PHYSFS_android_platform_SetUserDir(const char *user_dir);

JNIEXPORT void JNICALL Java_com_physfs_PhysFSWrapper_setDirs
  (JNIEnv *env, jobject obj, jstring base_dir, jstring user_dir){
	  const char *base_dir_str = env->GetStringUTFChars(base_dir, 0);
	  if(base_dir_str){
		  __PHYSFS_android_platform_SetBaseDir(base_dir_str);
		  env->ReleaseStringUTFChars(base_dir, base_dir_str);
	  }
	  const char *user_dir_str = env->GetStringUTFChars(user_dir, 0);
	  if(user_dir_str){
		  __PHYSFS_android_platform_SetUserDir(user_dir_str);
		  env->ReleaseStringUTFChars(user_dir, user_dir_str);
	  }
  }

  //TODO: write your code here
  JNIEXPORT void JNICALL Java_com_physfs_PhysFSWrapper_test
  (JNIEnv *, jobject){
	  PHYSFS_init(0);
	  PHYSFS_setSaneConfig("organization", "myappName", "zip", 0, 1);
	  __android_log_print(ANDROID_LOG_DEBUG, "physfs", "PHYSFS_getBaseDir: %s",PHYSFS_getBaseDir());
  }
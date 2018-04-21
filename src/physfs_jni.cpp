
#include <jni.h>
#include <string>
#include "physfs.h"

extern "C"
JNIEXPORT void
JNICALL
Java_com_physfs_appfs_bridge_PHYSFS_1init(
        JNIEnv *env,
        jobject /* this */) {
    PHYSFS_init(0);
}

extern "C"
JNIEXPORT void
JNICALL
Java_com_physfs_appfs_bridge_PHYSFS_AddToSearchPath(
        JNIEnv *env,
        jobject /* this */) {

}

extern "C"
JNIEXPORT void
JNICALL
Java_com_physfs_appfs_bridge_PHYSFS_exists(
        JNIEnv *env,
        jobject /* this */) {

}

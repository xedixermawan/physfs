#include <string.h>
#include <linux/limits.h>

#define __PHYSICSFS_INTERNAL__
#include "physfs_internal.h"

char PHYSFS_android_platform_base_dir[PATH_MAX] = {0};
char PHYSFS_android_platform_user_dir[PATH_MAX] = {0};

char *__PHYSFS_platformGetUserName(void)
{
	return NULL;
}

char *__PHYSFS_platformCalcBaseDir(const char *argv0)
{
	char *retval = (char *) allocator.Malloc(PATH_MAX);
	if (retval != NULL){
		memset(retval, '\0', sizeof(char) * PATH_MAX);
		strncpy(retval, PHYSFS_android_platform_base_dir, PATH_MAX);
	}
	return retval;
}

char *__PHYSFS_platformGetUserDir(void)
{
	char *retval = (char *) allocator.Malloc(PATH_MAX);
	if (retval != NULL){
		memset(retval, '\0', sizeof(char) * PATH_MAX);
		strncpy(retval, PHYSFS_android_platform_user_dir, PATH_MAX);
	}
	return retval;
}

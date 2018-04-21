package com.physfs;

/**
 * Created by xedi on 20/04/18.
 */

public class bridge {
    static {
        System.loadLibrary("physfs-lib");
    }

    public native void PHYSFS_init();
    public native void PHYSFS_AddToSearchPath();
    public native void PHYSFS_exists();
    public native void PHYSFS_openRead();
    public native void PHYSFS_fileLength();
    public native void PHYSFS_read();
    public native void PHYSFS_close();
    public native void PHYSFS_deinit();

}

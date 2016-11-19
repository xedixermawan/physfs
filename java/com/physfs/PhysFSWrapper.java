package com.physfs;

public class PhysFSWrapper {
	static {
		System.loadLibrary("physfs");
	}

	/**
	 * provide base_dir for PHYSFS_getBaseDir() and  and user_dir for PHYSFS_getUserDir(), 
	 * @see PHYSFS_getBaseDir(), PHYSFS_getUserDir()
	 * example:
	 * PhysFSWrapper physFSWrapper = new PhysFSWrapper();
	 * physFSWrapper.setDirs(Environment.getExternalStorageDirectory().getAbsolutePath(), getCacheDir().getAbsolutePath()); 
	 * 
	 * NOTE: only ExternalStorageDirectory (like "/storage/emulated/0") is supported as base_dir in this version..
	 **/
	public native void setDirs(String base_dir, String user_dir);
}

package com.ecarx.enlu.utils;

import com.sun.jna.Library;
import com.sun.jna.Native;

/**
 * @desc 底层库函数 桥接
 */
public interface Clibrary extends Library {

    Clibrary INSTANCE = Native.loadLibrary("sqliteUtil",Clibrary.class);

    int create_alarm ();
    int insert_alarm();
}

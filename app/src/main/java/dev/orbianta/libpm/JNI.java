package dev.orbianta.libpm;

public class JNI
{

    static
    {
        System.loadLibrary("pm");
    }

    public static native void request_root_perm();
    public static native int exec_boot_on_recovery();
    public static native int exec_boot_on_download_mode();
    public static native int exec_reboot();
    public static native int exec_shutdown();

}

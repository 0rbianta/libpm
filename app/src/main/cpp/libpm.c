#include <jni.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

#define su_path "/bin/su"

int exec(char *command, char **argv, int wait_child_done)
{
    pid_t cp;
    cp = fork();

    if (cp == -1)
        return -1;
    else if(cp == 0)
    {
        int exec_res = execvp(command, argv);
        if (exec_res == -1)
            return -1;
    }
    else if(wait_child_done)
        waitpid(cp, NULL, 0);


    return cp;
}

JNIEXPORT void JNICALL
Java_dev_orbianta_libpm_JNI_request_1root_1perm(JNIEnv *env, jclass clazz)
{

    char *argv[] = {su_path, NULL};
    exec(su_path, argv, 1);
}


JNIEXPORT jint JNICALL
Java_dev_orbianta_libpm_JNI_exec_1boot_1on_1recovery(JNIEnv *env, jclass clazz)
{

    char *argv[] = {su_path, "-c", "svc power reboot recovery", NULL};
    pid_t ret = exec(su_path, argv, 0);
    return ret;
}

JNIEXPORT jint JNICALL
Java_dev_orbianta_libpm_JNI_exec_1reboot(JNIEnv *env, jclass clazz) {

    char *argv[] = {su_path, "-c", "svc power reboot", NULL};
    pid_t ret = exec(su_path, argv, 0);
    return ret;
}

JNIEXPORT jint JNICALL
Java_dev_orbianta_libpm_JNI_exec_1shutdown(JNIEnv *env, jclass clazz) {

    char *argv[] = {su_path, "-c", "svc power shutdown", NULL};
    pid_t ret = exec(su_path, argv, 0);
    return ret;

}

JNIEXPORT jint JNICALL
Java_dev_orbianta_libpm_JNI_exec_1boot_1on_1download_1mode(JNIEnv *env, jclass clazz) {

    char *argv[] = {su_path, "-c", "svc power reboot download", NULL};
    pid_t ret = exec(su_path, argv, 0);
    return ret;

}
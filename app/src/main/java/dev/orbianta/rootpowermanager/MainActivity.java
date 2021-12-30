package dev.orbianta.rootpowermanager;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import dev.orbianta.libpm.JNI;
import dev.orbianta.rootpowermanager.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {



    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());



    }


    public void boot_on_recovery_btn_click(View v)
    {
        JNI.request_root_perm();
        int res = JNI.exec_boot_on_recovery();

    }

    public void boot_on_download_mode_btn_click(View v)
    {
        JNI.request_root_perm();
        int res = JNI.exec_boot_on_download_mode();
    }

    public void reboot_btn_click(View v)
    {
        JNI.request_root_perm();
        int res = JNI.exec_reboot();
    }

    public void shutdown_btn_click(View v)
    {
        JNI.request_root_perm();
        int res = JNI.exec_shutdown();
    }


}
package com.example.brigittebroszus.hw17;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    int sum_mr = 0; // the sum of the mass times the radius
    int sum_m = 0; // the sum of the masses
                for (int i = 0; i < bmp.getWidth(); i++) {
        if ( (red(pixels[i]) - (green(pixels[i])+blue(pixels[i]))/2) > -R)  && (red(pixels[i]) - (green(pixels[i])+blue(pixels[i]))/2) < R) &&(red(pixels[i])  > T)) {
            pixels[i] = rgb(1, 1, 1); // set the pixel to almost 100% black

            sum_m = sum_m + green(pixels[i])+red(pixels[i])+blue(pixels[i]);
            sum_mr = sum_mr + (green(pixels[i])+red(pixels[i])+blue(pixels[i]))*i;
        }
    }
    // only use the data if there were a few pixels identified, otherwise you might get a divide by 0 error
                if(sum_m>5){
        COM = sum_mr / sum_m;
    }
                else{
        COM = 0;
}

#include "ImgFunctions.h"

RgbImg rainbow() {
    RgbImg img = createRgbImg(100,700,{0,0,255});
    RGB colour_codes[7]={{0,0,255},{0,165,255},{0,255,255},{0,128,0},{250,144,30},{255,0,0},{128,0,128}};
    for(size_t k=0;k<7;++k)
        for(size_t i=0;i<100;++i)
            for(size_t j=0;j<100;++j)
                img.pixels[i][j+k*100]=colour_codes[k];
    return img;
}

void rotation(const char* filename, int angle, const char* output) {
    if(angle%360!=0) {
        RgbImg img = readRgbImg(filename);
        size_t width = (angle % 180 == 90 || angle % 180 == 270 ? img.height : img.width);
        size_t height = (angle % 180 == 90 || angle % 180 == 270 ? img.width : img.height);
        RgbImg rotated_img = createRgbImg(height, width);

        for (size_t i = 0; i < height; ++i)
            for (size_t j = 0; j < width; ++j)
                if (angle % 360 == 180) rotated_img.pixels[i][j] = img.pixels[height - 1 - i][width - 1 - j];
                else if (angle % 360 == 270) rotated_img.pixels[i][j] = img.pixels[j][height - 1 - i];
                else if (angle % 360 == 90) rotated_img.pixels[i][j] = img.pixels[width - 1 - j][i];
        writeRgbImg(output, rotated_img);
    }
}

void shades_of_gray(const char* filename, const char* output){
    RgbImg img = readRgbImg(filename);
    RgbImg gray_img = createRgbImg(img.height,img.width);
    for (size_t i = 0; i < img.height; ++i)
        for (size_t j = 0; j < img.width; ++j) {
            BYTE temp = (img.pixels[i][j].Blue + img.pixels[i][j].Green + img.pixels[i][j].Red) / 3;
            gray_img.pixels[i][j]={temp,temp,temp};
        }
    writeRgbImg(output, gray_img);
}

void sharpness(const char* filename, const char* output){
    RgbImg img = readRgbImg(filename);
    RgbImg new_img = createRgbImg(img.height,img.width);

    for (size_t i = 0; i < img.height; ++i)
        for (size_t j = 0; j < img.width; ++j) {
            new_img.pixels[i][j].Blue = 0;
            new_img.pixels[i][j].Red = 0;
            new_img.pixels[i][j].Green = 0;
            for (int k1 = -2; k1 < 3; ++k1)
                for (int k2 = -2; k2 < 3; ++k2){
                    if ((i+k1>=0 && i+k1 < img.height)&&(j+k2>=0 && j+k2 < img.width)){
                    new_img.pixels[i][j].Blue += img.pixels[i+k1][j+k2].Blue/25;
                    new_img.pixels[i][j].Red += img.pixels[i+k1][j+k2].Red/25;
                    new_img.pixels[i][j].Green += img.pixels[i+k1][j+k2].Green/25;}
                }
        }

    int s_ker[3][3]={{0,-1,0},{-1,5,-1},{0,-1,0}};
    for (size_t i = 0; i < img.height; ++i)
        for (size_t j = 0; j < img.width; ++j) {
            img.pixels[i][j].Blue = 0;
            img.pixels[i][j].Red = 0;
            img.pixels[i][j].Green = 0;
            for (int k1 = -1; k1 < 2; ++k1)
                for (int k2 = -1; k2 < 2; ++k2){
                    if ((i+k1>=0 && i+k1 < img.height)&&(j+k2>=0 && j+k2 < img.width)){
                        img.pixels[i][j].Blue += new_img.pixels[i+k1][j+k2].Blue*s_ker[k1+1][k2+1];
                        img.pixels[i][j].Red += new_img.pixels[i+k1][j+k2].Red*s_ker[k1+1][k2+1];
                        img.pixels[i][j].Green += new_img.pixels[i+k1][j+k2].Green*s_ker[k1+1][k2+1];}
                }
        }

    writeRgbImg(output, img);
}

void swapping(BYTE* x, BYTE* y){
    BYTE tmp=*x;
    x=y;
    *y=tmp;
}

void insertion_sort(BYTE* x, size_t len){
    if (!len) return;
    for (size_t i = 1; i < len; i++)
        for (size_t j = i; j+1 > 1 && x[j - 1] > x[j]; j--)
            swapping(x+j,x+j - 1);

}

void median(const char* filename, const char* output,int N) {
    RgbImg img = readRgbImg(filename);
    RgbImg new_img = createRgbImg(img.height, img.width);
    for (size_t i = 0; i < img.height; ++i)
        for (size_t j = 0; j < img.width; ++j) {
            int len = N*N;
            BYTE colors[3][len];size_t l=0;
                for (int k1 = -N/2; k1 < N/2+1; ++k1)
                    for (int k2 = -N/2; k2 < N/2+1; ++k2) {
                        if ((i + k1 >= 0 && i + k1 < img.height) && (j + k2 >= 0 && j + k2 < img.width)) {
                            colors[0][l]=img.pixels[i+k1][j+k2].Blue;
                            colors[1][l]=img.pixels[i+k1][j+k2].Green;
                            colors[2][l]=img.pixels[i+k1][j+k2].Red;
                            ++l;
                        }
                        for(size_t l2=0;l2<3 && l>0;++l2) {
                            insertion_sort(colors[l2], l);
                        }
                    }
                new_img.pixels[i][j]={colors[0][(l+1)/2],colors[1][(l+1)/2],colors[2][(l+1)/2]};
        }
    writeRgbImg(output, new_img);
}
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "/includes/gd.h"

#define VARNAME argv[1]
#define FILENAME argv[2]

int rgb_conv(int r, int g, int b)
{
    r = (int) round((double) r * (31.0 / 255.0));
    g = (int) round((double) g * (31.0 / 255.0));
    b = (int) round((double) b * (31.0 / 255.0));
    printf("%d, %d, %d", r, g, b);
    exit(0);
    return r | (g << 5) | (b << 10);
}

int valid_varname(char *s)
{
    if (!*s || isdigit(*s))
        return 0;
    while (*s) {
        if (!isalpha(*s) && !isdigit(*s) && *s != '_')
            return 0;
        s++;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr,
            "Converts a gif/png/jpg to a c array of a 16-bit bitmap, "
            "format {x, y, data}\n"
            "Need var name as first arg, valid image file as second arg\n"
            "(Compact mode on if third arg is 1)");
        return -1;
    }

    if (!valid_varname(VARNAME)) {
        fprintf(stderr, "Invalid C varname %s ", VARNAME);
        return -2;
    }

    FILE *imgdata;
    gdImagePtr img = NULL;
    char header[4];
    int w, h;
    int x, y;
    int i;
    int type, color, rgb;
    int compact = atoi(argv[3]);

    imgdata = fopen(FILENAME, "rb");

    if (!imgdata)
    { fprintf(stderr, "File %s read error: does not exist?\n", FILENAME); return -4; }

    img = gdImageCreateFromJpeg(imgdata);
    if (!img)
    img = gdImageCreateFromGif(imgdata);
    if (!img)
    img = gdImageCreateFromPng(imgdata);
    
    if (!img) {
        fprintf(stderr, "File %s is invalid %s\n", FILENAME,
                type == 0 ? "JPG" : type == 1 ?
                "GIF" : type == 2 ? "PNG" : "image");
        return -5;
    }

    fclose(imgdata);

    w = img->sx;
    h = img->sy;

    printf("/* 16-bit GBA bitmap array generated by imgtogba */\n\n");
    printf("const unsigned short %s[] = {\n/* xdim  ydim, */\n", VARNAME);
    printf("   %4d, %4d\n", w, h);

    if (compact == 1) {
        for (y = i = 0; y < h; ++y) {
            for (x = 0; x < w; ++x) {
                color = gdImageGetPixel(img, x, y);
                rgb = rgb_conv(
                        gdImageRed(img, color),
                        gdImageGreen(img, color),
                        gdImageBlue(img, color)
                        );
                printf(",%d", rgb);
            }
        }
    } else {
        for (y = i = 0; y < h; ++y) {
            for (x = 0; x < w; ++x) {
                color = gdImageGetPixel(img, x, y);
                rgb = rgb_conv(
                        gdImageRed(img, color),
                        gdImageGreen(img, color),
                        gdImageBlue(img, color)
                        );
                printf("%s0x%04x", (i++ % 10 ? ", " : ",\n"), rgb);
            }
        }
    }

    printf("};");
    gdImageDestroy(img);
    return 0;
}

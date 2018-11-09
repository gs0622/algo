/*
 * arm-eabi-gcc -c -march=armv7-a -mfloat-abi=softfp -mfpu=neon rgb.c
 */
/** rgb_convert
 *
 *  convert RGB565 to RGB888, 8 pixels per loop
 *
 *  Note: version-1 reduce from 79 to 16.5 ms (540x960 pxs)
 */
void rgb_convert(unsigned short *src, unsigned int *dst, unsigned int pxs)
{
        __asm__ volatile (
                "       cmp          %[s], #0\r\n"
                "       beq          2f\r\n"
                "       vmov.i32     d5, #0\r\n"
                "1:     vldmia       %[i]!, {q0}\r\n"
                "       vshr.u8      q1, q0, #3\r\n"
                "       vshrn.i16    d4, q1, #5\r\n"
                "       vshrn.i16    d3, q0, #5\r\n"
                "       vshl.i8      d3, d3, #2\r\n"
                "       vshl.i16     q0, q0, #3\r\n"
                "       vmovn.i16    d2, q0\r\n"
                "       vst4.8       {d2, d3, d4, d5}, [%[o]]!\r\n"
                "       subs         %[s], %[s], #8\r\n"
                "       bne          1b\r\n"
                "2:\r\n"
        :: [i] "r" (src), [o] "r" (dst), [s] "r" (pxs)
        );
}

/** rgb_convert
 *
 *  convert RGB565 to RGB888, 16 pixels per loop
 *
 *  Note: version-1 16.5 ms, version-2 down to 8.5 ms (540x960 pxs)
 */
void rgb_convert(unsigned short *src, unsigned int *dst, unsigned int pxs)
{
        __asm__ volatile (
                "       cmp          %[s], #0\r\n"
                "       beq          2f\r\n"
                "       vmov.i32     d5, #0\r\n"
                "       vmov.i32     d11, #0\r\n"
                "1:     vldmia       %[i]!, {q0}\r\n"
                "       vldmia       %[i]!, {q3}\r\n"
                "       vshr.u8      q1, q0, #3\r\n"
                "       vshr.u8      q4, q3, #3\r\n"
                "       vshrn.i16    d4, q1, #5\r\n"
                "       vshrn.i16    d10, q4, #5\r\n"
                "       vshrn.i16    d3, q0, #5\r\n"
                "       vshrn.i16    d9, q3, #5\r\n"
                "       vshl.i8      d3, d3, #2\r\n"
                "       vshl.i8      d9, d9, #2\r\n"
                "       vshl.i16     q0, q0, #3\r\n"
                "       vshl.i16     q3, q3, #3\r\n"
                "       vmovn.i16    d2, q0\r\n"
                "       vmovn.i16    d8, q3\r\n"
                "       vst4.8       {d2, d3, d4, d5}, [%[o]]!\r\n"
                "       vst4.8       {d8, d9, d10, d11}, [%[o]]!\r\n"
                "       subs         %[s], %[s], #16\r\n"
                "       bne          1b\r\n"
                "2:\r\n"
        :: [i] "r" (src), [o] "r" (dst), [s] "r" (pxs)
        );
}

void initialize_fb_datapart(unsigned long *fbbuf,  int wfb,int hfb, unsigned short* data,int flip)
{
    int i=0, pxs=wfb*hfb;
    int r,g,b;

    if (0==(pxs&15)) {
        unsigned long *dst = (MEMTYPE_NONCACHE == chipset_get_mem_cache_type(fbbuf))? \
            chipset_noncache_to_cache(fbbuf) : fbbuf;
        rgb_convert(data, dst, pxs);
        cache_flush();
        return;
    }

    for(i=0;i<pxs;i++)
    {
        unsigned short value = (unsigned short *)data[i];

        r = (value & 0xF800) >> 11;
        g = (value & 0x07E0) >> 5;
        b = (value & 0x001F);
        r <<= 3;
        g <<= 2;
        b <<= 3;
        fbbuf[i]= (r << 16) | (g << 8) | (b<<0);
    }
}
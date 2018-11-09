#include <stdio.h>
#include <time.h>

static unsigned short src[540*960] __attribute__ ((__aligned__ (64)));
static unsigned int dst[540*960] __attribute__ ((__aligned__ (64)));

void rgb_convert_yt_ca15(unsigned short *src, unsigned int *dst, unsigned int pxs)
{
}

void rgb_convert_yt_ca9(unsigned short *src, unsigned int *dst, unsigned int pxs)
{
        __asm__ volatile (
                "        lsrs    ip, r2, #5\r\n"
                "        vmov.i8 q15, #7\r\n"
                "        beq     31f\r\n"
                "        vld2.8  {q0, q1}, [r0:256]!\r\n"
                "        vld2.8  {q2, q3}, [r0:256]!\r\n"
                "        vmov.i8 q10, #0\r\n"
                "        vmov.i8 q14, #0\r\n"
                "        vpush   {q7}\r\n"
                "32:     vshr.u8 q8, q0, #3\r\n"
                "        pld     [r0, #256]\r\n"
                "        vshr.u8 q12, q2, #3\r\n"
                "        pld     [r0, #288]\r\n"
                "        vshl.i8 q7, q0, #3\r\n"
                "        vshl.i8 q11, q2, #3\r\n"
                "        vsli.8  q8, q1, #5\r\n"
                "        vsli.8  q12, q3, #5\r\n"
                "        vbic    q9, q1, q15\r\n"
                "        vbic    q13, q3, q15\r\n"
                "        vbic    q8, q8, q15\r\n"
                "        subs    ip, ip, #1\r\n"
                "        vbic    q12, q12, q15\r\n"
                "        beq     320f\r\n"
                "        vld2.8  {q0, q1}, [r0:256]!\r\n"
                "        vld2.8  {q2, q3}, [r0:256]!\r\n"
                "320:    vst4.8  {d14, d16, d18, d20}, [r1:256]!\r\n"
                "        vst4.8  {d15, d17, d19, d21}, [r1:256]!\r\n"
                "        vst4.8  {d22, d24, d26, d28}, [r1:256]!\r\n"
                "        vst4.8  {d23, d25, d27, d29}, [r1:256]!\r\n"
                "        bne     32b\r\n"
                "        vpop    {q7}\r\n"
                "31:\r\n"
        :: [i] "r" (src), [o] "r" (dst), [s] "r" (pxs)
        );
}

void rgb_convert_hp(unsigned short *src, unsigned int *dst, unsigned int pxs)
{
        __asm__ volatile (
                "       cmp          %[s], #0\r\n"
                "       beq          2f\r\n"
                "       vmov.i32     d21, #0\r\n"
                "       vmov.i32     d27, #0\r\n"
                "1:     vldmia       %[i]!, {q8}\r\n"
                "       vldmia       %[i]!, {q11}\r\n"
                "       pld          [%[i], #128]\r\n"
                "       vshr.u8      q9, q8, #3\r\n"
                "       vshr.u8      q12, q11, #3\r\n"
                "       vshrn.i16    d20, q9, #5\r\n"
                "       vshrn.i16    d26, q12, #5\r\n"
                "       vshrn.i16    d19, q8, #5\r\n"
                "       vshrn.i16    d25, q11, #5\r\n"
                "       vshl.i8      d19, d19, #2\r\n"
                "       vshl.i8      d25, d25, #2\r\n"
                "       vshl.i16     q8, q8, #3\r\n"
                "       vshl.i16     q11, q11, #3\r\n"
                "       vmovn.i16    d18, q8\r\n"
                "       vmovn.i16    d24, q11\r\n"
                "       vst4.8       {d18, d19, d20, d21}, [%[o]]!\r\n"
                "       vst4.8       {d24, d25, d26, d27}, [%[o]]!\r\n"
                "       subs         %[s], %[s], #16\r\n"
                "       bne          1b\r\n"
                "2:\r\n"
        :: [i] "r" (src), [o] "r" (dst), [s] "r" (pxs)
        );
}

typedef void (*func_t)(unsigned short *src, unsigned int *, unsigned int);

int main(int argc, char **argv)
{
        int i, model;
        float t3;
        const int frames=10000;
        struct timespec t1, t2;
        func_t rgb565to888 = rgb_convert_hp;

        if (argc > 1) {
            printf("model: rgb_convert_yt_ca9\n\r");
            if (argv[1][0]=='1') rgb565to888 = rgb_convert_yt_ca9;
        }
        memset((void *)src, 0xff, 540*960*2);
        clock_gettime(CLOCK_REALTIME, &t1);
        for (i=0; i<frames; i++) {
                rgb565to888(src, dst, 540*960);
        }
        clock_gettime(CLOCK_REALTIME, &t2);
        t3 = (float)(t2.tv_sec-t1.tv_sec)+(float)(t2.tv_nsec-t1.tv_nsec)/1000000000;
        printf("%d frames\t%f s\t%f s/f\n", frames, t3, t3/(float)frames);
	return 0;
}


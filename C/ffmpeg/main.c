#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libavutil/imgutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/timestamp.h>
#include <libswscale/swscale.h>

int main() {
    printf("AV Version:%s\n", av_version_info());
    printf("%X\n", avcodec_version());
    printf("%X\n", avformat_version());
    printf("%X\n", avutil_version());
    printf("%X\n", swscale_version());

    return 0;
}

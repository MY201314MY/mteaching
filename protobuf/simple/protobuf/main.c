#include <stdio.h>
#include "pb_encode.h"
#include "pb_decode.h"
#include "message.pb.h"

int main() {
    printf("- - - protobuf - - -\n");

    uint8_t buffer[128];
    size_t message_length;
    bool status;

    {
        printf("Encode our message...\r\n");
        Example message = Example_init_zero;
        pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));

        message.value = 13;

        status = pb_encode(&stream, Example_fields, &message);
        message_length = stream.bytes_written;

        if (!status){
            printf("Encoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }
    }

    {
        printf("Decode our message...\r\n");
        Example message = Example_init_zero;
        pb_istream_t stream = pb_istream_from_buffer(buffer, sizeof(buffer));

        pb_decode(&stream, Example_fields, &message);

        if(!status){
            printf("Decoding failed: %s\n", PB_GET_ERROR(&stream));
            return 1;
        }

        printf("Your set value is:%d\r\n", message.value);
    }

    return 0;
}
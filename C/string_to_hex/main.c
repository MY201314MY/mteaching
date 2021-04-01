#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *input = "048681201556076140";
    int m = (strlen(input)%2)?1:0;
    m += strlen(input)/2;

    uint16_t *output = (uint16_t*)malloc(m*sizeof(uint16_t));

    int length = strlen(input);
    int n= 0;
    int index = 0;

    if(length%2==0){
        output[index] = (input[n++]-'0')*16 + input[n++]-'0';
    }else{
        output[index] = input[n++]-'0';
    }
    printf("output[0]:0x%02d\r\n", output[0]);

    while (n<length){
        index++;
        output[index] = (input[n++]-'0')*16 + input[n++]-'0';
    }

    for(int i = 0 ;i<m; i++){
        printf("0x%02X ", output[i]);
    }
    printf("\r\n\r\n--- End---\r\n");

    free(output);

    return 0;
}
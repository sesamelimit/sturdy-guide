#include <iostream>

const char alphabet[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char* base64_encode(const char message[], size_t size) {
    if (!size) return "";
    size_t coded_size = (size / 3) * 4 + (size % 3!=0? 4:0);
    char *coded_message = new char[coded_size];
    for (size_t i = 0; i + 2 < size; i += 3) {
        int temp = (int) (message[i]) * (2 << 15) + (int) (message[i + 1]) * (2 << 7) + (int) message[i + 2];
        for (size_t j = 0; j < 4; ++j) {
            coded_message[i / 3 * 4 + 3 - j] = alphabet[temp - (temp >> 6 << 6)];
            temp = temp >> 6;
        }
    }
    if (size%3)
    {
        int temp = (size%3==1? (int)(message[size-1])*(2<<15) : (int)(message[size-2])*(2<<15)) + (size%3==2)*((int)(message[size-1])*(2<<7));
        for (size_t j = 0; j < 4; ++j) {
            coded_message[size / 3 * 4 + 3 - j] = (((size%3==1)&&(3-j<2)) || ((size%3==2)&&(3-j<3))  ? alphabet[temp - (temp >> 6 << 6)]: '=');
            temp = temp >> 6;
        }
        coded_message[coded_size-1]='=';
        if (size%3==1) coded_message[coded_size-2]='=';
    }
    return coded_message;
}

char* base64_decode(const char encoded[], size_t& out_size){
    if (!out_size) return "";
    size_t coded_size = (out_size / 3) * 4 + (out_size % 3!=0? 4:0);
    char *decoded_message = new char[out_size];
    for (size_t i = 0; i+3 < coded_size; i+=4) {
        size_t current_byte=0;
        for(size_t j=0; j<4; ++j) {
            size_t letter_id = 0;
            if (encoded[i+j] < '=') {
                if (encoded[i+j] == '+') letter_id = 62;
                if (encoded[i+j] == '/') letter_id = 63;
                if (encoded[i+j] >= '0' && encoded[i+j] <= '9')
                    letter_id = (int) encoded[i+j] - int('0') + 52;
            } else if (encoded[i+j] >= 'A' && encoded[i+j] <= 'Z')
                letter_id = (int) encoded[i+j] - int('A');
            else if (encoded[i+j] >= 'a' && encoded[i+j] <= 'z')
                letter_id = (int) encoded[i+j] - int('a') + 26;
            current_byte+= letter_id <<((3-j)*6);
        }
        for(size_t j=0;j<3;++j)
        {
            decoded_message[(i/4) * 3+2-j]=(char)(current_byte - (current_byte >> 8 << 8));
            current_byte = current_byte >> 8;
        }
    }
    return decoded_message;
}
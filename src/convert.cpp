/**
 * @file convert.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/convert.hpp"

std::string TextToHexadecimal(std::string text_string){
    char hex_char;
    std::string hex_string = std::string(text_string.size() << 1, '\0');
    for(size_t i = 0, j = 0; i < text_string.size(); i++){
        hex_char = (text_string[i] & 0xF0) >> 4;
        hex_string[j++] = hex_char > 9 ? (hex_char - 9) | 0x40 : hex_char | 0x30;
        hex_char = text_string[i] & 0xF;
        hex_string[j++] = hex_char > 9 ? (hex_char - 9) | 0x40 : hex_char | 0x30;
    }
    return hex_string;
}

std::string HexadecimalToText(std::string hex_string){
    unsigned char hex_char;
    std::string text_string = std::string((hex_string.size() + 1) >> 1, '\0');
    for(size_t i = 0; i < text_string.size(); i++){
        hex_char = static_cast<unsigned char>(hex_string[i << 1]);
        text_string[i] = (hex_char > '9' ? hex_char + 9 : hex_char) << 4;
        hex_char = static_cast<unsigned char>(hex_string[(i << 1) | 1]);
        text_string[i] |= (hex_char > '9' ? (hex_char + 9) & 0xF : hex_char & 0xF);
    }
    return text_string;
}
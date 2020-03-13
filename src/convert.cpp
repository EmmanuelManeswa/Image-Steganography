/**
 * @file convert.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This source file contains the functions implementation of the functions defined in "../include/convert.hpp" header file.
 * @version 0.1
 * @date 2020-03-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <cctype>
#include <cstdint>
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

std::string HexadecimalToBinary(std::string hex_string){
    std::string bin_string;
    uint8_t int_val;
    for(auto hex_char: hex_string){
        if(hex_char >= '0' && hex_char <= '9')
            int_val = hex_char - '0';
        else
            int_val = 10 + hex_char - 'A';
        for (int8_t i = 3; i >= 0; i--){
            bin_string.push_back((int_val & (1 << i)) ? '1' : '0');
        }
    }
    return bin_string;
}

std::string BinaryToHexadecimal(std::string bin_string){
    std::string hex_string;
    for(size_t i = 0; i < bin_string.size(); i+=4){
        int8_t int_val = 0;
        for(size_t j = i; j < i+4; j++){
            int_val <<= 1;
            if(bin_string[j] == '1')
                int_val |= 1;
        }
        if(int_val <= 9)
            hex_string.push_back('0' + int_val);
        else
            hex_string.push_back('A' + int_val - 10);
    }
    return hex_string;
}
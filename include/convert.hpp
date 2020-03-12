/**
 * @file convert.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2020-03-12
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

/**
 * @brief This function converts a string of text to a string of hexadecimal.
 * 
 * @param text 
 * @return std::string 
 */
std::string TextToHexadecimal(std::string text);

/**
 * @brief This function converts a string of hexadecimal to a string of text.
 * 
 * @param hex_text 
 * @return std::string 
 */
std::string HexadecimalToText(std::string hex_text);

#endif
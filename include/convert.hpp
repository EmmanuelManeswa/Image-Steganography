/**
 * @file convert.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This header file contains the function definitions of the functions to convert strings to and from various formarts.
 *        The formarts available for conversion are:
 *                                              1. Text to Hexadecimal
 *                                              2. Hexadecimal to Text
 *                                              3. Hexadecimal to Binary
 *                                              4. Binary to Hexadecimal
 *        Functions implementation path: "../src/convert.cpp".
 * @version 0.1
 * @date 2020-03-13
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>

/**
 * @brief This function converts a text string to a hexadecimal string.
 * 
 * @param text 
 * @return std::string 
 */
std::string TextToHexadecimal(std::string text);

/**
 * @brief This function converts a hexadecimal string to a text string.
 * 
 * @param hex_text 
 * @return std::string 
 */
std::string HexadecimalToText(std::string hex_text);

/**
 * @brief This function converts a hexadecimal string to a binary string.
 * 
 * @param hex_string 
 * @return std::string 
 */
std::string HexadecimalToBinary(std::string hex_string);

/**
 * @brief This function converts a binary string to a hexadecimal string.
 * 
 * @param bin_string 
 * @return std::string 
 */
std::string BinaryToHexadecimal(std::string bin_string);

#endif
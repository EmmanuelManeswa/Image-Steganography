/**
 * @file steganography.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This header file contains the function definitions for encoding secret message into cover image and decoding secret
 *        message from stego image.
 *        Functions implementation path: "../src/steganography.cpp".
 * @version 0.1
 * @date 2020-03-30
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef STEGANOGRAPHY_HPP
#define STEGANOGRAPHY_HPP

#include <string>

/**
 * @brief This function embeds the secret message into the cover image.
 * 
 * @param message 
 * @param key 
 * @param cover_img_path 
 * @return std::string 
 */
std::string Encode(std::string message, std::string key, std::string cover_img_path);

/**
 * @brief This function extracts the secret message from the stego image.
 * 
 * @param key 
 * @param stego_img_path 
 * @return std::string 
 */
std::string Decode(std::string key, std::string stego_img_path);

#endif
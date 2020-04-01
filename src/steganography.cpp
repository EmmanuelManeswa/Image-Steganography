/**
 * @file steganography.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This source file contains the class member functions implementation for the class.
 *        Class definition implementation in "../include/steganography.hpp"
 *        header file.
 * @version 0.1
 * @date 2020-04-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

//#include <string>
//#include <opencv2/imgcodecs.hpp>
#include "../include/steganography.hpp"
#include  "../include/convert.hpp"

Steganography::Steganography(std::string msg, std::string key, std::string image_path): secret_info_(msg), key_(key), img_path_(image_path){ }

Steganography::Steganography(std::string key, std::string image_path): key_(key), img_path_(image_path){ }

void Steganography::LoadImage(){
    img_ = cv::imread(img_path_, cv::IMREAD_COLOR);
    if(img_.empty())
        exit(EXIT_FAILURE);
}

std::string Steganography::Extraction(){
    LoadImage();
    
    /**
     * @brief Secret info encryption to be left for last, so the following two line just converts secret info to binary form.
     * 
     */
    secret_info_ = TextToHexadecimal(secret_info_);
    secret_info_ = HexadecimalToBinary(secret_info_);

    
}
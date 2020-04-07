/**
 * @file steganography.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This source file contains the class member functions implementation for the class.
 *        Class definition implementation in "../include/steganography.hpp"
 *        header file.
 * @version 0.1
 * @date 2020-04-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

//#include <string>
//#include <opencv2/imgcodecs.hpp>
#include "../include/steganography.hpp"
#include "../include/convert.hpp"
#include "../third-party/sha256/include/sha256.hpp"

Steganography::Steganography(std::string msg, std::string key, std::string image_path): secret_info_(msg), key_(key), img_path_(image_path){ }

Steganography::Steganography(std::string key, std::string image_path): key_(key), img_path_(image_path){ }

void Steganography::LoadImage(){
    img_ = cv::imread(img_path_, cv::IMREAD_COLOR); // [B, G, R]
    if(img_.empty())
        exit(EXIT_FAILURE); // failed to open image.
}

void Steganography::SaveStegoImage(std::string stego_img_path){
    cv::imwrite(stego_img_path, img_);
}

std::string Steganography::HiddenBits(size_t size){
    return HexadecimalToBinary(std::to_string(size));
}

bool Steganography::IfStorable(std::string number_of_bits_hidden)const{
    if(img_.rows >= 10){
        if(5 * img_.cols >= number_of_bits_hidden.length()){
            if(5 * img_.cols >= key_hash_.length()){
                if(img_.rows - 10 * img_.cols >= secret_info_.length()) return true;
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

bool Steganography::IsEven(unsigned char color_shade)const{
    return color_shade % 2 == 0 ? true :false;
}

bool Steganography::IsOdd(unsigned char color_shade)const{
    return color_shade % 2 == 1 ? true : false;
}

bool Steganography::XOR(char secret_bit, bool lsb)const{
    switch(secret_bit){
        case '0':
            switch(lsb){
                case false: return false;
                case true:  return true;
            }
        case '1':
            switch(lsb){
                case false: return true;
                case true:  return false;
            }
    }
}

void Steganography::CirculateKey (){
    auto iterator = key_.begin();
    key_.push_back(*iterator);
    key_.erase(0, 1);
}

cv::Vec3b Steganography::EmbedInBlue(cv::Vec3b pixel, size_t index){
    if(IsEven(secret_info_[index]) && IsEven(pixel[0]));  // if both bit to embed and blue lsb are 0 do nothing.
    else if(IsEven(secret_info_[index]) && IsOdd(pixel[0]))  pixel[0] = pixel[0] - 1;    // if bit to embed is 0 and blue lsb is 1 change blue lsb to 0.
    else if(IsOdd(secret_info_[index]) && IsEven(pixel[0]))  pixel[0] = pixel[0] + 1;    // if bit to embed is 1 and blue lsb is 0 change blue lsb to 1.
    else;   // if both bit to embed and blue lsb are 1 do nothing.
    return pixel;
}

cv::Vec3b Steganography::EmbedInGreen(cv::Vec3b pixel, size_t index){
    if(IsEven(secret_info_[index]) && IsEven(pixel[1]));  // if both bit to embed and green lsb are 0 do nothing.
    else if(IsEven(secret_info_[index]) && IsOdd(pixel[1]))  pixel[1] = pixel[1] - 1;    // if bit to embed is 0 and green lsb is 1 change green lsb to 0.
    else if(IsOdd(secret_info_[index]) && IsEven(pixel[1]))  pixel[1] = pixel[1] + 1;    // if bit to embed is 1 and green lsb is 0 change green lsb to 1.
    else;   // if both bit to embed and green lsb are 1 do nothing.
    return pixel;
}

cv::Vec3b Steganography::EmbedInRed(cv::Vec3b pixel, size_t index){
    if(IsEven(secret_info_[index]) && IsEven(pixel[2]));  // if both bit to embed and red lsb are 0 do nothing.
    else if(IsEven(secret_info_[index]) && IsOdd(pixel[2]))  pixel[2] = pixel[2] - 1;    // if bit to embed is 0 and red lsb is 1 change red lsb to 0.
    else if(IsOdd(secret_info_[index]) && IsEven(pixel[2]))  pixel[2] = pixel[2] + 1;    // if bit to embed is 1 and red lsb is 0 change red lsb to 1.
    else;   // if both bit to embed and red lsb are 1 do nothing.
    return pixel;
}

void Steganography::EmbedLength(std::string number_of_bits_hidden){
    for(size_t i = 0, count = 0; i < 5; i++)
        for(size_t j = 0; j < img_.cols; j++, count++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(i, j));  // get pixel.
            if(count < number_of_bits_hidden.length()){
                if(IsOdd(pixel[1]))   pixel[1] = pixel[1] - 1;  // green lsb to 0.
                if(IsEven(number_of_bits_hidden[count]) && IsEven(pixel[2])); // if both bit to embed and red lsb are 0 do nothing.
                else if(IsEven(number_of_bits_hidden[count]) && IsOdd(pixel[2]))  pixel[2] = pixel[2] - 1;    // if bit to embed is 0 and red lsb is 1 change red lsb to 0.
                else if(IsOdd(number_of_bits_hidden[count]) && IsEven(pixel[2]))  pixel[2] = pixel[2] + 1;    // if bit to embed is 1 and red lsb is 0 change red lsb to 1.
                else;   // if both bit to embed and red lsb are 1 do nothing.
                img_.at<cv::Vec3b>(cv::Point(i, j)) = pixel;  // save changes to pixel back to the image.
            }
            else{
                if(IsEven(pixel[1]))  pixel[1] + 1; // green lsb to 1.
                img_.at<cv::Vec3b>(cv::Point(i, j)) = pixel;  // save changes to pixel back to the image.
                return;
            }
        }
}

void Steganography::EmbedKeyHash(){
    for(size_t i = 5, count = 0; i < 10; i++)
        for(size_t j = 0; j < img_.cols; j++, count++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(i, j));    // get pixel.
            if(count < key_hash_.length()){
                if(IsEven(key_hash_[count]) && IsEven(pixel[0]));  // if both bit to embed and blue lsb are 0 do nothing.
                else if(IsEven(key_hash_[count]) && IsOdd(pixel[0]))  pixel[0] = pixel[0] - 1;    // if bit to embed is 0 and blue lsb is 1 change blue lsb to 0.
                else if(IsOdd(key_hash_[count]) && IsEven(pixel[0]))  pixel[0] = pixel[0] + 1;    // if bit to embed is 1 and blue lsb is 0 change blue lsb to 1.
                else;   // if both bit to embed and blue lsb are 1 do nothing.
                img_.at<cv::Vec3b>(cv::Point(i, j)) = pixel;  // save changes to pixel back to the image.
            }
            else return;
        }
}

void Steganography::EmbedSecretInfo(){
    for(size_t i = 10, count = 0; i < img_.rows; i++){
        for(size_t j = 0; j < img_.cols; j++, count++){
            if(count < secret_info_.length()){
                cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(i, j));    //get pixel.
                switch(j % 3){
                    /**
                     * @brief Case 0: Use blue lsb for XOR. if 1 embed secret information in red lsb else embed in green lsb.
                     * 
                     */
                    case 0:
                        if(XOR(key_[0], IsOdd(pixel[0])))
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInRed(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInGreen(pixel, count);
                        break;

                    /**
                     * @brief Case 1: Use green lsb for XOR. if 1 embed secret information in blue lsb else embed in red lsb.
                     * 
                     */
                    case 1:
                        if(XOR(key_[0], IsOdd(pixel[1])))
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInBlue(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInRed(pixel, count);
                        break;

                    /**
                     * @brief Case 2: Use red lsb for XOR. if 1 embed secret information in green lsb else embed in blue lsb.
                     * 
                     */
                    case 2:
                        if(XOR(key_[0], IsOdd(pixel[2])))
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInGreen(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(i, j)) = EmbedInBlue(pixel, count);
                        break;
                }
            }
            else return;
        }
    }
}

std::string Steganography::Embedding(){
    LoadImage();
    
    /**
     * @brief Secret info encryption to be left for last, so the following two line just converts secret infomation to binary form.
     * 
     */
    secret_info_ = TextToHexadecimal(secret_info_);
    secret_info_ = HexadecimalToBinary(secret_info_);

    /**
     * @brief Key hashing using sha256 and then convert to binary form.
     * 
     */
    key_hash_ = sha256(key_);
    key_hash_ = HexadecimalToBinary(key_hash_);

    /**
     * @brief Change original key to bits.
     * 
     */
    key_ = TextToHexadecimal(key_);
    key_ = HexadecimalToBinary(key_);

    std::string number_of_bits_hidden = HiddenBits(secret_info_.length());

    if(!IfStorable(number_of_bits_hidden))
        exit(EXIT_FAILURE);  // image is small.
    
    EmbedLength(number_of_bits_hidden);
    EmbedKeyHash();
    EmbedSecretInfo();

    std::string stego_img_path = "../scrum-board/Stego_1. 2020-03-11_20:23.jpeg";
    SaveStegoImage(stego_img_path);

    return stego_img_path;
}
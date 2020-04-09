/**
 * @file steganography.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This source file contains the class member functions implementation for Steganography class.
 *        Class definition implementation in "../include/steganography.hpp"
 *        header file.
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

//#include <string>
//#include <opencv2/imgcodecs.hpp>
#include <sstream>
#include "../include/steganography.hpp"
#include "../include/convert.hpp"
#include "../third-party/sha256/include/sha256.hpp"

Steganography::Steganography(std::string msg, std::string key, std::string image_path, std::string new_stego_image_path):
                            secret_info_(msg), key_(key), img_path_(image_path), new_stego_img_path_(new_stego_image_path+".png"){ }

Steganography::Steganography(std::string key, std::string image_path): key_(key), img_path_(image_path){ }

void Steganography::LoadImage(){
    img_ = cv::imread(img_path_, cv::IMREAD_COLOR); // [B, G, R]
    if(img_.empty())
        exit(EXIT_FAILURE); // failed to open image.
}

void Steganography::SaveStegoImage(){
    cv::imwrite(new_stego_img_path_, img_);
}

std::string Steganography::HiddenBits(size_t size){
    return HexadecimalToBinary(std::to_string(size));
}

bool Steganography::IfStorable(std::string number_of_bits_hidden)const{
    if(img_.rows >= 10){
        if(5 * img_.cols >= number_of_bits_hidden.length()){
            if(5 * img_.cols >= key_hash_.length()){
                if((img_.rows - 10) * img_.cols >= secret_info_.length()) return true;
                return false;
            }
            return false;
        }
        return false;
    }
    return false;
}

int Steganography::BToI(char bit){
    return bit == '0' ? 0 : 1;
}

bool Steganography::IsEven(int color_shade)const{
    return color_shade % 2 == 0 ? true :false;
}

bool Steganography::IsOdd(int color_shade)const{
    return color_shade % 2 == 1 ? true : false;
}

bool Steganography::XOR(char secret_bit, bool lsb)const{
    switch(secret_bit){
        case '0':
            switch(lsb){
                case false: return false;
                case true: return true;
            }
        case '1':
            switch(lsb){
                case false: return true;
                case true: return false;
            }
    }
    exit(EXIT_FAILURE);
}

void Steganography::CirculateKey (){
    auto iterator = key_.begin();
    key_.push_back(*iterator);
    key_.erase(0, 1);
}

cv::Vec3b Steganography::EmbedInBlue(cv::Vec3b pixel, size_t index){
    if(IsEven(BToI(secret_info_[index])) && IsEven((int)pixel[0]));  // if both bit to embed and blue lsb are 0 do nothing.
    else if(IsEven(BToI(secret_info_[index])) && IsOdd((int)pixel[0])) pixel[0] -= 1;    // if bit to embed is 0 and blue lsb is 1 change blue lsb to 0.
    else if(IsOdd(BToI(secret_info_[index])) && IsEven((int)pixel[0])) pixel[0] += 1;    // if bit to embed is 1 and blue lsb is 0 change blue lsb to 1.
    else;   // if both bit to embed and blue lsb are 1 do nothing.
    return pixel;
}

void Steganography::ExtractFromBlue(cv::Vec3b pixel){
    if(IsEven((int)pixel[0])) secret_info_.push_back('0');
    else secret_info_.push_back('1');
}

cv::Vec3b Steganography::EmbedInGreen(cv::Vec3b pixel, size_t index){
    if(IsEven(BToI(secret_info_[index])) && IsEven((int)pixel[1]));  // if both bit to embed and green lsb are 0 do nothing.
    else if(IsEven(BToI(secret_info_[index])) && IsOdd((int)pixel[1])) pixel[1] -= 1;    // if bit to embed is 0 and green lsb is 1 change green lsb to 0.
    else if(IsOdd(BToI(secret_info_[index])) && IsEven((int)pixel[1])) pixel[1] += 1;    // if bit to embed is 1 and green lsb is 0 change green lsb to 1.
    else;   // if both bit to embed and green lsb are 1 do nothing.
    return pixel;
}

void Steganography::ExtractFromGreen(cv::Vec3b pixel){
    if(IsEven((int)pixel[1])) secret_info_.push_back('0');
    else secret_info_.push_back('1');
}

cv::Vec3b Steganography::EmbedInRed(cv::Vec3b pixel, size_t index){
    if(IsEven(BToI(secret_info_[index])) && IsEven((int)pixel[2]));  // if both bit to embed and red lsb are 0 do nothing.
    else if(IsEven(BToI(secret_info_[index])) && IsOdd((int)pixel[2])) pixel[2] -= 1;    // if bit to embed is 0 and red lsb is 1 change red lsb to 0.
    else if(IsOdd(BToI(secret_info_[index])) && IsEven((int)pixel[2])) pixel[2] += 1;    // if bit to embed is 1 and red lsb is 0 change red lsb to 1.
    else;   // if both bit to embed and red lsb are 1 do nothing.
    return pixel;
}

void Steganography::ExtractFromRed(cv::Vec3b pixel){
    if(IsEven((int)pixel[2])) secret_info_.push_back('0');
    else secret_info_.push_back('1');
}

void Steganography::EmbedLength(std::string number_of_bits_hidden){
    for(size_t i = 0, count = 0; i < 5; i++)
        for(size_t j = 0; j < img_.cols; j++, count++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));  // get pixel.
            if(count < number_of_bits_hidden.length()){
                if(IsOdd((int)pixel[1])) pixel[1] -= 1;  // green lsb to 0.
                if(IsEven(BToI(number_of_bits_hidden[count])) && IsEven((int)pixel[2])); // if both bit to embed and red lsb are 0 do nothing.
                else if(IsEven(BToI(number_of_bits_hidden[count])) && IsOdd((int)pixel[2])) pixel[2] -= 1;    // if bit to embed is 0 and red lsb is 1 change red lsb to 0.
                else if(IsOdd(BToI(number_of_bits_hidden[count])) && IsEven((int)pixel[2])) pixel[2] += 1;    // if bit to embed is 1 and red lsb is 0 change red lsb to 1.
                else;   // if both bit to embed and red lsb are 1 do nothing.
                img_.at<cv::Vec3b>(cv::Point(j, i)) = pixel;  // save changes to pixel back to the image.
            }
            else{                
                if(IsEven((int)pixel[1])) pixel[1] += 1; // green lsb to 1.                
                img_.at<cv::Vec3b>(cv::Point(j, i)) = pixel;  // save changes to pixel back to the image.
                return;
            }
        }
}

size_t Steganography::ExtractLength(){
    std::string length_bits;
    for(size_t i = 0; i < 5; i++)
        for(size_t j = 0; j < img_.cols; j++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));  // get pixel;
            if(IsEven((int)pixel[1])){
                if(IsEven((int)pixel[2])) length_bits.push_back('0');
                else length_bits.push_back('1');
            }
            else{
                std::stringstream sstream(BinaryToHexadecimal(length_bits));
                size_t secret_length;
                sstream >> secret_length;
                return secret_length;
            }
        }
    exit(EXIT_FAILURE);
}

void Steganography::EmbedKeyHash(){
    for(size_t i = 5, count = 0; i < 10; i++)
        for(size_t j = 0; j < img_.cols; j++, count++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));    // get pixel.
            if(count < key_hash_.length()){
                if(IsEven(BToI(key_hash_[count])) && IsEven((int)pixel[0]));  // if both bit to embed and blue lsb are 0 do nothing.
                else if(IsEven(BToI(key_hash_[count])) && IsOdd((int)pixel[0])) pixel[0] -= 1;    // if bit to embed is 0 and blue lsb is 1 change blue lsb to 0.
                else if(IsOdd(BToI(key_hash_[count])) && IsEven((int)pixel[0])) pixel[0] += 1;    // if bit to embed is 1 and blue lsb is 0 change blue lsb to 1.
                else;   // if both bit to embed and blue lsb are 1 do nothing.
                img_.at<cv::Vec3b>(cv::Point(j, i)) = pixel;  // save changes to pixel back to the image.
            }
            else return;
        }
}

std::string Steganography::ExtractKeyHash(){
    std::string embedded_key_hash;
    for(size_t i = 5; i < 10; i++)
        for(size_t j = 0; j < img_.cols; j++){
            cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));  // get pixel.
            if(embedded_key_hash.length() < 256){
                if(IsEven((int)pixel[0])) embedded_key_hash.push_back('0');
                else embedded_key_hash.push_back('1');
            }
            else return BinaryToHexadecimal(embedded_key_hash);
        }
    exit(EXIT_FAILURE);
}

void Steganography::EmbedSecretInfo(){
    for(size_t i = 10, count = 0; i < img_.rows; i++){
        for(size_t j = 0; j < img_.cols; j++, count++){
            if(count < secret_info_.length()){
                cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));    // get pixel.
                switch(j % 3){
                    /**
                     * @brief Case 0: Use blue lsb for XOR. if 1 embed secret information in red lsb else embed in green lsb.
                     * 
                     */
                    case 0:
                        if(XOR(key_[0], IsOdd((int)pixel[0])))
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInRed(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInGreen(pixel, count);
                        break;

                    /**
                     * @brief Case 1: Use green lsb for XOR. if 1 embed secret information in blue lsb else embed in red lsb.
                     * 
                     */
                    case 1:
                        if(XOR(key_[0], IsOdd((int)pixel[1])))
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInBlue(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInRed(pixel, count);
                        break;

                    /**
                     * @brief Case 2: Use red lsb for XOR. if 1 embed secret information in green lsb else embed in blue lsb.
                     * 
                     */
                    case 2:
                        if(XOR(key_[0], IsOdd((int)pixel[2])))
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInGreen(pixel, count);                        
                        else
                            img_.at<cv::Vec3b>(cv::Point(j, i)) = EmbedInBlue(pixel, count);
                        break;
                }
                CirculateKey();
            }
            else return;
        }
    }
}

void Steganography::ExtractSecretInfo(size_t secret_info_length){
    for(size_t i = 10; i < img_.rows; i++)
        for(size_t j = 0; j < img_.cols; j++){
            if(secret_info_.length() < secret_info_length){
                cv::Vec3b pixel = img_.at<cv::Vec3b>(cv::Point(j, i));
                switch(j % 3){
                    /**
                     * @brief Case 0: Use blue lsb for XOR. if 1 extract secret information from red lsb else extract from green lsb.
                     * 
                     */
                    case 0:
                        if(XOR(key_[0], IsOdd((int)pixel[0]))) ExtractFromRed(pixel);
                        else ExtractFromGreen(pixel);
                        break;

                    /**
                     * @brief Case 1: Use green lsb for XOR. if 1 extract secret information from blue lsb else extract from red lsb.
                     * 
                     */
                    case 1:
                        if(XOR(key_[0], IsOdd((int)pixel[1]))) ExtractFromBlue(pixel);
                        else ExtractFromRed(pixel);
                        break;

                    /**
                     * @brief Case 2: Use red lsb for XOR. if 1 extract secret information from green lsb else extract from blue lsb.
                     * 
                     */
                    case 2:
                        if(XOR(key_[0], IsOdd((int)pixel[2]))) ExtractFromGreen(pixel);
                        else ExtractFromBlue(pixel);
                        break;
                }
                CirculateKey();
            }
            else return;
        }
}

std::string Steganography::Embedding(){
    LoadImage();

    /**
     * @brief Secret info encryption to be left for last, so the following two line just converts secret infomation to binary form.
     * 
     */
    secret_info_ = HexadecimalToBinary( TextToHexadecimal(secret_info_));

    /**
     * @brief Key hashing using sha256 and then convert to binary form.
     * 
     */
    key_hash_ = HexadecimalToBinary( sha256(key_));

    /**
     * @brief Change original key to bits.
     * 
     */
    key_ = HexadecimalToBinary( TextToHexadecimal(key_));

    std::string number_of_bits_hidden = HiddenBits(secret_info_.length());

    if(!IfStorable(number_of_bits_hidden))
        exit(EXIT_FAILURE);  // image is small.
    
    EmbedLength(number_of_bits_hidden);
    EmbedKeyHash();
    EmbedSecretInfo();

    SaveStegoImage();

    return new_stego_img_path_;
}

std::string Steganography::Extraction(){
    LoadImage();

    /**
     * @brief Key hashing using sha256 and then converting to binary and back to hexadecimal.
     * 
     */
    key_hash_ = BinaryToHexadecimal( HexadecimalToBinary( sha256( key_)));

    /**
     * @brief change original key to bits.
     * 
     */
    key_ = HexadecimalToBinary( TextToHexadecimal(key_));

    if(img_.rows < 10)
        exit(EXIT_FAILURE); // image is small.

    size_t secret_info_length = ExtractLength();

    if(key_hash_ != ExtractKeyHash())
        exit(EXIT_FAILURE); // wrong key/password.

    ExtractSecretInfo(secret_info_length);
    secret_info_ = HexadecimalToText( BinaryToHexadecimal( secret_info_));

    return secret_info_;
}
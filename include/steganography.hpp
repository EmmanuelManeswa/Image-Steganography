/**
 * @file steganography.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This header file contains the Steganography class definition.
 *        Class implementation path: "../src/steganography.cpp".
 * @version 0.1
 * @date 2020-04-09
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef STEGANOGRAPHY_HPP
#define STEGANOGRAPHY_HPP

#include <string>
#include <opencv2/imgcodecs.hpp>

/**
 * @brief Steganography class for embedding and extraction of secret message into and from image.
 * 
 */
class Steganography{

        std::string secret_info_, key_, key_hash_, img_path_, new_stego_img_path_;
        cv::Mat img_;

        /**
         * @brief Loads image from the path given (img_path_).
         * 
         */
        void LoadImage();
        
        /**
         * @brief Saves the stego image.
         * 
         * @param stego_image_path 
         */
        void SaveStegoImage();

        /**
         * @brief Calculates the number of secret information bits and returns it as bits.
         * 
         * @return std::string 
         */
        std::string HiddenBits(size_t size);

        /**
         * @brief checks if the secret infomation, hashed key and the legth of hidden info can be embedded into the cover image.
         * 
         * @return true 
         * @return false 
         */
        bool IfStorable(std::string number_of_bits_hidden)const;

        /**
         * @brief Takes bit of type char and returns the equivalent bit of type int.
         * 
         * @param bit 
         * @return int 
         */
        int BToI(char bit);

        /**
         * @brief Checks if value is an even number.
         * 
         * @param color_value 
         * @return true 
         * @return false 
         */
        bool IsEven(int color_shade)const;

        /**
         * @brief Checks if value is an odd number.
         * 
         * @param color_value 
         * @return true 
         * @return false 
         */
        bool IsOdd(int color_shade)const;

        /**
         * @brief Exclusive Or of of two bits of different data types.
         * 
         * @param secret_bit 
         * @param green_lsb 
         * @return true 
         * @return false 
         */
        bool XOR(char secret_bit, bool lsb)const;

        /**
         * @brief Circulates the key making ith behave like a circular string.
         * 
         */
        void CirculateKey();

        /**
         * @brief Embeds secret information bit in the LSB of blue.
         * 
         * @param pixel 
         * @param index 
         * @return cv::Vec3b 
         */
        cv::Vec3b EmbedInBlue(cv::Vec3b pixel, size_t index);

        void ExtractFromBlue(cv::Vec3b pixel);

        /**
         * @brief Embeds secret information bit in the LSB of green.
         * 
         * @param pixel 
         * @param index 
         * @return cv::Vec3b 
         */
        cv::Vec3b EmbedInGreen(cv::Vec3b pixel, size_t index);

        void ExtractFromGreen(cv::Vec3b pixel);

        /**
         * @brief Embeds secret information bit in the LSB of red.
         * 
         * @param pixel 
         * @param index 
         * @return cv::Vec3b 
         */
        cv::Vec3b EmbedInRed(cv::Vec3b pixel, size_t index);

        void ExtractFromRed(cv::Vec3b pixel);
        
        /**
         * @brief Embeds the length of the secret information bits into the cover image.
         * 
         * @param number_of_bits_hidden 
         */
        void EmbedLength(std::string number_of_bits_hidden);

        /**
         * @brief Extracts the length of the secret information bits from the cover image.
         * 
         * @return size_t 
         */
        size_t ExtractLength();

        /**
         * @brief Embeds the hashed key bits into the cover image.
         * 
         */
        void EmbedKeyHash();

        /**
         * @brief Extracts the hashed key bits from the cover image.
         * 
         * @return std::string 
         */
        std::string ExtractKeyHash();

        /**
         * @brief Embeds the secret key bits into the cover image.
         * 
         */
        void EmbedSecretInfo();

        /**
         * @brief Extracts the secret information bits from the cover image.
         * 
         * @param secret_info_length 
         */
        void ExtractSecretInfo(size_t secret_info_length);

    public:

        /**
         * @brief Deleted the default constructor.
         * 
         */
        Steganography() = delete;

        /**
         * @brief Construct a new Steganography object. This constructor is used for embedding purposes.
         * 
         * @param msg 
         * @param key 
         * @param img 
         */
        Steganography(std::string msg, std::string key, std::string img_path, std::string new_stego_image_path);

        /**
         * @brief Construct a new Steganography object. This constructor is used for extraction purposes.
         * 
         * @param key 
         * @param img 
         */
        Steganography(std::string key, std::string img_path);

        /**
         * @brief Construct a new Steganography object.
         * 
         */
        Steganography(const Steganography&) = delete;

        /**
         * @brief Embeds the secret information into cover image and returns the path/name of stego image.
         * 
         * @return std::string 
         */
        std::string Embedding();

        /**
         * @brief Extracts the secret information from stego image and returns the secret information.
         * 
         * @return std::string 
         */
        std::string Extraction();
        
        /**
         * @brief Destroy the Steganography object.
         * 
         */
        ~Steganography() = default;
};

#endif
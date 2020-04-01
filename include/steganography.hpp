/**
 * @file steganography.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This header file contains the class definition for image steganography.
 *        Class implementation path: "../src/steganography.cpp".
 * @version 0.1
 * @date 2020-04-01
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

        std::string secret_info_, key_, img_path_;
        cv::Mat img_;

    public:

        /**
         * @brief Deleted the default constructor.
         * 
         */
        Steganography() = delete;

        /**
         * @brief Construct a new Steganography object.
         * 
         * @param msg 
         * @param key 
         * @param img 
         */
        Steganography(std::string msg, std::string key, std::string img_path);

        /**
         * @brief Construct a new Steganography object.
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
         * @brief Loads image from the path given (img_path_).
         * 
         */
        void LoadImage();

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
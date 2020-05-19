/**
 * @file middlemen.hpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This header file contains the Middlemen class definition.
 *        Class implementation path "../src/middlemen.cpp".
 * @version 0.1
 * @date 2020-05-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef MIDDLEMEN_HPP
#define MIDDLEMEN_HPP

#include <QObject>
#include <QString>

/**
 * @brief The Middlemen class for handling communications between the QML frontend and the Steganography C++ class backend.
 * 
 */
class Middlemen : public QObject{
    
    Q_OBJECT

    public:
        explicit Middlemen(QObject *parent = 0);

        /**
         * @brief It is called from QML to embed information into image and then it passes the task to the Steganography class
         *        and it recieves the the new path for the stego image  and passes it back to QML.
         * 
         * @param message 
         * @param password 
         * @param img_path 
         * @param stego_path 
         * @return QString 
         */
        Q_INVOKABLE QString Embed(QString message, QString password, QString img_path, QString stego_path);

        /**
         * @brief It is called from QML to extract information from image and then it passes the task to the Steganography class
         *        and it recieves the extracted information and passes it back to QML.
         * 
         * @param password 
         * @param img_path 
         * @return QString 
         */
        Q_INVOKABLE QString Extract(QString password, QString img_path);
        
        ~Middlemen();
};

#endif
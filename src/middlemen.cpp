/**
 * @file middlemen.cpp
 * @author Emmanuel Maneswa (emmanuelmaneswa@gmail.com)
 * @brief This source file contains the class member functions implementation for Middlemen class.
 *        class definition path "../include/middlemen.hpp".
 * @version 0.1
 * @date 2020-05-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include "../include/middlemen.hpp"
#include "../include/steganography.hpp"

Middlemen::Middlemen(QObject *parent) : QObject(parent) { }

QString Middlemen::Embed(QString message, QString password, QString img_path, QString stego_path){
    Steganography steg(message.toStdString(), password.toStdString(), img_path.toStdString(), stego_path.toStdString());
    return QString::fromStdString(steg.Embedding());
}

QString Middlemen::Extract(QString password, QString img_path){
    Steganography steg(password.toStdString(), img_path.toStdString());
    return QString::fromStdString(steg.Extraction());
}

Middlemen::~Middlemen(){ }
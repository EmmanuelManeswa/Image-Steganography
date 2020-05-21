QT += quick qml
CONFIG += c++17
CONFIG += warn_off

TARGET = ImSteg

SOURCES +=  src/main.cpp \
            src/convert.cpp \
            src/steganography.cpp \
            src/middlemen.cpp \
            third-party/sha256/src/sha256.cpp

RESOURCES += gui/qml.qrc

HEADERS +=  include/convert.hpp \
            include/steganography.hpp \
            include/middlemen.hpp \
            third-party/sha256/include/sha256.hpp \
            third-party/easy-encryption/include/encrypt.h \
            third-party/easy-encryption/include/vigenere.h \
            third-party/easy-encryption/include/b64.h

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += opencv4

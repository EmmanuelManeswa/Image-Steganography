# __Image/Picture Steganography__ #

## __Student Details__ ##

- Number: 154409

- Name: Emmanuel Maneswa

- Email: <emmanuelmaneswa@gmail.com>

## __Project Advisor__ ##

- Asst. Prof. Dr. Cem Kalyoncu

## __Languages__ ##

- C++
- QML
- JavaScript

## __Softwares/Tools Used__ ##

- Visual Studio Code: [https://code.visualstudio.com/](https://code.visualstudio.com/)
- Git: [https://git-scm.com/](https://git-scm.com/)
- Bitbucket: [https://bitbucket.org/](https://bitbucket.org/)
- Github: [https://github.com/](https://github.com/)
- CMake: [https://cmake.org/](https://cmake.org/)
- Qt: [https://www.qt.io/](https://www.qt.io/)
- OpenCV: [https://opencv.org/](https://opencv.org/)
- Doxygen: [http://www.doxygen.nl/](http://www.doxygen.nl/)
- Trello: [https://trello.com/](https://trello.com/)

## __Supported Image Formats__ ##

- JPEG: *.jpeg, *.jpg, *.jpe
- PNG: *.png
- TIFF: *.tiff, *.tif
- WebP: *.webp
- Bitmaps: *.bmp
- OpenEXR: *.exr
- HDR: *.hdr

## __Format Stego Image is Saved__ ##

- PNG: *.png ─> Because it uses a lossless compression(LZW).

## __Third-Party Libraries__ ##

- Sha256: [http://www.zedwood.com/article/cpp-sha256-function](http://www.zedwood.com/article/cpp-sha256-function)
- Easy Encryption: [https://github.com/philipperemy/easy-encryption](https://github.com/philipperemy/easy-encryption)

## __Directory Structure__ ##

```.
.
├── build
│   ├── convert.o
│   ├── ImSteg
│   ├── main.o
│   ├── Makefile
│   ├── middlemen.o
│   ├── moc_middlemen.cpp
│   ├── moc_middlemen.o
│   ├── moc_predefs.h
│   ├── qrc_qml.cpp
│   ├── qrc_qml.o
│   ├── sha256.o
│   └── steganography.o
├── docs
│   ├── project 1
│   │   ├── proj1_documentation.docx
│   │   ├── proj1_documentation.pdf
│   │   ├── proj1_poster.pdf
│   │   └── proj1_poster.pptx
│   └── project 2
│       ├── Project Poster (154409 - Emmanuel Maneswa).pptx
│       ├── Project Presentation (154409 - Emmanuel Maneswa).pptx
│       └── Project Report (154409 - Emmanuel Maneswa).docx
├── gui
│   ├── js
│   │   ├── embed.js
│   │   └── extract.js
│   ├── pages
│   │   ├── embed.qml
│   │   ├── extract.qml
│   │   └── main.qml
│   └── qml.qrc
├── ImSteg.pro
├── include
│   ├── convert.hpp
│   ├── middlemen.hpp
│   └── steganography.hpp
├── README.md
├── README.pdf
├── samples
│   ├── 3.webp
│   ├── sample_1280×853.exr
│   ├── sample_1280×853.hdr
│   ├── sample_1920×1280.bmp
│   ├── stego-image11.png
│   ├── stego-image12.png
│   ├── stego-image13.png
│   ├── stego-image14.png
│   ├── stego-image15.png
│   ├── stego-image16.png
│   ├── stego-image1.png
│   ├── stego-images
│   │   ├── stego1.png
│   │   └── stego2.png
│   └── tiff-image.tiff
├── scrum-board
│   ├── 10. 2020-05-21_22:30.jpg
│   ├── 11. 2020-05-21_23:28.jpg
│   ├── 1. 2020-03-11_20:23.jpeg
│   ├── 12. 2020-05-21_23:28.jpg
│   ├── 13. 2020-05-22_00:02.jpg
│   ├── 14. 2020-05-22_00:02.jpg
│   ├── 2. 2020-03-30_07:31.jpg
│   ├── 3. 2020-04-07_16:53.jpg
│   ├── 4. 2020-04-07_16:56.jpg
│   ├── 5. 2020-04-08_12:32.jpg
│   ├── 6. 2020-04-08_12:35.jpg
│   ├── 7. 2020-04-09_08:46.jpg
│   ├── 8. 2020-04-25_02:30.jpg
│   └── 9. 2020-05-21_01:35.jpg
├── src
│   ├── convert.cpp
│   ├── main.cpp
│   ├── middlemen.cpp
│   └── steganography.cpp
└── third-party
    ├── easy-encryption
    │   ├── include
    │   │   ├── b64.h
    │   │   ├── encrypt.h
    │   │   └── vigenere.h
    │   └── LICENSE
    ├── README.md
    ├── README.pdf
    └── sha256
        ├── include
        │   └── sha256.hpp
        ├── LICENCE.txt
        └── src
            └── sha256.cpp
```

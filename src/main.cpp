#include <iostream>
#include <string>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>
#include "../include/steganography.hpp"
#include "../include/convert.hpp"
#include "../third-party/sha256/include/sha256.hpp"
#include "../include/middlemen.hpp"

int main(int argc, char *argv[]){

    //std::cout << Encode("Emmanuel", "Maneswa", "../scrum-board/1. 2020-03-11_20:23.jpeg") << std::endl;
    /*std::string name = "Emmanuel", a = "bc8a2f8cdedb005b5c787692853709b060db75ff",
    b = "b781cbb29054db12f88f08c6e161c199", c = "571f3896fb694dc268b032d7940dabbfbcd7ee64c07f45c01c9e64db";
    std::string h_name = sha256(name);
    std::cout << h_name << std::endl;
    h_name = HexadecimalToBinary(h_name);
    std::cout << h_name << std::endl;
    h_name = BinaryToHexadecimal(h_name);
    std::cout << h_name << std::endl;*/
    /*a = HexadecimalToBinary(a);
    std::cout << a << std::endl;
    b = HexadecimalToBinary(b);
    std::cout << b << std::endl;
    a = BinaryToHexadecimal(a);
    std::cout << a << std::endl;
    b = BinaryToHexadecimal(b);
    std::cout << b << std::endl;
    c = HexadecimalToBinary(c);
    std::cout << c << std::endl;
    c = BinaryToHexadecimal(c);
    std::cout << c << std::endl;*/

    //std::string test("Contrary to popular belief, Lorem Ipsum is not simply random text. It has roots in a piece of classical Latin literature from 45 BC, making it over 2000 years old. Richard McClintock, a Latin professor at Hampden-Sydney College in Virginia, looked up one of the more obscure Latin words, consectetur, from a Lorem Ipsum passage, and going through the cites of the word in classical literature, discovered the undoubtable source. Lorem Ipsum comes from sections 1.10.32 and 1.10.33 of \"de Finibus Bonorum et Malorum\" (The Extremes of Good and Evil) by Cicero, written in 45 BC. This book is a treatise on the theory of ethics, very popular during the Renaissance. The first line of Lorem Ipsum, \"Lorem ipsum dolor sit amet..\", comes from a line in section 1.10.32. The standard chunk of Lorem Ipsum used since the 1500s is reproduced below for those interested. Sections 1.10.32 and 1.10.33 from \"de Finibus Bonorum et Malorum\" by Cicero are also reproduced in their exact original form, accompanied by English versions from the 1914 translation by H. Rackham.");

    //Steganography steg(test, "emmanuel12345", "../scrum-board/1. 2020-03-11_20:23.jpeg", "../samples/stego-image1");
    //Steganography steg("Emmanüél maneswa iz mı n@mé.", "emmanuel12345", "../samples/stego-image1.png", "../scrum-board/stego-image11");
    //Steganography steg("Emmanüél maneswa iz mı n@mé. 22 yr old!!", "emmanuel12345", "../samples/tiff-image.tiff", "../samples/stego-image12");
    //Steganography steg("Emmanüél maneswa iz mı n@mé. Zimbabwean??", "emmanuel12345", "../samples/3.webp", "../samples/stego-image13");
    //Steganography steg("Emmanüél maneswa 154409", "emmanuel12345", "../samples/sample_1920×1280.bmp", "../samples/stego-image14");
    //Steganography steg("Emmanüél maneswa 154409 EUL", "emmanuel12345", "../samples/sample_1280×853.hdr", "../samples/stego-image16");
    //std::cout << steg.Embedding() << std::endl;

    //Steganography steg2("emmanuel12345", "../samples/stego-image1.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image11.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image12.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image13.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image14.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image15.png");
    //Steganography steg2("emmanuel12345", "../samples/stego-image16.png");
    //std::cout << steg2.Extraction() << std::endl;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    
    QGuiApplication app(argc, argv);

    //qmlRegisterType<Middlemen>("com.ImSteg.Middlemen", 1, 0, "Middlemen");
    QScopedPointer<Middlemen> middlemen(new Middlemen);

    QQmlApplicationEngine engine;

    app.setOrganizationName("European University of Lefke");
    app.setOrganizationDomain("http://www.eul.edu.tr/en/");
    app.setApplicationName("ImSteg");

    const QUrl url(QStringLiteral("qrc:/pages/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &obj_url){
        if(!obj && url == obj_url)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    engine.rootContext()->setContextProperty("middlemen", middlemen.data());

    return app.exec();
    //return 0;
}
#ifndef MIDDLEMEN_HPP
#define MIDDLEMEN_HPP

#include <QObject>
#include <QString>

class Middlemen : public QObject{
    
    Q_OBJECT

    public:
        explicit Middlemen(QObject *parent = 0);
        Q_INVOKABLE QString Embed(QString message, QString password, QString img_path, QString stego_path);
        Q_INVOKABLE QString Extract(QString password, QString img_path);
        ~Middlemen();
};

#endif
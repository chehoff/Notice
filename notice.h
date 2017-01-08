#ifndef NOTICE_H
#define NOTICE_H

#include <QObject>

class Notice : public QObject
{
    Q_OBJECT
public:
    explicit Notice(const QString &str, QObject *parent = 0);
    QString GetName();
signals:

public slots:
private:
    QString name;
    QString projectName;
    bool isInFolder;
    QString author;
};

#endif // NOTICE_H

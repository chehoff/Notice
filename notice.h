#ifndef NOTICE_H
#define NOTICE_H

#include <QObject>
#include <QDate>
#include<QStringList>

class Notice : public QObject
{
    Q_OBJECT
public:
    explicit Notice(const QString &str, QObject *parent = 0);
    ~Notice();
    QString GetName();
    void setisInFolder(bool b);
    bool GetisInFolder();
    void setinwork(bool b);
    bool Getinwork();
    void setProjectName(const QString &str);
    QString GetProjectName();
    void setAutor(const QString &str);
    QString GetAuthor();
    void setStatus(const QString &str);
    QString GetStatus();
    static int GetCount();
    void setDateIncoming(const QString &str);
    QDate GetDateIncoming();
    static QStringList Getprojects();
signals:

public slots:
private:
    QString name;
    QString projectName;
    bool isInFolder;
    QString author;
    QString status;
    static int count;
    QDate dateIncoming;
    bool inwork;
    static QStringList projects;
};

#endif // NOTICE_H

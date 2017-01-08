#include "notice.h"

Notice::Notice(const QString &str, QObject *parent) : QObject(parent)
{
    this->name = str;
}
QString Notice::GetName(){
    //qDebug() << "Имя: " << this->name;
    return this->name;
}

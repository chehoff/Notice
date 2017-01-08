#ifndef STARTFORM_H
#define STARTFORM_H

#include <QWidget>
#include <QtWidgets>

namespace Ui {
class StartForm;
}

class StartForm : public QWidget
{
    Q_OBJECT

public:
    QString PathToXLS;
    QString PathToFolder;
    explicit StartForm(QWidget *parent = 0);
    ~StartForm();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    //void on_PathToFolderLine_textChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    Ui::StartForm *ui;
signals:
    void DirPath(const QString &str);
    void FilePath(const QString &str);
};

#endif // STARTFORM_H

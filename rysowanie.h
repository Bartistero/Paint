#ifndef RYSOWANIE_H
#define RYSOWANIE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class rysowanie; }
QT_END_NAMESPACE

class rysowanie : public QMainWindow
{
    Q_OBJECT

public:
    rysowanie(QWidget *parent = nullptr);
    ~rysowanie();

private:
    Ui::rysowanie *ui;
};
#endif // RYSOWANIE_H

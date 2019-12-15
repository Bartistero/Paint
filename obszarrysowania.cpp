#include "obszarrysowania.h"

obszarRysowania::obszarRysowania(QWidget *parent) : QWidget(parent)
{
    mKolor=Qt::black;
}
void obszarRysowania::changeRed()
{
    mKolor = Qt::red;
    qDebug() <<"wybrano czerwony";
}
void obszarRysowania::changeYellow()
{
    mKolor = Qt::yellow;
    qDebug() <<"wybrano zółty";
}
void obszarRysowania::changeBlue()
{
    mKolor = Qt::blue;
    qDebug() <<"wybrano Niebieski";

}
void obszarRysowania::changeGreen()
{
    mKolor = Qt::green;
    qDebug() <<"wybrano zielony";

}
void obszarRysowania::changeWhite()
{
    mKolor = Qt::black;
    qDebug() <<"wybrano biały";
}
void obszarRysowania::save()
{
    QString filters("Obrazy (*.PNG)");
    QString nazwa = QFileDialog::getSaveFileName(this,"Zapisywanie",QDir::currentPath(),filters);
    mRysunek.save(nazwa,"PNG");
    qDebug() <<"Czy Zapisano? ;) ";
}
void obszarRysowania::clear()
{
    QImage obraz(rozmiar,QImage::Format_RGB32);
    obraz.fill(Qt::white);
    mRysunek=obraz;
    update();


}
void obszarRysowania::mousePressEvent(QMouseEvent *zdarzenie)
{
    if(zdarzenie->button() == Qt::LeftButton)
    {
        mRysowanie=true;
        mousePos=zdarzenie->pos();
        qDebug() <<"Rozpoczęto rysowanie Xd";
    }
}
void obszarRysowania::mouseMoveEvent(QMouseEvent *zdarzenie)
{
    if(mRysowanie == true)
    {
        end = zdarzenie->pos();
        QPainter rysownik;
        QPen pioro(mKolor,2);
        rysownik.begin(&mRysunek);
        rysownik.setPen(pioro);

        rysownik.drawLine(mousePos,end);
        mousePos = zdarzenie->pos();
        update();

    }
}
void obszarRysowania::mouseReleaseEvent(QMouseEvent *zdarzenie)
{
    if(zdarzenie->button()==Qt::LeftButton)
        mRysowanie=false;
    qDebug() <<"Zakończono rysowanie";
}
void obszarRysowania::paintEvent(QPaintEvent *zdarzenie)
{
    QPainter rysownik;
    rysownik.begin(this);
    rysownik.drawImage(0,0,mRysunek);
    rysownik.end();

}
void obszarRysowania::resizeEvent(QResizeEvent *zdarzenie)
{
    rozmiar = zdarzenie->size();
    clear();
}

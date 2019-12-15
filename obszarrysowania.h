#ifndef OBSZARRYSOWANIA_H
#define OBSZARRYSOWANIA_H

#include <QWidget>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
class obszarRysowania : public QWidget
{
    Q_OBJECT
public:
    explicit obszarRysowania(QWidget *parent = nullptr);

signals:

public slots:
    void changeRed();
    void changeYellow();
    void changeBlue();
    void changeGreen();
    void changeWhite();
    void clear();
    void save();
protected:
    void mousePressEvent(QMouseEvent *zdarzenie);
    void mouseMoveEvent(QMouseEvent *zdarzenie);
    void mouseReleaseEvent(QMouseEvent *zdarzenie);
    void paintEvent(QPaintEvent *zdarzenie);
    void resizeEvent(QResizeEvent *zdarzenie);
private:
    bool mRysowanie;
    QPoint mousePos;
    QPoint end;
    QColor mKolor;
    QImage mRysunek;
    QSize rozmiar;
};

#endif // OBSZARRYSOWANIA_H

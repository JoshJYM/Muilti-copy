#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QClipboard>
#include <QFocusEvent>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    virtual void keyPressEvent(QKeyEvent *e);
    QClipboard *clip;
    bool set_flag = false;

private:
    Ui::Widget *ui;
private slots:
    void slotget();

};

#endif // WIDGET_H

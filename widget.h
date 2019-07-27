#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void ChangeMoney(int n);
    int Money{0};
    int Money_RE{0};
    int FiveH{0};
    int FiveH_RE{0};
    int OneH{0};
    int OneH_RE{0};
    int Fifty{0};
    int Fifty_RE{0};
    int Ten{0};

private slots:
    void on_M10_clicked();

    void on_M50_clicked();

    void on_M100_clicked();

    void on_M500_clicked();

    void on_Exchange_clicked();

    void on_MilkButton_clicked();

    void on_TeaButton_clicked();

    void on_CoffeeButton_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H

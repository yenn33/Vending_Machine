#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ChangeMoney(int n){
    Money += n;
    ui->lcdNumber->display(QString::number(Money));

    ui->CoffeeButton->setEnabled(false);
      ui->TeaButton->setEnabled(false);
      ui->MilkButton->setEnabled(false);
      if(Money>=500){
      ui->CoffeeButton->setEnabled(true);
      }
      if(Money>=300){
      ui->TeaButton->setEnabled(true);
      }
      if(Money>=400){
      ui->MilkButton->setEnabled(true);
      }



}



void Widget::on_M10_clicked()
{
    ChangeMoney(10);
}

void Widget::on_M50_clicked()
{
    ChangeMoney(50);
}

void Widget::on_M100_clicked()
{
    ChangeMoney(100);
}

void Widget::on_M500_clicked()
{
    ChangeMoney(500);
}

void Widget::on_Exchange_clicked()
{
    QMessageBox MSG;

        FiveH=Money/500;
        FiveH_RE=Money%500;
        OneH=OneH_RE/100;
        OneH_RE=FiveH_RE%100;
        Fifty=OneH_RE/50;
        Fifty_RE=OneH_RE%50;
        Ten=Fifty_RE/10;

             MSG.information(nullptr, "Exchange","Total = "+QString::number(Money)+"\n"+
                "500 = "+QString::number(FiveH)+"\n"+
                "100 = "+QString::number(OneH)+"\n"+
                "50 = "+QString::number(Fifty)+"\n"+
                "10 = "+QString::number(Ten));

        Money=0;
        ui->lcdNumber->display(QString::number(Money));
}

void Widget::on_MilkButton_clicked()
{
    ChangeMoney(-400);
}

void Widget::on_TeaButton_clicked()
{
    ChangeMoney(-300);
}

void Widget::on_CoffeeButton_clicked()
{
    ChangeMoney(-500);
}

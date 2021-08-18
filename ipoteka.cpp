#include "ipoteka.h"
#include "ui_ipoteka.h"
#include <QLabel>
#include <QRegExpValidator>
#include <cmath>
#include <QMessageBox>
#include <QPixmap>


Ipoteka::Ipoteka(QWidget *parent): QMainWindow(parent)    , ui(new Ui::Ipoteka)
{
    ui->setupUi(this);
    ui->doubleSpinBox->setValue(0.00);
    ui->spinBox_2->setMaximum(360);

    ui->lineEdit->setText("0");

    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("[0-9]{10}") , this) ); // выставили ограничения в 10 цифр





    QObject::connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int) ) );
    QObject::connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int) ) );

    connect(ui->lineEdit, SIGNAL(textChanged(QString)) , this , SLOT(set_max_value_spinBox(QString)));

    connect(ui->checkBox , SIGNAL(toggled(bool)) , this , SLOT (mnogo_det_semia(bool)) );


    ui->lineEdit_2->setReadOnly(1);
    ui->lineEdit_3->setReadOnly(1);
    ui->lineEdit_4->setReadOnly(1);
    ui->lineEdit_5->setReadOnly(1);

    QPixmap My_pix(":/new/prefix1/Безымянный.png");
    My_pix = My_pix.scaled(ui->label_3->width() , ui->label_3->height() , Qt::AspectRatioMode::KeepAspectRatio);

    ui->label_3->setPixmap(My_pix);
}

Ipoteka::~Ipoteka()
{
    delete ui;
}


/*

void Ipoteka::on_checkBox_stateChanged(int arg1)
{
    bool on = true;
    ui->checkBox->setChecked(on);
    ui->doubleSpinBox->setValue(Procent_Mnogodet_semia);

    ui->doubleSpinBox->setReadOnly(1);
}

*/




void Ipoteka::set_max_value_spinBox(QString A)
{
    A = ui->lineEdit->text();
    ui->spinBox->setMaximum(A.toInt());
}

void Ipoteka::mnogo_det_semia(bool V)
{
    if(ui->checkBox->isChecked() == 1)
        {
            ui->doubleSpinBox->setValue(Procent_Mnogodet_semia);

            ui->doubleSpinBox->setReadOnly(1);
    }
    else {
            ui->doubleSpinBox->setValue(0.00);
            ui->doubleSpinBox->setReadOnly(0);
    }
}






void Ipoteka::on_pushButton_clicked()
{
     if ((ui->lineEdit->displayText()).toDouble()  !=  0.0)
        {
         if(ui->spinBox->value() != 0.0)
            {
                if(ui->doubleSpinBox->value() != 0.00)
                    {
                        if (ui->spinBox_2->value() != 0.0)
                            {
                                double ezemech_proc;
                                ezemech_proc = (ui->doubleSpinBox->value() / 100) / 12;

                                double tmp = pow ((1 + ezemech_proc) , ui->spinBox_2->value());
                                double ezemech_plat;
                                ezemech_plat =( (ui->lineEdit->text()).toDouble() * ezemech_proc * tmp )/ (tmp - 1);

                                ui->lineEdit_2->setText(QString::number(ezemech_plat));

                                double part_procent_ezemech_plat , part_osnov_ezemech_plat ;
                                part_procent_ezemech_plat = ( (ui->lineEdit->text()).toDouble() - ui->spinBox->value() ) * ezemech_proc;
                                part_osnov_ezemech_plat = ezemech_plat - part_procent_ezemech_plat;

                                ui->lineEdit_5->setText( QString::number(part_procent_ezemech_plat) );
                                ui->lineEdit_4->setText( QString::number(part_osnov_ezemech_plat) );

                                double summa_pereplat = (ezemech_plat * ui->spinBox_2->value() ) - (ui->lineEdit->text()).toDouble() ;
                                ui->lineEdit_3->setText(QString::number(summa_pereplat , 'g' , 9));
                            }
                        else
                            {
                                QMessageBox *My_Box = new QMessageBox(QMessageBox::Icon::Warning , "Отсутствует \" количество месяцев \"" ,
                                                               " Введите количество месяцев !" , QMessageBox::Ok );
                                My_Box->show();
                                My_Box->exec();
                            }
                    }

                else
                    {
                        QMessageBox *My_Box = new QMessageBox(QMessageBox::Icon::Warning , "Отсутствует \" годовой процент \"" ,
                                                       " Введите годовой процент !" , QMessageBox::Ok );
                        My_Box->show();
                        My_Box->exec();
                    }
            }
         else
            {
                QMessageBox *My_Box = new QMessageBox(QMessageBox::Icon::Warning , "Отсутствует \" первоначальный взнос \"" ,
                                               " Введите первоначальный взнос !" , QMessageBox::Ok );
                My_Box->show();
                My_Box->exec();
            }
         }
     else {
         QMessageBox *My_Box = new QMessageBox(QMessageBox::Icon::Warning , "Отсутствует \" стоимость жилья \"" ,
                                           " Введите стоимость жилья в первой строчке" , QMessageBox::Ok );
            My_Box->show();
            My_Box->exec();
     }
}


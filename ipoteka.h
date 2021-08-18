#ifndef IPOTEKA_H
#define IPOTEKA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Ipoteka; }
QT_END_NAMESPACE

class Ipoteka : public QMainWindow
{
    Q_OBJECT

public:
    Ipoteka(QWidget *parent = nullptr);
    ~Ipoteka();

private slots:
    //void on_checkBox_stateChanged(int arg1);
    void set_max_value_spinBox(QString A);
    void mnogo_det_semia(bool);

    void on_pushButton_clicked();

signals:


private:
    Ui::Ipoteka *ui;
    double Procent_Mnogodet_semia = 5.55;

};
#endif // IPOTEKA_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->ui->comboBox->addItem("Algorytm Widmarka");
    this->ui->comboBox_2->addItem("Mężczyzna");
    this->ui->comboBox_2->addItem("Kobieta");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const double alcoholDistributionCoefficient = (this->ui->comboBox->currentText() == "Mężczyzna") ? 0.68 : 0.55;
    const int weight = this->ui->spinBox->value();
    const int drinkVolume = this->ui->spinBox_2->value();
    const double alcoholContent = this->ui->doubleSpinBox_2->value();

    const double amountOfAlcohol = drinkVolume * (alcoholContent / 100) * 0.789;

    const int numberOfHours = this->ui->spinBox_3->value();

    double bac = (amountOfAlcohol / (alcoholDistributionCoefficient * weight)) - (0.15 * numberOfHours);

    if(bac < 0)
    {
        bac = 0;
    }

    this->ui->label_7->setText(QString::number(amountOfAlcohol, 'g', 2) + " g");
    this->ui->label_9->setText(QString::number(bac, 'g', 2) + "\u2030");
}


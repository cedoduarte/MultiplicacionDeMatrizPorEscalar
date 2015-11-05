#include "IntroducirOdenMatrizDialog.h"
#include "ui_IntroducirOdenMatrizDialog.h"

IntroducirOdenMatrizDialog::IntroducirOdenMatrizDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::IntroducirOdenMatrizDialog)
{
    ui->setupUi(this);
    configureSpinBox(ui->numeroDeFilasSpinBox);
    configureSpinBox(ui->numeroDeColumnasSpinBox);
}

IntroducirOdenMatrizDialog::~IntroducirOdenMatrizDialog()
{
    delete ui;
}

int IntroducirOdenMatrizDialog::getNumeroDeFilas() const
{
    return ui->numeroDeFilasSpinBox->value();
}

int IntroducirOdenMatrizDialog::getNumeroDeColumnas() const
{
    return ui->numeroDeColumnasSpinBox->value();
}

void IntroducirOdenMatrizDialog::on_buttonBox_accepted()
{
    accept();
}

void IntroducirOdenMatrizDialog::on_buttonBox_rejected()
{
    reject();
}

void IntroducirOdenMatrizDialog::configureSpinBox(QSpinBox *spinBox) const
{
    spinBox->setMinimum(1);
    spinBox->setMaximum(INT_MAX);
}

#ifndef INTRODUCIRODENMATRIZDIALOG_H
#define INTRODUCIRODENMATRIZDIALOG_H

#include <QDialog>

namespace Ui
{
class IntroducirOdenMatrizDialog;
}

class QSpinBox;

class IntroducirOdenMatrizDialog : public QDialog
{
    Q_OBJECT
public:
    explicit IntroducirOdenMatrizDialog(QWidget *parent = nullptr);
    ~IntroducirOdenMatrizDialog();
    int getNumeroDeFilas() const;
    int getNumeroDeColumnas() const;
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
private:
    void configureSpinBox(QSpinBox *spinBox) const;

    Ui::IntroducirOdenMatrizDialog *ui;
};

#endif // INTRODUCIRODENMATRIZDIALOG_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_multiplicarPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
    void on_actionIntroducir_matriz_triggered();

private:
    double getValueAt(QStandardItemModel *model, int fila, int col) const;

    Ui::Widget *ui;
    QStandardItemModel *mModel;
};

#endif // WIDGET_H

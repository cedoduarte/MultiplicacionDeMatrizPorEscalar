#include "Widget.h"
#include "ui_Widget.h"
#include "DoubleSpinBoxDelegate.h"
#include "IntroducirOdenMatrizDialog.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(new DoubleSpinBoxDelegate(this));
    ui->escalarDoubleSpinBox->setMinimum(-9999999999.9);
    ui->escalarDoubleSpinBox->setMaximum(+9999999999.9);
    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->tableView->addAction(ui->actionIntroducir_matriz);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_multiplicarPushButton_clicked()
{
    const double escalar = ui->escalarDoubleSpinBox->value();
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    for (int ix = 0; ix < rowCount; ++ix) {
        for (int jx = 0; jx < colCount; ++jx) {
            const double mij = getValueAt(mModel, ix, jx);
            const double new_mij = mij * escalar;
            mModel->item(ix, jx)->setText(QString::number(new_mij));
        }
    }
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

double Widget::getValueAt(QStandardItemModel *model, int fila, int col) const
{
    if (!model->item(fila, col)) {
        model->setItem(fila, col, new QStandardItem("0.0"));
        return 0.0;
    }
    return model->item(fila, col)->text().toDouble();
}

void Widget::on_actionIntroducir_matriz_triggered()
{
    IntroducirOdenMatrizDialog d(this);
    if (d.exec() == QDialog::Rejected) {
        return;
    }
    mModel->setRowCount(d.getNumeroDeFilas());
    mModel->setColumnCount(d.getNumeroDeColumnas());
}

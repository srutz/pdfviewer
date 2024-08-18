#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mypdfview.h"

#include <QMainWindow>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void choosePDF();
    void openPDF(const QString &filename);

private:
    Ui::MainWindow *ui;
    QFileDialog *fileChooser;
    MyPdfView *pdfView;
};
#endif // MAINWINDOW_H

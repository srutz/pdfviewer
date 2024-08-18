
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mypdfview.h"
#include <QPdfBookmarkModel>
#include <cassert>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , fileChooser(nullptr)
{
    ui->setupUi(this);
    fileChooser = new QFileDialog(this);
    fileChooser->setNameFilter("PDF (*.pdf)");

    this->pdfView = new MyPdfView(this);
    auto layout = new QVBoxLayout(ui->pdfViewWrapper);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(pdfView);

    QObject::connect(fileChooser, &QFileDialog::fileSelected, this, &MainWindow::openPDF);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::choosePDF()
{
    fileChooser->show();
}

void MainWindow::openPDF(const QString &filename)
{
    qInfo() << "opening pdf \"" << filename << "\"";

    auto pdfView = this->findChild<MyPdfView*>();
    assert(pdfView != nullptr);
    auto pdfDocument = pdfView->showDocument(filename);

    /*
    auto treeView = this->findChild<QTreeView*>();
    if (pdfDocument) {
        //auto bookmarkModel = new QPdfBookmarkModel(pdfDocument);
        //bookmarkModel->setDocument(pdfDocument);
        pdfDocument->setDocument(pdfDocument);
        treeView->setModel(bookmarkModel);
    } else {
        treeView->setModel(nullptr);
    }
    */

}


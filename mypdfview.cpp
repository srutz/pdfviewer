#include "mypdfview.h"

MyPdfView::MyPdfView(QWidget *parent)
    : QPdfView{parent}
{
    this->setPageMode(QPdfView::PageMode::MultiPage);
}

QPdfDocument* MyPdfView::showDocument(const QString &filename)
{
    auto document = new QPdfDocument();
    auto error = document->load(filename);
    switch (error) {
    case QPdfDocument::Error::None:
        this->setDocument(document);
        break;
    default:
        qDebug() << "error loading pdf from " << filename << ": " << error;
    }
    return error == QPdfDocument::Error::None ? document : nullptr;
}

#include <QDebug>
#include <QtCore/QTime>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QAction>
#include <QtGui/QToolBar>
#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>

#include "CcMainWin.h"

CcMainWin::CcMainWin(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	initUI();
	initConnect();
}

CcMainWin::~CcMainWin()
{

}

void CcMainWin::initUI()
{
	_imageViewer = new CcImageViewer(this);
	this->setCentralWidget(_imageViewer);

	_fileToolBar = this->addToolBar(tr("File"));
	_openAction = new QAction(tr("Open"), _fileToolBar);
	_fileToolBar->addAction(_openAction);


}

void CcMainWin::initData()
{

}

void CcMainWin::initConnect()
{
	connect(_openAction, SIGNAL(triggered()), this, SLOT(on_action_openImg_triggered()));
}




void CcMainWin::on_action_openImg_triggered()
{
	QString imgpath = QFileDialog::getOpenFileName(this, tr("open image"), "/", tr("ALL(*.*)"));
	if (imgpath.isEmpty()) return;

	bool isok = _imageViewer->showImage(imgpath);
	
	if (!isok)
		QMessageBox::warning(this, tr("Warning"), tr("Open Image Faile!"), QMessageBox::Ok);


}
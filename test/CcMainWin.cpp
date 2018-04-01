#include <QDebug>
#include <QtCore/QTime>
#include <QtGui/QHBoxLayout>
#include <QtGui/QPushButton>
#include <QtGui/QAction>
#include <QtGui/QToolBar>
#include <QtGui/QMessageBox>
#include <QtGui/QFileDialog>
#include <QtGui/QResizeEvent>
#include <QtGui/QStatusBar>
#include <QtCore/QStringList>
#include <QtCore/QFileInfo>

#include "CcMainWin.h"
#include "CcDockFrame.h"

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
	this->statusBar()->setVisible(false);

	_imageViewer = new CcImageViewer(this);
	this->setCentralWidget(_imageViewer);

	_fileToolBar = this->addToolBar(tr("File"));
	_openAction = new QAction(tr("Open"), _fileToolBar);
	_fileToolBar->addAction(_openAction);
	_fileToolBar->setVisible(false);

	_dockFrame = new CcDockFrame(this);


}

void CcMainWin::initData()
{

}

void CcMainWin::initConnect()
{
	connect(_openAction, SIGNAL(triggered()), this, SLOT(on_action_openImg_triggered()));
	connect(_dockFrame, SIGNAL(sig_open()), this, SLOT(on_action_openImg_triggered()));
	connect(_dockFrame, SIGNAL(sig_exit()), this, SLOT(closeMainWin()));
	connect(_dockFrame, SIGNAL(sig_front()), this, SLOT(frontImage()));
	connect(_dockFrame, SIGNAL(sig_next()), this, SLOT(nextImage()));
}




void CcMainWin::on_action_openImg_triggered()
{
	QString imgpath = QFileDialog::getOpenFileName(this, tr("open image"), "/", tr("ALL(*.*)"));
	if (imgpath.isEmpty()) return;

	bool isok = _imageViewer->showImage(imgpath);
	
	if (!isok)
		QMessageBox::warning(this, tr("Warning"), tr("Open Image Faile!"), QMessageBox::Ok);

	getDirFiles(imgpath);
	_currentImagePath = imgpath;

}

void CcMainWin::resizeEvent(QResizeEvent * event)
{
	QSize mwin_size = event->size();//获得目前窗口大小
	QSize frame_size = _dockFrame->size();//获得dockFrame的大小
	QStatusBar* status_bar = this->statusBar();

	int pos_x = (mwin_size.width() - frame_size.width()) / 2;
	int pos_y = mwin_size.height() - frame_size.height() - 20;
	if (status_bar && status_bar->isEnabled() && status_bar->isVisible())//处理有状态条的情况
	{
		pos_y = pos_y - status_bar->height() - 3;
	}

	_dockFrame->setGeometry(pos_x, pos_y, frame_size.width(), frame_size.height());
	
}

void CcMainWin::closeMainWin()
{
	this->close();
}

void CcMainWin::nextImage()
{
	int current_index = _imagePathList.indexOf(_currentImagePath);
	if ((current_index + 1) < _imagePathList.size())
	{
		_currentImagePath = _imagePathList[current_index + 1];
		_imageViewer->showImage(_currentImagePath);
		current_index++;
	}
}

void CcMainWin::frontImage()
{
	int current_index = _imagePathList.indexOf(_currentImagePath);
	if ((current_index - 1) > 0)
	{
		_currentImagePath = _imagePathList[current_index - 1];
		_imageViewer->showImage(_currentImagePath);
		current_index--;
	}
}

void CcMainWin::getDirFiles(const QString& imagepath)
{
	_imagePathList.clear();

	QFileInfo file_info(imagepath);
	QDir image_dir = file_info.absoluteDir();
	QFileInfoList file_info_list = image_dir.entryInfoList();
	for (int i = 0; i < file_info_list.size(); i++)
	{
		QString temp_list = file_info_list[i].absoluteFilePath();
		if (temp_list == QString("..") || temp_list == QString(".")) continue;

		_imagePathList.append(temp_list);
	}
}
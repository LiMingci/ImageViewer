#include <QtGui/QHBoxLayout>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>
#include <QtGui/QDragEnterEvent>
#include <QtGui/QDropEvent>
#include <QtGui/QPushButton>
#include <QtCore/QUrl>


#include "CcImageViewer/CcImageViewer.h"
#include "CcImageViewer/CcGraphicsView.h"

CcImageViewer::CcImageViewer(QWidget* parent/* = 0*/, Qt::WindowFlags f/* = 0*/ )
	: QWidget(parent, f)
{
	initUI();
}

CcImageViewer::~CcImageViewer()
{
	if (_graphicsView)
	{
		delete _graphicsView;
		_graphicsView = NULL;
	}

}


void CcImageViewer::initUI()
{
	_graphicsView = new CcGraphicsView();

	QHBoxLayout* hlayout = new QHBoxLayout(this);
	hlayout->addWidget(_graphicsView);
	hlayout->setSpacing(0);
	hlayout->setMargin(0);
	this->setLayout(hlayout);

	this->setStyleSheet("border: none");

	_graphicsView->setAcceptDrops(false);    //一定要设置_graphicsView不接受拖拽事件
	this->setAcceptDrops(true);
}


void CcImageViewer::initData()
{
	//
}


void CcImageViewer::initConnect()
{
	//
}

bool CcImageViewer::showImage(QString imagepath)
{
	QImage image;
	bool isload = image.load(imagepath);
	if (!isload) return false;

	QPixmap tempimage =	QPixmap::fromImage(image);
	int imgwidth = tempimage.size().width();
	int imgheight = tempimage.size().height();

	QGraphicsScene* myScene = new QGraphicsScene();
	myScene->setSceneRect(0, 0, imgwidth, imgheight);

	QGraphicsPixmapItem* imgItem = new QGraphicsPixmapItem();
	imgItem->setPixmap(tempimage);
	imgItem->setPos(0, 0);
	myScene->addItem( imgItem );

	_graphicsView->setScene( myScene );

	return true;

}

void CcImageViewer::dragEnterEvent(QDragEnterEvent * event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
	{
		event->acceptProposedAction();
	}
}

void CcImageViewer::dropEvent(QDropEvent * event)
{
	QList<QUrl> urls = event->mimeData()->urls();
	if (urls.isEmpty()) return;

	QString filepath = urls.first().toLocalFile();
	if (filepath.isEmpty()) return;

	showImage(filepath);

}
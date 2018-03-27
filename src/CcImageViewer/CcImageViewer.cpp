#include <QtGui/QHBoxLayout>
#include <QtGui/QImage>
#include <QtGui/QPixmap>
#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsPixmapItem>

#include "CcImageViewer/CcImageViewer.h"
#include "CcImageViewer/CcGraphicsView.h"

CcImageViewer::CcImageViewer(QWidget* parent/* = 0*/, Qt::WindowFlags f/* = 0*/ )
	: QWidget(parent, f)
{
	initUI();
}

CcImageViewer::~CcImageViewer()
{


}


void CcImageViewer::initUI()
{
	_graphicsView = new CcGraphicsView();

	QHBoxLayout* hlayout = new QHBoxLayout(this);
	hlayout->addWidget(_graphicsView);
	hlayout->setSpacing(0);
	hlayout->setMargin(0);

	this->setLayout(hlayout);
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

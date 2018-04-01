/*!
 * \file CcMainWin.h
 *
 * \author LiMingci
 * \date ÈýÔÂ 2018
 *
 * 
 */
#pragma once
#include <QtGui/QMainWindow>
#include "CcImageViewer/CcImageViewer.h"

class QToolBar;
class QAction;
class QResizeEvent;
class CcDockFrame;
class QStringList;
class CcMainWin : public QMainWindow
{
	Q_OBJECT

public:
	CcMainWin(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CcMainWin();

protected:
	void resizeEvent(QResizeEvent * event);

private slots:
	void on_action_openImg_triggered();
	void closeMainWin();
	void nextImage();
	void frontImage();

private:
	void initUI();

	void initData();

	void initConnect();

	void getDirFiles(const QString& imagepath);


private:
	CcImageViewer*              _imageViewer;
	QToolBar*                   _fileToolBar;
	QAction*                    _openAction;

	CcDockFrame*                _dockFrame;

	QStringList                 _imagePathList;
	QString                     _currentImagePath;


};


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
class CcMainWin : public QMainWindow
{
	Q_OBJECT

public:
	CcMainWin(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CcMainWin();



private slots:
	void on_action_openImg_triggered();

private:
	void initUI();

	void initData();

	void initConnect();


private:
	CcImageViewer*              _imageViewer;
	QToolBar*                   _fileToolBar;
	QAction*                    _openAction;



};


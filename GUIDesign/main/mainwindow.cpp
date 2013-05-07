#include"mainwindow.h"
#include<QMenu>
#include<QAction>
#include<QMenuBar>
#include <QMessageBox>
#include<QLabel>
#include<QPixmap>
#include<QFileDialog>
#include<QPainter>
MainWindow::MainWindow(QWidget* parent)
	:QMainWindow(parent)
{
    widget=new Widget;
    setCentralWidget(widget);
	createActions();	
	createMenu();
    //createBackWard();
	setWindowTitle("MIX");
	//setMinimumSize(QSize(600,800));
	//setMaximumSize(QSize(1024,768));
	resize(1024,768);
}

void MainWindow::createActions()
{
	newAction=new QAction(tr("新建"),this);
	newAction->setIcon(QIcon("F:/QT4Project/knuth.jpg"));
	newAction->setShortcut(QKeySequence::New);
	connect(newAction,SIGNAL(triggered()),this,SLOT(newFile()));

	openAction=new QAction("打开",this);
	openAction->setIcon(QIcon("F:/QT4Project/8.jpg"));
	openAction->setShortcut(QKeySequence::Open);
    connect(openAction,SIGNAL(triggered()),widget,SLOT(loadImageFile()));

	saveAction=new QAction("保存",this);
	saveAction->setIcon(QIcon("F:/QT4Project/knuth.jpg"));
	saveAction->setShortcut(QKeySequence::Save);
	connect(saveAction,SIGNAL(triggered()),this,SLOT(saveFile()));

	for(int i=0;i<5;i++)	
	{
		recentFileAction[i]=new QAction(this);
		recentFileAction[i]->setVisible(false);
		connect(recentFileAction[i],SIGNAL(triggered()),this,SLOT(openRecentFile()));
	}

	cutAction=new QAction("剪切",this);	
	cutAction->setIcon(QIcon("F:/QT4Project/knuth.jpg:/"));
	//connect(cutAction,SIGNAL(triggered()),this,SLOT())	
	
	exitAction=new QAction("关闭",this);
	exitAction->setIcon(QIcon("F:/QT4Project/knuth.jpg"));
    exitAction->setShortcut(tr("Ctrl+W"));
	connect(exitAction,SIGNAL(triggered()),this,SLOT(close()));
	localCVAction=new QAction("LocalCV分割算法",this);
	localCVAction->setIcon(QIcon("F:/QT4Project/knuth.jpg:/"));
	connect(localCVAction,SIGNAL(triggered()),this,SLOT(localCV()));
	
	sradAction=new QAction("SRAD分割算法",this);
	connect(sradAction,SIGNAL(triggered()),this,SLOT(srad()));
}

void MainWindow::srad()
{
	QMessageBox* messageBox=new QMessageBox;
	messageBox->setText("OPenCV实现SRAD分割算法");
	messageBox->show();





}

void MainWindow::localCV()
{
	QMessageBox* messageBox=new QMessageBox;
	messageBox->setText("调用opencv分割LocalCV算法");
	messageBox->show();







}

void MainWindow::createMenu()
{
	fileMenu=menuBar()->addMenu("文件");
	fileMenu->addAction(newAction);
	fileMenu->addAction(openAction);
	fileMenu->addSeparator();
	fileMenu->addAction(saveAction);
	for(int i=0;i<5;i++)	
		fileMenu->addAction(recentFileAction[i]); 
	fileMenu->addAction(exitAction);

	editMenu=menuBar()->addMenu("编辑");
	editMenu->addAction(cutAction);
		

	segmentationMenu=menuBar()->addMenu("分割算法");
	segmentationMenu->addAction(localCVAction);
	
	noiseReductionMenu=menuBar()->addMenu("去噪");
	noiseReductionMenu->addAction(sradAction);
}


void MainWindow::newFile()
{
	QMessageBox* messageBox=new QMessageBox;
	messageBox->setText("File");
	messageBox->show();
	
}


void MainWindow::saveFile()
{
	QMessageBox* messageBox=new QMessageBox	;
	messageBox->setText("Save");
	messageBox->show();	

}

void MainWindow::openRecentFile()
{
	QMessageBox* messageBox=new QMessageBox;
	messageBox->setText("openRecentFile");
	messageBox->show();
}

			


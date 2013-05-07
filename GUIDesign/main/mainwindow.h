#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_
#include<QMainWindow>
#include"widget.h"
class QMenu;
class QAction;
class QLabel;
class QPixmap;
class QPushButton;

class MainWindow: public QMainWindow
{
	Q_OBJECT		
public:
		MainWindow(QWidget* parent=0);
protected:
	//void paintEvent(QPaintEvent* event);
private slots:
	void newFile();
	//void loadFile();
	void saveFile();
	void openRecentFile();
	void localCV();
	void srad();
//void paint();
private:
		void createActions();
		void createMenu();
		QDialog* dialog;
		QMenu* fileMenu;
		QAction* newAction;
		QAction* openAction;
		QAction* saveAction;	
		enum{MaxRecentFile=5};
		QAction* recentFileAction[MaxRecentFile];
		QAction* cutAction;
		QMenu* editMenu;
		QAction* exitAction;
		QMenu* segmentationMenu; 
		QAction* localCVAction;
		QMenu* noiseReductionMenu; 
		QAction* sradAction;
        Widget* widget;
        QString fileName;
			

};
#endif

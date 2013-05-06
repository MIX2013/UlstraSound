#include<QApplication>
#include<QTextCodec>
#include"mainwindow.h"
#include"widget.h"
int main(int argc,char** argv)
{
	QApplication app(argc,argv);
    QTextCodec *codec = QTextCodec::codecForName("GB2312");
  
	   QTextCodec::setCodecForLocale(codec);  
	   QTextCodec::setCodecForCStrings(codec);  
	   QTextCodec::setCodecForTr(codec);  

    MainWindow window;
    window.show();

	return app.exec();
}


#ifndef WIDGET_H
#define WIDGET_H
#include<QWidget>
class QLabel;
class QPushButton;
class QGroupBox;
class QRaidoButton;
class QComboBox;
 #include <QRadioButton>
class Widget:public QWidget
{
	Q_OBJECT
public:
	Widget(QWidget* parent=0);
signals:
protected:
   void paintEvent(QPaintEvent* event);
private slots:
    void loadImageFile();
private:
	QGroupBox* styleGroupBox;//×óÉÏ½Ç
	QRadioButton* bRadioButton;
	QRadioButton* mRadioButton;
	QRadioButton* dRadioButton;

	QGroupBox* imageGroupBox;//×óÏÂ½Ç
    QLabel* inputWordLabel;
    QLabel* describeMapComboBoxLabel;
	QComboBox* mapComboBox;
	QLabel* origanlImageLabel;
	QLabel* secondImageLabel;
	QLabel* thirdImageLabel;
	QLabel* fourthImageLabel;
	//ÓÒ±ß	
	QPushButton* loadButton;	
	QPushButton* returnButton;
    
    QString fileName;
    
};
#endif

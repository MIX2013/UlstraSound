#include"widget.h"
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QLabel>
#include<QGroupBox>
#include<QString>
#include<QFileDialog>
#include<QPainter>
#include<QSizePolicy>
#include<QRadioButton>
#include<QPushButton>
#include<QComboBox>
Widget::Widget(QWidget* parent)
	:QWidget(parent)
{
	//GroupBox
	styleGroupBox=new QGroupBox;
	styleGroupBox->setTitle(tr("图谱类型"));
	styleGroupBox->setStyleSheet (QString ("QGroupBox:title { color: blue;  }"));
	bRadioButton=new QRadioButton;
	bRadioButton->setText(tr("B"));
	mRadioButton=new QRadioButton;
	mRadioButton->setText(tr("M"));
	dRadioButton=new QRadioButton;
	dRadioButton->setText(tr("D"));

	//图像框在左下角
	//左下角上部
    inputWordLabel=new QLabel;
	inputWordLabel->setText(tr("输入：X 输出: X"));
	

	describeMapComboBoxLabel=new QLabel;
	describeMapComboBoxLabel->setText(tr("图谱选择"));

    mapComboBox=new QComboBox;
	mapComboBox->addItem(tr("1"));	
	mapComboBox->addItem(tr("2"));
	mapComboBox->addItem(tr("3"));
		

	imageGroupBox=new QGroupBox;
	imageGroupBox->setTitle("图像框");
	imageGroupBox->setStyleSheet(QString("QGroupBox::title{color:blue;}"));
	origanlImageLabel=new QLabel;
	origanlImageLabel->setText("图一");
	origanlImageLabel->setFrameStyle(2);
	secondImageLabel=new QLabel;
	secondImageLabel->setFrameStyle(2);
	secondImageLabel->setText("图二");
	thirdImageLabel=new QLabel;
	thirdImageLabel->setText("图三");
	thirdImageLabel->setFrameStyle(2);
	fourthImageLabel=new QLabel;
	fourthImageLabel->setText("图四");
	fourthImageLabel->setFrameStyle(2);
	

	//载入框在右边
	loadButton=new QPushButton;
	loadButton->setText(tr("载入"));
	returnButton=new QPushButton;
	returnButton->setText(tr("返回"));

	//左上角内部布局
	QHBoxLayout* leftTopLayout=new QHBoxLayout;
	leftTopLayout->addWidget(bRadioButton);
	leftTopLayout->addWidget(mRadioButton);
	leftTopLayout->addWidget(dRadioButton);
	styleGroupBox->setLayout(leftTopLayout);

	//左下角内部布局
	QHBoxLayout* comboxLayout=new QHBoxLayout;
	comboxLayout->addWidget(describeMapComboBoxLabel);
	comboxLayout->addWidget(mapComboBox);

    QGridLayout* leftDownLayout=new QGridLayout;
	leftDownLayout->addWidget(inputWordLabel,0,0);
	leftDownLayout->addLayout(comboxLayout,0,1);
    leftDownLayout->addWidget(origanlImageLabel,1,0);
    leftDownLayout->addWidget(secondImageLabel,1,1);
	leftDownLayout->addWidget(thirdImageLabel,2,0);
	leftDownLayout->addWidget(fourthImageLabel,2,1);

	imageGroupBox->setLayout(leftDownLayout);
	//左边布局
	QVBoxLayout* leftLayout=new QVBoxLayout;	
	leftLayout->addWidget(styleGroupBox);
	leftLayout->addWidget(imageGroupBox);
	leftLayout->setStretchFactor(imageGroupBox,2);

	//右边布局.
	QVBoxLayout* rightLayout=new QVBoxLayout;	
    rightLayout->addWidget(loadButton);
	rightLayout->addWidget(returnButton);
    rightLayout->addStretch();
	//整体布局
	QHBoxLayout* mainLayout=new QHBoxLayout;	
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(leftLayout,1);

    setWindowTitle(tr("超声乳腺系统"));
    setLayout(mainLayout);
    //setMinimumSize(800,600);//设置窗口最小尺寸为800*600
   //setFixedSize(800,600);
    // resize(1024,768);//设置初始化尺寸

    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadImageFile()));


}

void  Widget::loadImageFile()
{
	 fileName=QFileDialog::getOpenFileName(this,tr("打开文件"),
			"",tr("Image(*.png *.jpg *.bmp)"));
     QPixmap img(fileName);
     img=img.scaled(origanlImageLabel->size());
     if(!fileName.isEmpty () )
         origanlImageLabel->setPixmap(img);
    // update();
}

//void Widget::paintEvent(QPaintEvent* event)
//{
  //  QPainter painter(this);

//}




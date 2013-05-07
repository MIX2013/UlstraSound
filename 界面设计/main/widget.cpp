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
	styleGroupBox->setTitle(tr("ͼ������"));
	styleGroupBox->setStyleSheet (QString ("QGroupBox:title { color: blue;  }"));
	bRadioButton=new QRadioButton;
	bRadioButton->setText(tr("B"));
	mRadioButton=new QRadioButton;
	mRadioButton->setText(tr("M"));
	dRadioButton=new QRadioButton;
	dRadioButton->setText(tr("D"));

	//ͼ��������½�
	//���½��ϲ�
    inputWordLabel=new QLabel;
	inputWordLabel->setText(tr("���룺X ���: X"));
	

	describeMapComboBoxLabel=new QLabel;
	describeMapComboBoxLabel->setText(tr("ͼ��ѡ��"));

    mapComboBox=new QComboBox;
	mapComboBox->addItem(tr("1"));	
	mapComboBox->addItem(tr("2"));
	mapComboBox->addItem(tr("3"));
		

	imageGroupBox=new QGroupBox;
	imageGroupBox->setTitle("ͼ���");
	imageGroupBox->setStyleSheet(QString("QGroupBox::title{color:blue;}"));
	origanlImageLabel=new QLabel;
	origanlImageLabel->setText("ͼһ");
	origanlImageLabel->setFrameStyle(2);
	secondImageLabel=new QLabel;
	secondImageLabel->setFrameStyle(2);
	secondImageLabel->setText("ͼ��");
	thirdImageLabel=new QLabel;
	thirdImageLabel->setText("ͼ��");
	thirdImageLabel->setFrameStyle(2);
	fourthImageLabel=new QLabel;
	fourthImageLabel->setText("ͼ��");
	fourthImageLabel->setFrameStyle(2);
	

	//��������ұ�
	loadButton=new QPushButton;
	loadButton->setText(tr("����"));
	returnButton=new QPushButton;
	returnButton->setText(tr("����"));

	//���Ͻ��ڲ�����
	QHBoxLayout* leftTopLayout=new QHBoxLayout;
	leftTopLayout->addWidget(bRadioButton);
	leftTopLayout->addWidget(mRadioButton);
	leftTopLayout->addWidget(dRadioButton);
	styleGroupBox->setLayout(leftTopLayout);

	//���½��ڲ�����
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
	//��߲���
	QVBoxLayout* leftLayout=new QVBoxLayout;	
	leftLayout->addWidget(styleGroupBox);
	leftLayout->addWidget(imageGroupBox);
	leftLayout->setStretchFactor(imageGroupBox,2);

	//�ұ߲���.
	QVBoxLayout* rightLayout=new QVBoxLayout;	
    rightLayout->addWidget(loadButton);
	rightLayout->addWidget(returnButton);
    rightLayout->addStretch();
	//���岼��
	QHBoxLayout* mainLayout=new QHBoxLayout;	
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    mainLayout->setStretchFactor(leftLayout,1);

    setWindowTitle(tr("��������ϵͳ"));
    setLayout(mainLayout);
    //setMinimumSize(800,600);//���ô�����С�ߴ�Ϊ800*600
   //setFixedSize(800,600);
    // resize(1024,768);//���ó�ʼ���ߴ�

    connect(loadButton,SIGNAL(clicked()),this,SLOT(loadImageFile()));


}

void  Widget::loadImageFile()
{
	 fileName=QFileDialog::getOpenFileName(this,tr("���ļ�"),
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




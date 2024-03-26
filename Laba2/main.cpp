#include <QApplication>
#include <Qwidget>
#include <QLineEdit>
#include <QPushButton>
#include <QFrame>
#include <iostream>
#include <QLabel>
#include <QValidator>
#include <QVBoxLayout>
#include <string>
#include <QMessageBox>
#include <fstream>
#include <limits>

using namespace std;

struct nabor {
    int a;
    nabor* p;
};

class creatorint {
private: nabor * first, *q, *d, *n, *pr;
public: creatorint() {
        first = new nabor;
        first->a = 0;
        first->p = nullptr;
        n = first;

    }
    void creater(int t) {
        q = new nabor;
        q->a = t;
        q->p = n;
        n = q;
    }
    void deleter() {
        d = q;
        q = q->p;
        delete d;
    }
    void printer(string i) {
        pr = q;
        do {
            i=to_string(pr->a)+" ";
            pr = pr->p;
        } while (pr->p != nullptr);
    }
    void counter() {
        pr = q;
        do {
            if (pr->a > 1000 || pr->a < 0) {
                cout << "   " << "What is this?" << "   ";
                break;
            }
            pr = pr->p;
        } while (pr->p != nullptr);
    }
    int probamosh() {
        int b = 0;
        pr = q;
        do {
            b = b + 1;
            pr = pr->p;
        } while (pr->p != nullptr);
        return b;
    }
    ~creatorint() {
        do {
            pr = q->p;
            delete q;
            q = pr;
        } while (q != nullptr);
        delete first;
    }
    int print1(){
        pr = q;
        return pr->a;
    }
    int print(){
        pr=pr->p;
        return pr->a;
    }
};

struct naborch {
    char *b;
    naborch* p;
};
class creatorchar {
private: naborch* first2, * q2, * d2, * n2, * pr2;
public: creatorchar() {
        first2 = new naborch;
        strcpy(first2->b," ");
        first2->p = nullptr;
        n2 = first2;
    }
    void creater(char *t) {
        q2 = new naborch;
        strcpy(q2->b,t);
        q2->p = n2;
        n2 = q2;
    }
    void deleter() {
        d2 = q2;
        q2 = q2->p;
        delete d2;
    }
    void printer(string i) {
        pr2 = q2;
        do {
            i=i+pr2->b;
            i=i+" ";
            pr2 = pr2->p;
        } while (pr2->p != nullptr);
    }
    int probamoshch() {
        int b2 = 0;
        pr2 = q2;
        do {
            b2 = b2 + 1;
            pr2 = pr2->p;
        } while (pr2->p != nullptr);
        return b2;
    }
    ~creatorchar() {
        do {
            pr2 = q2->p;
            delete q2;
            q2 = pr2;
        } while (q2 != nullptr);
        delete first2;
    }
    char* print1(){
        pr2 = q2;
        return pr2->b;
    }
    char* print(){
        pr2=pr2->p;
        return pr2->b;
    }
};

class mosh: private creatorint {
private: creatorint A;
public: mosh(creatorint Aa) {
        A = Aa;
    }
    void power() {
        cout << "   " << A.probamosh()-1 << "   ";
    }
};

class moshch : private creatorchar {
private: creatorchar A;
public: moshch(creatorchar Aa) {
        A = Aa;
    }
    void power() {
        cout << "   " << A.probamoshch()-1 << "   ";
    }
};

class Win:public QWidget{
    Q_OBJECT
protected:
    QFrame *frame;
    QLineEdit *inputint, *inputchar;
    QLineEdit *outer;
    QPushButton *start, *intsave, *charsave, *intmosh, *charmosh;
    QPushButton *print;
public:
    Win(QWidget *parent = nullptr);
public slots:
    void begin();
    void saver1();
    void saver2();
    void mosh1();
    void enter();
};

class StrValidator:public QValidator {
public:
    StrValidator(QObject *parent):QValidator(parent){}
    virtual State validate(QString &str,int &pos)const {
        return Acceptable;
    }
};

Win :: Win(QWidget *parent) : QWidget(parent){
    QWidget::setWindowTitle("Strange program");
    frame = new QFrame(this);
    frame -> setFrameShadow(QFrame::Raised);
    frame -> setFrameShape(QFrame::Panel);
    inputint=new  QLineEdit("",this);
    inputchar=new QLineEdit("",this);
    StrValidator *v1=new StrValidator(inputint);
    inputint -> setValidator(v1);
    StrValidator *v2=new StrValidator(inputchar);
    inputchar -> setValidator(v2);
    outer=new QLineEdit("hah",this);
    intsave=new QPushButton("Save(int)",this);
    charsave=new QPushButton("Save(char)",this);
    intmosh=new QPushButton("Power(int)",this);
    charmosh=new QPushButton("Power(char)",this);
    print=new QPushButton("Print",this);
    QVBoxLayout *Layout1=new QVBoxLayout(frame);
    Layout1->addWidget(inputint);
    Layout1->addWidget(intsave);
    Layout1->addWidget(intmosh);
    QVBoxLayout *Layout2=new QVBoxLayout(frame);
    Layout2->addWidget(inputchar);
    Layout2->addWidget(charsave);
    Layout2->addWidget(charmosh);
    QVBoxLayout *Layout3=new QVBoxLayout();
    Layout3->addLayout(Layout1);
    Layout3->addLayout(Layout2);
    QVBoxLayout *Layout4=new QVBoxLayout(frame);
    Layout4->addWidget(print);
    Layout4->addWidget(outer);
    QVBoxLayout *Layout=new QVBoxLayout(this);
    Layout->addWidget(frame);
    Layout->addLayout(Layout3);
    Layout->addLayout(Layout4);
    begin();
    connect(intsave,SIGNAL(clicked()),this,SLOT(saver1()));
    connect(charsave,SIGNAL(clicked()),this,SLOT(saver2()));
    connect(intsave,SIGNAL(clicked()),this,SLOT(begin()));
    connect(charsave,SIGNAL(clicked()),this,SLOT(begin()));
    connect(intmosh,SIGNAL(clicked()),this,SLOT(mosh1()));
    connect(charmosh,SIGNAL(clicked()),this,SLOT(mosh1()));
    connect(print,SIGNAL(clicked()),this,SLOT(enter()));
}

void Win :: begin(){
    inputint->clear();
    inputchar->clear();
    intsave->setEnabled(true);
    intsave->setDefault(true);
    charsave->setEnabled(true);
    charsave->setDefault(true);
    intmosh->setEnabled(true);
    charmosh->setEnabled(true);
    inputint->setEnabled(true);
    inputchar->setEnabled(true);
    print->setEnabled(true);
}

void Win :: saver1(){
    QString str=inputint->text();
    string line;
    int num;
    ofstream out;
    ifstream in;
    in.open("C:/Qt/Laba2/int.txt");
    creatorint a1;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            num=stoi(line);
            a1.creater(num);
        }
    }
    in.close();
    bool ok=true;
    int a, d, c;
    a=str.toDouble(&ok);
    if(ok){
        a1.creater(int (a));
        inputint->clear();
        out.open("C:/Qt/Laba2/int.txt");
        d=a1.probamosh();
        c=a1.print1();
        line=to_string(c);
        out << line << endl;
        while (d>0){
            d=d-1;
            c = a1.print();
            line=to_string(c);
            out << line << endl;
        }
        out.close();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information,"Wrong operation","You wrong",QMessageBox::Ok);
            msgBox.exec();
        }
    inputint->clear();
}

void Win :: saver2(){
    string line;
    creatorchar b;
    ofstream out;
    ifstream in;
    int d;
    in.open("C:/Qt/Laba2/char.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            char *cha=new char[line.length()+1];
            strcpy(cha,line.c_str());
            b.creater(cha);
            delete [] cha;
        }
    }
    in.close();
    char *c;
    bool ok=true;
    QString str=inputint->text();
    if (!str.isEmpty())
    {
        QMessageBox msgBox(QMessageBox::Information,"Wrong operation","You wrong",QMessageBox::Ok);
        msgBox.exec();
    }
    else if(ok){
        QByteArray ba = str.toLocal8Bit();
        char *a = ba.data();
        b.creater(a);
        inputchar->clear();
        out.open("C:/Qt/Laba2/int.txt");
        d=b.probamoshch();
        c=b.print1();
        line=c;
        out << line << endl;
        while (d>0){
            d=d-1;
            c = b.print();
            line=c;
            out << line << endl;
        }
        out.close();
    }
    inputchar->clear();
}

void Win :: mosh1(){
    ifstream in, inch;
    in.open("C:/Qt/Laba2/int.txt");
    inch.open("C:/Qt/Laba2/char.txt");
    creatorint a1;
    creatorchar b;
    string line;
    int num;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            num=stoi(line);
            a1.creater(num);
        }
    }
    in.close();
    if (inch.is_open())
    {
        while (getline(inch, line))
        {
            char *cha=new char[line.length()+1];
            strcpy(cha,line.c_str());
            b.creater(cha);
            delete [] cha;
        }
    }
    in.close();
    outer->clear();
    QString str;
    int i;
    i=a1.probamosh()+b.probamoshch();
    str.setNum(i);
    outer->setText(str);
}

void Win :: enter(){
    ifstream in, inch;
    in.open("C:/Qt/Laba2/int.txt");
    inch.open("C:/Qt/Laba2/char.txt");
    creatorint a1;
    creatorchar b;
    string line;
    int num;
    if (in.is_open())
    {
        while (getline(in, line))
        {
            num=stoi(line);
            a1.creater(num);
        }
    }
    in.close();
    if (inch.is_open())
    {
        while (getline(inch, line))
        {
            char *cha=new char[line.length()+1];
            strcpy(cha,line.c_str());
            b.creater(cha);
            delete [] cha;
        }
    }
    in.close();
    bool ok=true;
    if(ok){
        outer->clear();
        QString str1, str2;
        string m, n;
        a1.printer(m);
        b.printer(n);
        str1=QString :: fromStdString(m);
        str2=QString :: fromStdString(n);
        outer->setText(str1);
        outer->setText(str2);}
}



int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Win win;
    win.show();
    return a.exec();
}

#include <iostream>
#include <string>
using namespace std;

class Printer;

//visitado
class Document
{
protected:
  string data;
public:
  static int countDocs;
  virtual void printOn(Printer*)=0;
  virtual string getData() { return data; }
};
int Document::countDocs = 0;

class SimpleText : public Document
{
public:
  SimpleText()
  {
    countDocs++;
    data = "soy un texto simple";
  }
  void printOn(Printer*);
};

class FormatedText : public Document
{
public:
  FormatedText()
  {
    countDocs++;
    data = "soy un texto con formato";
  }
  void printOn(Printer*);
};

class Image : public Document
{
public:
  Image()
  {
    Document::countDocs++;
    data = "soy una imagen";
  }
  void printOn(Printer*);
};

class TarjetaPresentacion : public Document
{
public:
  TarjetaPresentacion()
  {
    countDocs ++;
    data="soy una tarjeta de presentacion";
  }
  void printOn(Printer*);
};

//visitante
class Printer
{
protected:
  string tipo;
public:
  template <class T>
  static T* getInstance()
  {
    static T v;
    return &v;
  }
  static int countPrinters;
  //string getTipo() { return tipo; }
  virtual void printOn(SimpleText* s) = 0;
  virtual void printOn(FormatedText* f) = 0;
  virtual void printOn(Image* i) = 0;
  virtual void printOn(TarjetaPresentacion* t) = 0;
};
int Printer::countPrinters = 0;

class Laser : public Printer
{
public:
  Laser()
  {
    countPrinters++;
    tipo = "soy una impresora laser";
  }
  void printOn(SimpleText* s)
  {
    cout<<tipo<<endl;
    cout<<s->getData()<<endl;
  }
  void printOn(FormatedText* f)
  {
    cout<<tipo<<endl;
    cout<<f->getData()<<endl;
  }
  void printOn(Image* i)
  {
    cout<<tipo<<endl;
    cout<<i->getData()<<endl;
  }
  void printOn(TarjetaPresentacion* t)
  {
    cout<<tipo<<endl;
    cout<<t->getData()<<endl;
  }
};

class Inyeccion : public Printer
{
public:
  Inyeccion()
  {
    countPrinters++;
    tipo = "soy una impresora de inyeccion";
  }
  void printOn(SimpleText* s)
  {
    cout<<tipo<<endl;
    cout<<s->getData()<<endl;
  }
  void printOn(FormatedText* f)
  {
    cout<<tipo<<endl;
    cout<<f->getData()<<endl;
  }
  void printOn(Image* i)
  {
    cout<<tipo<<endl;
    cout<<i->getData()<<endl;
  }
  void printOn(TarjetaPresentacion* t)
  {
    cout<<tipo<<endl;
    cout<<t->getData()<<endl;
  }
};

class Pdf : public Printer
{
public:
  Pdf()
  {
    countPrinters++;
    tipo = "soy una impresora de pdf";
  }
  void printOn(SimpleText* s)
  {
    cout<<tipo<<endl;
    cout<<s->getData()<<endl;
  }
  void printOn(FormatedText* f)
  {
    cout<<tipo<<endl;
    cout<<f->getData()<<endl;
  }
  void printOn(Image* i)
  {
    cout<<tipo<<endl;
    cout<<i->getData()<<endl;
  }
  void printOn(TarjetaPresentacion* t)
  {
    cout<<tipo<<endl;
    cout<<t->getData()<<endl;
  }
};

class Postscript : public Printer
{
public:
  Postscript()
  {
    countPrinters++;
    tipo = "soy la impresora Postscript";
  }

  void printOn(SimpleText* s)
  {
    cout<<tipo<<endl;
    cout<<s->getData()<<endl;
  }
  void printOn(FormatedText* f)
  {
    cout<<tipo<<endl;
    cout<<f->getData()<<endl;
  }
  void printOn(Image* i)
  {
    cout<<tipo<<endl;
    cout<<i->getData()<<endl;
  }
  void printOn(TarjetaPresentacion* t)
  {
    cout<<tipo<<endl;
    cout<<t->getData()<<endl;
  }
};

class Portatil : public Printer
{
public:
  Portatil()
  {
    countPrinters++;
    tipo = "soy una impresora portatil";
  }
  void printOn(SimpleText* s)
  {
    cout<<tipo<<endl;
    cout<<s->getData()<<endl;
  }
  void printOn(FormatedText* f)
  {
    cout<<tipo<<endl;
    cout<<f->getData()<<endl;
  }
  void printOn(Image* i)
  {
    cout<<tipo<<endl;
    cout<<i->getData()<<endl;
  }
  void printOn(TarjetaPresentacion* t)
  {
    cout<<tipo<<endl;
    cout<<t->getData()<<endl;
  }
};

void SimpleText::printOn(Printer* p)
{
  p->printOn(this);
}
void FormatedText::printOn(Printer* p)
{
  p->printOn(this);
}
void Image::printOn(Printer* p)
{
  p->printOn(this);
}
void TarjetaPresentacion::printOn(Printer* p)
{
  p->printOn(this);
}

void printAllDocuments(Document** d, int countDocs, Printer** p, int countPrinters)
{
  for(int j=0; j<countDocs; j++)
    for(int i=0; i<countPrinters; i++)
    {
      d[j]->printOn(p[i]); //should work on any printer and for any document
    }
}
int main()
{
  Document* documents[] = {new SimpleText, new FormatedText, new Image, new TarjetaPresentacion};
  Laser* l = Printer::getInstance<Laser>();
  Pdf*p = Printer::getInstance<Pdf>();
  Inyeccion* i = Printer::getInstance<Inyeccion>();
  Postscript* pst = Printer::getInstance<Postscript>();
  Portatil* prt = Printer::getInstance<Portatil>();
  Printer* printers[] = { l, p, i, pst, prt};

  printAllDocuments(documents, Document::countDocs, printers, Printer::countPrinters);

  return 0;
}

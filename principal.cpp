#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    this->dibujar();
    ui->outCuadro->setPixmap(lienzo);
}
Principal::~Principal()
{
    delete ui;
}

void Principal::paintEvent(QPaintEvent *event)
{
    ui->outCuadro->setPixmap(lienzo);
}

void Principal::dibujar()
{
    lienzo.fill(Qt::white);

    QPainter painter(&lienzo);

    int x = 0;
    int y = 0;

    //Barra 1
    // Crear un pincel para los bordes
    QPen pincel;
    pincel.setWidth(5);
    //pincel.setColor(Qt::green);
    pincel.setJoinStyle(Qt::MiterJoin);

    // Crear un objeto color para el relleno
        QColor colorRelleno1(190,120,162);
        // Crear otro objeto color para el borde
        QColor colorBorde1(78,3,48);

    // Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setPen(pincel);
    painter.setBrush(colorRelleno1);

    //Obtener datos para la primera barra
    int nota1=ui->inNota1->value();
    int altoN1=this->getAlto(nota1);
    int incYN1=this->incY(altoN1);

    // Dibujar primera barra
    painter.drawRect(x+50, y+50+incYN1,100,+altoN1);
    painter.drawText(x+95,y+480,"");

    //Barra 2
    // Crear un objeto color para el borde y relleno
    QColor colorRelleno2(150,107,100);
    QColor colorBorde2(80,107,100);

    // Cambiar el color del pincel
    pincel.setColor(colorBorde2);

    // Volver a establecer el pincel al "pintor"
    painter.setPen(pincel);

    // Establecer el color al brush (relleno)
    painter.setBrush(colorRelleno2);

    //Obtener datos para la segunda barra
    int nota2=ui->inNota2->value();
    int altoN2=this->getAlto(nota2);
    int incYN2=this->incY(altoN2);

    // Dibujar segunda barra
    painter.drawRect(x+190, y+50+incYN2, 100, altoN2);
    painter.drawText(x+215,y+480,"");

    // Barra 3
    // Creando los colores de la tercera barra
       QColor cRellenoBarra3(253, 253, 115);
       QColor cBordeBarra3(174, 174, 51);



    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Obtener datos para la tercera barra
    int nota3=ui->inNota3->value();
    int altoN3=this->getAlto(nota3);
    int incYN3=this->incY(altoN3);

    // Dibujar tercera barra
    painter.drawRect(x+330,y+50+incYN3,100,altoN3);
    painter.drawText(x+370,y+480,"");

    // Estableciendo colores al puncel y al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    // Promedio
    // Poner el color y el estilo
    QColor colorLinea(41,223,41);
    pincel.setColor(colorLinea);
    painter.setPen(pincel);

    // Obtener el promedio de l// Dibujar tercera barraas notas
    float promedio = (nota1 + nota2 + nota3) / 3.0;
    int alto4 = this->getAlto(promedio);
    int incYN4 = this->incY(alto4);


    // Dibujar la raya del promedio
    painter.drawLine(x+30,y+50+incYN4,450,y+50+incYN4);
    ui->inPromedio->setText(QString::number(promedio));


}

void Principal::promediar(){

}

int Principal::getAlto(int valor)
{
    return 4*valor;
}

int Principal::incY(int alto)
{
    return 400-alto;
}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen",QString(),"Imagenes (*.png)");
    if (!nombreArchivo.isEmpty()){
        if (lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen","Archivo guarado en: " + nombreArchivo);
        else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }
}

void Principal::on_inNota1_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota2_valueChanged(int arg1)
{
    dibujar();
}

void Principal::on_inNota3_valueChanged(int arg1)
{
    dibujar();
}



void Principal::on_actionNuevo_triggered()
{
    ui->inNota1->setValue(0);
    ui->inNota2->setValue(0);
    ui->inNota3->setValue(0);
}


void Principal::on_btnPromediar_clicked()
{
 promediar();
}


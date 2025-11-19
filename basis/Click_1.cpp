/* (Qt) при нажатии на кнопку, считываение цифр с двух lineEdit, и вывод их суммы в третьем lineEdit */ 

void MainWindow::on_pushButton_3_clicked()
{
    int x, y, z;

        //Считаем значение из первого lineEdit
        QString S1 = ui->lineEdit->text();
        //Переведем значение в число
        x = S1.toInt();

        //Считаем значение из второго lineEdit
        QString S2 = ui->lineEdit_2->text();
        //Переведем значение в число
        y = S2.toInt();

        //Посчитаем сумму
        z = x + y;

        //Выведем результат
        ui->lineEdit_3->setText(QString::number(z));
}

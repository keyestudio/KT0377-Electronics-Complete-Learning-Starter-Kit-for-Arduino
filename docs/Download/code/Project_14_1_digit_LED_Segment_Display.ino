/ *

Kit de inicio para aprendizaje de electrónica con Arduino

Proyecto 14

Display de segmento LED de 1 dígito

Editado por Keyes

* / 

void displayNumber(int n) {

digitalWrite(a, num[n][0]);

...

digitalWrite(g, num[n][6]);

digitalWrite(dp, LOW); // Punto decimal apagado

}
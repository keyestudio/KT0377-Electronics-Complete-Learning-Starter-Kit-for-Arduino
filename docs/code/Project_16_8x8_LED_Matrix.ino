/*

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 16

Matriz de LED 8x8

Editado por Keyes

*/

void Clear() {

for (int i = 0; i < 8; i++) {

digitalWrite(R[i], LOW);

digitalWrite(C[i], HIGH);

}

}
/ *

Kit de Inicio para Aprender Electrónica con Arduino

Proyecto 28

Contenedor Inteligente

Editado por Keyes

* /

// Envía un pulso alto de 10 microsegundos para activar el sensor ultrasónico

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

// Lee la duración del pulso alto en el pin Echo

duration = pulseIn(echoPin, HIGH);
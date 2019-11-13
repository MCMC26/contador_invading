
int LED13 = 13;
int Trigger_izq = 11;
int Echo_der = 10;
boolean estado = false;
int Compress = 9;
int contador = 0;
int tiempo = 1;
int temporizador = 0;


int izquierdo = 0;
int izquierdo_cuenta = 0;
int izquierdo_anterior = 0;
int izquierdo_ahora = 0;

int izquierdo_duracion, izquierdo_distancia;



void setup() {
  pinMode(LED13, OUTPUT);
  pinMode(Trigger_izq, OUTPUT);
  pinMode(Echo_der, INPUT);
  pinMode(Compress, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite (Trigger_izq, HIGH);
  delayMicroseconds (10);
  digitalWrite (Trigger_izq, LOW);
  izquierdo_duracion = pulseIn (Echo_der, HIGH);
  izquierdo_distancia = (izquierdo_duracion / 2) / 29.1;

  if (izquierdo_distancia < 40) { // Se esta a menos de 20 activa izquierdo.
    izquierdo = HIGH;
    digitalWrite (LED13, HIGH);

    if (estado == false) {
      estado = true;
      contador++;
      temporizador += 35;    
    }
  }
  else {
    estado = false;
    izquierdo = LOW;
    digitalWrite (LED13, LOW);
    //digitalWrite (Compress, LOW);
  }

  //izquierdo = digitalRead(LED13);

  if (izquierdo ==  HIGH) { // Comprueba activado izquierdo.
    izquierdo_ahora = 1;
  }
  else {
    izquierdo_ahora = 0;
  }


  if (izquierdo_ahora != izquierdo_anterior) {
    if (izquierdo_ahora == 1) {
      izquierdo_cuenta = izquierdo_cuenta + 1;
     
    }
  }
  izquierdo_anterior = izquierdo_ahora;

  delay(100);
  if (temporizador > 0) {
    temporizador--;
  }

  if (temporizador <= 0 ) {
    digitalWrite (Compress, LOW);
  } else {
    digitalWrite (Compress, HIGH);
  }
  
  Serial.println(temporizador);


}

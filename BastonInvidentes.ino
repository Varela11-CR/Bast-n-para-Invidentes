const int TRIG = 6;               //Se crea la constante y se le asigna el valor del pin TRIG
const int ECO = 5;                //Se crea la constante y se le asigna el valor del pin ECO
const int BUZZER = 3;             //Se crea la constante y se le asigna el valor del pin BUZZER
const int LGREEN = 9;             //Se crea la constante y se le asigna el valor del pin LGREEN
const int LYELLOW = 10;           //Se crea la constante y se le asigna el valor del pin LYELLOW
const int LRED = 11;              //Se crea la constante y se le asigna el valor del pin LRED
int duracion;
int distancia;

void setup() {

  pinMode(TRIG, OUTPUT);            //Pin TRIG = 10, se declare como salida
  pinMode(ECO, INPUT);              //Pin ECO = 9, se declare como entrada
  pinMode(BUZZER, OUTPUT);          //Pin BUZZER = 3, se declare como salida
  pinMode(LGREEN, OUTPUT);
  
  Serial.begin(9600);               //Se establece la transferencia para ver resultado en el Monitor Serie

}

void loop() {

  digitalWrite(TRIG, HIGH);         //Se activa el pin TRIG 
  delay(200);                       //Se hace un tiempo de 200 milisegundos de retraso
  digitalWrite(TRIG, LOW);          //Se desactiva el pin TRIG
  
  duracion = pulseIn(ECO, HIGH);    //Se guarda en la variable "duracion" el tiempo que duro el sensor en enviar y recibir el sonido
  distancia = duracion / 58.2;      //Se guarda en la variable "distancia" la división entre la "duracion" y 58.2 (valor constante dado por el fabricante del sensor)
  
  Serial.println(distancia);        //Imprime en el Monitor Serie el valor de la variable "distancia"
  delay(200);                       //Se hace un tiempo de 200 milisegundos de retraso

  if(distancia <= 38 && distancia >= 18){

    activarBuzzer(4500, 5);
    activarLed(LRED, 5);
    
    }

  if(distancia <= 48 && distancia >= 38){

    activarBuzzer(4250, 5);
    activarLed(LYELLOW, 5);
    
    }

  if(distancia <= 58 && distancia >= 48){

    activarBuzzer(4000, 5);
    activarLed(LGREEN, 5);
    
    }

}


//Función la cual activa el BUZZER, con los datos solicitados se genera el tono y se personaliza el delay
void activarBuzzer(int tono, const int multi){

  tone(BUZZER, tono);             //Se activa el pin BUZZER, y se da una frecuencia para que emita el sonido
  delay(distancia * multi);       //Se hace el tiempo de retraso multiplicando la variable "distancia" por la constante introducida en la función
  noTone(BUZZER);                 //Se desactiva el pin BUZZER
  
}

//Función la cual activa la luz LED correspondiente y se personaliza el delay
void activarLed(int led, const int multi){

  analogWrite(led, 255);           //Se activa el pin LED correspondiente, y se da el valor más alto para que brille al máximo
  delay(distancia * multi);       //Se hace el tiempo de retraso multiplicando la variable "distancia" por la constante introducida en la función
  analogWrite(led, 0);            //Se desactiva el pin LED
  
}

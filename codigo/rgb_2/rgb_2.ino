/* www.educachip.com */

//Se definen las variables que se van a utilizar para establecer los
//colores. Éstas deben estar asociadas a pines digitales PWM e irán
//unidas a los cátodos de cada uno de los colores.
int Rojo = 3;
int Verde = 11;
int Azul = 10;

//Se almacenan los valores relativos a la intensidad de cada color
//(las candelas de cada color).
int mcdRojo = 300;
int mcdVerde = 1000;
int mcdAzul = 400;

//Se realiza una relación entre las candelas de los distintos
//colores.
int GradoRojo = (mcdRojo / mcdVerde);
int GradoVerde = (mcdVerde / mcdVerde);
int GradoAzul = (mcdAzul / mcdVerde);

void setup() {

  //Se establecen los pines definidos como salidas para poder
  //la diferencia de voltaje con respecto a la alimentación común.
  pinMode(Rojo, OUTPUT);
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);

}

//Se crea un módulo auxiliar que facilitará la tarea de establecer
//los voltajes asociados a cada color.
//El valor de las variables R, G y B debe ser un entero entre 0 y 255
//siendo 255 el valor relativo a la máxima luminosidad de cada color.
void EstablecerColor(int R, int G, int B) {

  //Se utiliza la expresión X/GradoX para multiplicar el valor de la
  //salida PWM por un número que consiga una intensidad de luz
  //equiparable entre todos los colores.
  //Se debe tener en cuenta que la salida máxima es 255, por tanto,
  //la compensación entre los colores se pierde si la relación
  //X/GradoX genera un valor superior a 255.
  analogWrite(Rojo, (R / GradoRojo));
  analogWrite(Verde, (G / GradoVerde));
  analogWrite(Azul, (B / GradoAzul));

}

void loop() {

  //Se representan colores pseudoaleatorios en el LED RGB mediante el
  //uso de la instrución random(min,max);.
  EstablecerColor(random(0, 255), random(0, 255), random(0, 255));

  //Se utiliza un delay para que de tiempo algo observador a apreciar
  //los colores.
  delay(1000);

}

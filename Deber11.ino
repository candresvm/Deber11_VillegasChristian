/* 
 *        UNIVERSIDAD TECNICA DEL NORTE
 *                FICA - CITEL
 *            SISTEMAS EMBEBIDOS
 *                  DEBER 11
 *            CHRISTIAN VILLEGAS
 * 
 */
// matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};

int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //sumatoria x
float ln=0; // sumatoria del logaritmo de x
float mul=0; // multiplicacion entre Ex y ln
long int Ex2=0; //sumatoria x^2
long int Ex_2=0; //sumatoria Ex^2
int n= 14; //tama;o de muestras
float Bo; //coeficiente del exponente
float m; //pendiente
String dato; //recibir estatura
int estatura; //convertir dato
float w; // coeficiente de la base
float peso;
float m1; //aux

void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];
    ln=ln+log(matriz[fil][1]);
    mul=mul+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  Bo=(float(n*mul)-float(Ex*ln))/(float(n*Ex2-Ex_2));
  m1=(ln/n)-(Bo*(Ex/n));
  w=exp(m1);
  Serial.println("El modelo es: ");
  Serial.println(String("y= ")+String(w,4)+String("*")+String("e^(")+String(Bo,4)+String(")"));
  Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=w*exp(estatura*Bo);
    Serial.println("");
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
  }
}

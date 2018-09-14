/*
 * Este programa calcula el Indice de Masa Corporal, este se obtiene
 * dividiendola altura (en metros) entre el peso (en kilogramos) al cuadrado.
 * El usuario tiene que elegir el sistema de unidades,
 * las opciones son metrico e imperial. Si el usuario elige metrico, se hace
 * la operacion directamente, pero si elige imperial, se pasa a metrico primero.
 *
 * Si el indice es menor a 18.5 tiene bajo peso.
 * Si es mayor o igual a 18.5 y menor a 25, tiene peso normal.
 * Si es mayor o igual a 25 y menor a 30, tiene sobrepeso.
 * Y si es mayor o igual a 30 tiene obesidad.
 *
 * Autor: Jonathan Nuñez de Caceres
 * Fecha: 13 de Septiembre del 2018.
 * Correo: A01411277@itesm.mx
 */

#include <stdio.h>

// Funcion que imprime el menu a pantalla.
void PrintMenu(){
    printf("Elige tu sistema de unidades:\n");
    printf("1. Sistema metrico.\n");
    printf("2. Sistema imperial.\n");
}

// Funcion que hace los calculos y da el resultado.
void BMICalculation(float weight, float height) {
    float BMI; // Variable que guardara el indice.
    BMI = weight / (height * height); // Formula para el indice.
    printf("Tu IMC es: %.1f\n", *&BMI);

    if(BMI < 18.5){
        printf("Tienes bajo peso.");
    }
    else if(BMI >= 18.5 && BMI < 25 ){
        printf("Tienes un peso normal.");
    }
    else if(BMI >= 25 && BMI < 30){
        printf("Tienes sobrepeso.");
    }
    else{
        printf("Tienes obesidad.");
    }
}

// Funcion que hace las conversiones del sistema imperial a metrico.
void Conversion(float height, float inches, float weight){
    inches += height * 12; // A las pulgadas se le suman los pies en pulgadas.
    height = inches / 39.37; // La altura en pies se cambia a la altura en metros.
    weight /= 2.2046; // Las libras se convierten a kilogramos.

    // Se llama la funcion de los calculos con los valores en sistema metrico.
    BMICalculation(weight, height);
}

// Funcion donde se elige el sistema y se introducen los datos.
void ChoiceAndData(){
    // Declaracion de variables.
    float weight;
    float height;
    float inches;

    int unitChoice;
    scanf("%d", &unitChoice);

    // Opcion 1 es sistema metrico.
    if(unitChoice == 1){
        printf("Ingresa tu estatura en metros:");
        scanf("%f", &height);
        printf("Ingresa tu peso en kilogramos:");
        scanf("%f", &weight);

        BMICalculation(weight, height);
    }
    // Opcion 2 es sistema imperial.
    else if(unitChoice == 2){
        printf("Ingresa tu estatura en pies y pulgadas (separados por coma):");
        scanf("%f, %f", &height, &inches);
        printf("Ingresa tu peso en libras:");
        scanf("%f", &weight);

        Conversion(height, inches, weight);
    }
    // Si elige un numero invalido se repite la funcion ChoiceAndData.
    else{
        printf("Ingresa un numero valido:");
        ChoiceAndData();
    }
}

int main() {
    printf("-----CALCULA TU INDICE DE MASA CORPORAL-----\n");

    // Se imprime el menu.
    PrintMenu();

    // Se elige la opcion, se ingresan datos, y desde esa funcion se llama
    // a la funcion de los calculos, o si se elige el imperial se hacen las
    // conversiones primero.
    ChoiceAndData();

    return 0;
}

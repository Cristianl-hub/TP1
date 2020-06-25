#include <stdio.h>
#include <stdbool.h> 

//Midiclorianos
const float DEF_MIDI = 0.0F;
const float MIN_MIDI = 100.0F;
const float MAX_MIDI = 2999.9F;
const bool MIDI_VERIF = true;
const bool MIDI_NO_VERIF = false;
const float DEF_INF = 340.0F;

//Voluntad

const bool VOL_VERIF = true;
const bool VOL_NO_VERIFICADA = false;
const char DEF_VOL = 'q';
#define VOL_FLOJA 'f'
#define VOL_BUENA 'b'
#define VOL_MEDIANA 'm'
#define VOL_ALTA 'a'
#define VOL_ENORME 'e'
#define VOL_PELIGROSA 'p'

//Pasado
const char DEF_PAS = 'u';
#define PAS_BUENO 'b'
#define PAS_NORMAL 'n'
#define PAS_TRAGICO 't'
const bool PAS_VERIF = true;
const bool PAS_NO_VERIF = false;


const float INF_MULT = 3.4F;
const float OSCURIDAD =  0.001117684315F;

/*Numerico de Voluntad
FB = Floja/Buena
MA = Mediana/Alta
EP = Enorme/Peligrosa
*/

const float VOL_FB = 10.3F;
const float VOL_MA = 54.5F;
const float VOL_EP = 103.4F;

/* Numerico de Pasado
NT = Normal/Tragico
B = Bueno
*/
const float PAS_NT = 0.4F;
const float PAS_B = 1.5F;

#define MSJ_TITULO "\nStar Code: The Rise of Programmer\n\nBienvenido Padawans\n"
#define MSJ_PRES "Recuerda que dependiendo la influencia de la voluntad y pasado veremos la probabilidad de que te conviertas al lado oscuro\n"

#define MSJ_INF "\nIngresa tu influencia en Midiclorianos (Recorda que el rango es de 100.0 a 2999.9)\n\n"
#define MSJ_MAL_INGRESO "Valor de Midiclorianos no valido [X]\n\n"
#define MSJ_INGRESO_CORRECTO "Valor de Midiclorianos valido [V]\n"

#define MSJ_NIV_VOL "Ingresa tu nivel de voluntad\nFloja [f] - Buena [b] - Mediana [m] - Alta [a] - Enorme [e] - Peligrosa [p]\n"
#define MSJ_VOL_CORRECTO "Valor de Voluntad valido [V]\n"
#define MSJ_VOL_INCORRECTO "Valor de Voluntad no valido [X]\n\n"


#define MSJ_NIV_PAS "Ingresa tu nivel de pasado\nBueno [b] - Normal [n] - Tragico [t]\n"

#define MSJ_YEDI "Transmite lo que has aprendido: Fuerza, Maestria; pero insensatez, debilidad, fracaso tambien. ¡Si, fracaso sobre todo! El mejor profesor, el fracaso es.\n By Master Yoda"

void introduccion();

bool verificar_midiclorianos(float midi_verificar);
float recibir_midiclorianos();

char recibir_voluntad();
bool verificar_voluntad_recib(char vol_verificar);

char recibir_pasado();
bool verificar_pasado_recib(char pas_verificar);

void introduccion(){
	printf(MSJ_TITULO);
	printf(MSJ_PRES);
}

float recibir_midiclorianos(){
	float midi_rec = DEF_MIDI;
	do{
		printf(MSJ_INF);
		scanf("%f", &midi_rec);

		if ( !verificar_midiclorianos(midi_rec) ){
			printf(MSJ_MAL_INGRESO);	
		}else{
			printf(MSJ_INGRESO_CORRECTO);
		}
	}while( !verificar_midiclorianos(midi_rec) );	

	return midi_rec;
}

bool verificar_midiclorianos(float midi_verificar){
	bool verificado = MIDI_VERIF;
	if ((midi_verificar < MIN_MIDI) || (midi_verificar > MAX_MIDI)){
		verificado = MIDI_NO_VERIF;
	}
	return verificado;
}

char recibir_voluntad(){
	char vol_recib = DEF_VOL;
	do{
		printf(MSJ_NIV_VOL);
		scanf(" %c", &vol_recib);
		if (verificar_voluntad_recib(vol_recib)){
			printf(MSJ_VOL_CORRECTO);
		}else{
			printf(MSJ_VOL_INCORRECTO);
		}
	}while(!verificar_voluntad_recib(vol_recib));
	
	return vol_recib;
}

bool verificar_voluntad_recib(char vol_verificar){
	bool vol_verificada = VOL_NO_VERIFICADA;
	if((vol_verificar == VOL_FLOJA || vol_verificar == VOL_BUENA || vol_verificar == VOL_MEDIANA || vol_verificar == VOL_ALTA || vol_verificar == VOL_ENORME || vol_verificar == VOL_PELIGROSA)){
		vol_verificada = VOL_VERIF;
	}
	return vol_verificada;
}

char recibir_pasado(){
	char pas_recib = DEF_PAS;
	do{
		printf(MSJ_NIV_PAS);
		scanf(" %c", &pas_recib);
		if (verificar_voluntad_recib(pas_recib)){
			printf(MSJ_VOL_CORRECTO);
		}else{
			printf(MSJ_VOL_INCORRECTO);
		}
	}while( !verificar_voluntad_recib(pas_recib) );
	
	return pas_recib;
}

bool verificar_pasado_recib(char pas_verificar){
	bool pas_verificado = PAS_NO_VERIF;
	if((pas_verificar == PAS_BUENO || pas_verificar == PAS_NORMAL || pas_verificar == PAS_TRAGICO)){
		pas_verificado = PAS_VERIF;
	}
	return pas_verificado;
}

/*
float calculo_influencia(float midi_rec, float INF_MULT){
	float rec_inf = DEF_INF;
	rec_inf = midi_rec * INF_MULT;
	scanf("%f", &rec_inf);

	return rec_inf;
}

Calculo:

Influencia = midiclorianos * constante de influencia

-Unidad: Fuerza

Probabilidad de convertirse =

voluntad + (constante de oscuridad * influencia)/pasado -Unidad: %
*/

int main(){
	float midiclorianos = DEF_MIDI;
	char voluntad = DEF_VOL;
	char pasado = DEF_PAS;
	//float influencia = DEF_INF;

	introduccion();

	midiclorianos = recibir_midiclorianos();
	printf("Midiclorianos recibidos: %.1f\n", midiclorianos);

	voluntad = recibir_voluntad();
	printf("Voluntad recibida: %c\n", voluntad);

	pasado = recibir_pasado();
	printf("Voluntad recibida: %c\n", pasado);
/*
	influencia = calculo_influencia();
	printf("Influencia Calculada: %.1f\n", influencia);
*/
	return 0;
}
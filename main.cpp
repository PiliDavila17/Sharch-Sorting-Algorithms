// =================================================================
//
// File: main.cpp
// Author: Maria del Pilar Davila Verduzco
// Date: 03/09/2022
// Compilacion: g++ -std=c++11 main.cpp -o app --> ./app input_file output_file
//
// =================================================================
#include <iostream>
#include <vector>
#include "header.h"
#include <fstream>
#include "search.h"
#include "bubble.h"
#include "selection.h"
#include "insertion.h"

using namespace std;

 //argc=numero de elementos que llegan
 //argv=elementos

int main(int argc, char* argv[]) {
	//leer los archivos
	ifstream inputFile;
	ofstream outputFile; //Escribir archivos

	//REVISION DE LA ENTRADA DE ARCHIVOS
	if (argc !=3){
		cout<<"Uso: "<<argv[0]<<"Input.txt Output.txt";
		return -1;
	}
	inputFile.open(argv[1]);
	if (inputFile.fail()){
		cout<<"No se pudo abrir el archivo de entrada";
		return -1;
	}
	outputFile.open(argv[2]);
	if(outputFile.fail()){
		cout<<"No se pudo abrir el archivo de salida.";
		return -1;
	}

	//Programa:

	int N, N2, num; //N=datos -> N2=buscado -> num=guardados temporal
	inputFile>>N;//Asigna los datos a N (primer conjunto de numeros del archivo)

	//Vector que almanecenaran los numeros 
	vector<int> nums(N);

	//Lectura de los numeros 
	for (int i=0; i<N; i++){
		inputFile>>num;
		nums[i]=num; //Guarda los numeros 
	}

	//Algoritmos de ordenamientos 
	int bubble_comp, selection_comp, insertion_comp; //Contadores de cada algoritmo

	vector<int> ordered = nums;
	bubble_comp = bubbleSort(ordered);
	ordered = nums; //desordena

	selection_comp = selectionSort(ordered);
	ordered = nums;

	insertion_comp = insertionSort(ordered);

	outputFile << bubble_comp << ' ' 
			   << selection_comp << ' ' 
			   << insertion_comp << '\n' << '\n';

//BUSQUEDA
	inputFile >> N2;
	std::pair<int, int> result; // "pair" estructura de datos que tiene dos tipos de dato result es el nombre del pair
 	for (int i = 0; i < N2; i++) {
		inputFile >> num;
		result = sequentialSearch(ordered, num); //busca num en ordered 
		outputFile << result.first << ' ' //indice
				   << result.second << ' '; //contador
				   
		//Metodo BinarySearch
		result = binarySearch(ordered, num);  //indice, contador
		outputFile << result.second << '\n'; 
    } 

	inputFile.close();
	outputFile.close();
}
	

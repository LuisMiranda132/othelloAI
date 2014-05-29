#include "othello_cut.h"
#include "utils.h"
#include <stdio.h>

//recorre el arbol buscando un costo mayor que el v que recibe

bool test(state_t pos, int depth, int v, bool max, bool mayor)  {
	
	
	
	if (mayor) {  //caso test con el operador >
		if(pos.terminal()) {
			return (max ? (pos.value()>v) : (-pos.value()>v));
			//return pos.value()>v;
		}
		
		std::vector<int> succ(pos.getChildren(max));
		int i;
		if (max) {		//si es un nodo max
			for (i = 0; i < succ.size(); ++i) { 
				if (test(pos.move(max,succ[i]), depth-1, v, !max, 1)) {
					return 1; //si hay al menos un nodo mayor en el subarbol
				}
			}
			return 0; //si no hay un nodo mayor en el subarbol
		
		}
		else {		//si es un nodo/nivel min
			for (i = 0; i < succ.size(); ++i) { 
				if (!test(pos.move(max,succ[i]), depth-1, v, !max, 1)) {
					return 0;
				}
			}
			return 1;
		}
	}
	
	else {  //caso test con el operador <
		if (pos.terminal()) {
			return (max ? (pos.value()<v) : (-pos.value()<v));
			//return pos.value()<v;
		}
	
		std::vector<int> succ(pos.getChildren(max));
		int i;
		if (max) {  //si es un nodo/nivel max
			for (i = 0; i < succ.size(); ++i) { 
				if (!test(pos.move(max,succ[i]), depth-1, v, !max, 0)) {
					return 0;  //si hay al menos un nodo mayor
				}
			}
			return 1;  //si no hay ningun nodo mayor
		
		}
		else {
			for (i = 0; i < succ.size(); ++i) { 
				if (test(pos.move(max,succ[i]), depth-1, v, !max, 0)) {
					return 1;
				}
			}
			return 0;
		
		}
	}
}

int scout(state_t pos, int depth, bool max) {
	
	std::vector<int> succ(pos.getChildren(max));
	int v;
	bool mayor = true;
	int i;
	
	if (pos.terminal()) { //caso hoja
		return (max ? pos.value() : -pos.value());
		//return pos.value();
	}
	
	else {  //consigue el valor de la rama izquierda
		v = scout(pos.move(max,succ[0]), depth-1, !max);
	}
	for (i = 1; i < succ.size(); ++i) {
		if (max) {
		//for (i = 1; i < succ.size(); ++i) {
			if (test(pos.move(max,succ[i]), depth-1, v, !max, 1)) {  //verifica que no haya mejor costo
				v = scout(pos.move(max,succ[i]), depth-1, !max);  
			}
		//} 
		}
		else {
		//for (i = 1; i < succ.size(); ++i) {
			if (test(pos.move(max,succ[i]), depth-1, v, !max, 0)) {  //verifica que no haya mejor costo
				v = scout(pos.move(max,succ[i]), depth-1, !max); 
			}
		//}
		}
	}
	return v;
}
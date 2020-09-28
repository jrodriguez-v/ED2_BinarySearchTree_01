package main;

import java.util.ArrayList;
import java.util.List;

import objetos.hoja;

public class main {

	public static void main(String[] args) {
		// Variables
		List<hoja> list_arbol = new ArrayList<hoja>();
		List<Integer> list_nodos = new ArrayList<Integer>();
		hoja root;

		// Agregar datos a valores a la lista de nodos
		list_nodos.add(7);
		list_nodos.add(14);
		list_nodos.add(28);
		list_nodos.add(5);
		list_nodos.add(9);
		list_nodos.add(8);
		list_nodos.add(21);
		list_nodos.add(3);
		list_nodos.add(15);
		list_nodos.add(24);
		list_nodos.add(100);
		list_nodos.add(1);

		System.out.println("Creando árbol.... \n");
		
		for (int objNodo : list_nodos) {
			root = new hoja(objNodo, null, null);
			if (list_arbol.isEmpty()) {
				list_arbol.add(root);
				System.out.println("La raiz del árbol es el nodo " + list_arbol.get(0).getRoot() + ".");
			} else {
				list_arbol.indexOf(agregarNuevo(objNodo, list_arbol.get(0)));
			}
		}
		
		System.out.println("\nEl árbol a sido creado correctamente.");


		// imprimir en orden
		System.out.println("\nEl recorrido del árbol en Orden es:");
		printOrden(list_arbol.get(0));
		
		// imprimir en post-orden
		
		System.out.println("\n\nEl recorrido del árbol en Postorden es:");
		printPostOrden(list_arbol.get(0));
		
		// imprimir en pre-orden
		System.out.println("\n\nEl recorrido del árbol en Preorden es:");
		printPreOrden(list_arbol.get(0));
	}

	public static hoja agregarNuevo(int valorNuevo, hoja nodoActual) {
		if (nodoActual.getRoot() < valorNuevo) {
			if (nodoActual.getRight() != null) {
				agregarNuevo(valorNuevo, nodoActual.getRight());
			} else {
				hoja root = new hoja(valorNuevo, null, null);
				nodoActual.setRight(root);
				System.out.println("El nodo " + valorNuevo + " esta a la derecha del nodo " + nodoActual.getRoot() + ".");
			}
		} else if (nodoActual.getLeft() != null) {
			agregarNuevo(valorNuevo, nodoActual.getLeft());
		} else {
			hoja root = new hoja(valorNuevo, null, null);
			nodoActual.setLeft(root);
			System.out.println("El nodo " + valorNuevo + " esta a la izquierda del nodo " + nodoActual.getRoot() + ".");
		}

		return nodoActual;
	}

	public static void printOrden(hoja nodo) {
		if(nodo != null) {
			printOrden(nodo.getLeft());
			System.out.print(nodo.getRoot() + " ");
			printOrden(nodo.getRight());
		}
	}
	
	public static void printPreOrden(hoja nodo) {
		if(nodo != null) {
			System.out.print(nodo.getRoot() + " ");
			printPreOrden(nodo.getLeft());
			printPreOrden(nodo.getRight());
		}
	}

	public static void printPostOrden(hoja nodo) {
		if(nodo != null) {
			printPostOrden(nodo.getLeft());
			printPostOrden(nodo.getRight());
			System.out.print(nodo.getRoot() + " ");
		}
	}
	
	

}

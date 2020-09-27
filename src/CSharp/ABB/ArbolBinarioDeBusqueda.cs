using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABB
{
    public class ArbolBinarioDeBusqueda
    {
        #region Properties
        public Nodo Raiz { get; set; }
        #endregion

        #region Constructors
        public ArbolBinarioDeBusqueda()
        {
            this.Raiz = null;
        }
        #endregion

        #region Methods
        public Nodo Insertar(int valor, Nodo nodo)
        {
            Nodo temp = null;

            if (nodo == null)
            {
                temp = new Nodo();
                temp.Valor = valor;

                return temp;
            }

            if (valor < nodo.Valor)
            {
                nodo.Izquierdo = Insertar(valor, nodo.Izquierdo);
            }

            if (valor > nodo.Valor)
            {
                nodo.Derecho = Insertar(valor, nodo.Derecho);
            }

            return nodo;
        }

        private Nodo CrearNodo(int valor)
        {
            var nodo = new Nodo();
            nodo.Valor = valor;
            return nodo;
        }

        public void PreOrden(Nodo raiz)
        {
            if (raiz == null) return;

            Console.WriteLine(raiz.Valor);

            if (raiz.Izquierdo != null) PreOrden(raiz.Izquierdo);

            if (raiz.Derecho != null) PreOrden(raiz.Derecho);
        }

        public void EnOrden(Nodo raiz)
        {
            if (raiz == null) return;

            if (raiz.Izquierdo != null) EnOrden(raiz.Izquierdo);

            Console.WriteLine(raiz.Valor);

            if (raiz.Derecho != null) EnOrden(raiz.Derecho);
        }

        public void PostOrden(Nodo raiz)
        {
            if (raiz.Izquierdo != null) PostOrden(raiz.Izquierdo);

            if (raiz.Derecho != null) PostOrden(raiz.Derecho);

            Console.WriteLine(raiz.Valor);
        }
        #endregion
    }
}

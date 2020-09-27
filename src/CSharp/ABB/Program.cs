using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABB
{
    class Program
    {
        static void Main(string[] args)
        {
            var arbolBB = new ArbolBinarioDeBusqueda();

            //lista:
            //6,2,8,4,3,5,7,11,9,0,-1,10,12,14

            var raiz = arbolBB.Insertar(6, null);
            arbolBB.Insertar(2, raiz);
            arbolBB.Insertar(8, raiz);
            arbolBB.Insertar(1, raiz);
            arbolBB.Insertar(4, raiz);
            arbolBB.Insertar(3, raiz);
            arbolBB.Insertar(5, raiz);
            arbolBB.Insertar(7, raiz);
            arbolBB.Insertar(11, raiz);
            arbolBB.Insertar(9, raiz);
            arbolBB.Insertar(10, raiz);
            arbolBB.Insertar(0, raiz);
            arbolBB.Insertar(-1, raiz);
            arbolBB.Insertar(12, raiz);
            arbolBB.Insertar(14, raiz);

            Console.WriteLine("Pre orden");
            //preorden (R-I-D)
            //6, 2, 1, 0, -1, 4, 3, 5, 8, 7, 11, 9, 10, 12, 14
            arbolBB.PreOrden(raiz);

            Console.WriteLine("------------------------------------");
            Console.WriteLine("En orden");
            //in order (I-R-D)
            //-1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14
            arbolBB.EnOrden(raiz);

            Console.WriteLine("------------------------------------");
            Console.WriteLine("Post orden");
            //post orden (I-D-R)
            //-1, 0, 1, 3, 5, 4, 2, 7, 10, 9,14, 12, 11, 8, 6
            arbolBB.PostOrden(raiz);

            Console.ReadLine();
        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ABB
{
    public class Nodo
    {
        #region Properties
        public Nodo Izquierdo { get; set; }
        public Nodo Derecho { get; set; }
        public int Valor { get; set; }
        #endregion

        #region Constructors
        public Nodo()
        {
            this.Izquierdo = null;
            this.Derecho = null;
            this.Valor = 0;
        }
        #endregion
    }
}

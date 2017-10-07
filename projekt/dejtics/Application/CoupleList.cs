using System;
using System.Collections.Generic;

namespace Application
{
    class CoupleList
    {
        public LinkedList<Couple> List { get; private set; } = new LinkedList<Couple>();
        public CoupleList() { }
        public void Add(Couple couple)
        {
            List.AddFirst(couple);
        }
    }
}

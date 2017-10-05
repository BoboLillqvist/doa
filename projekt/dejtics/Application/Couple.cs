using System;

namespace Application
{
    public class Couple
    {
        public Person PersonA { get; private set; } = null;
        public Person PersonB { get; private set; } = null;

        public Couple() { }

        public Couple(Person persona, Person personb)
        {
            PersonA = persona;
            PersonB = personb;
        }
    }
}

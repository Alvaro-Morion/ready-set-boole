/*Me llevo 1 cuando ambos son 1.
Sumo los dos números sin llevadas.
Desplazo 1bit lo que me he llevado.
(siguiente iter) sumo lo que me llevé.*/

unsigned int	adder(unsigned int a, unsigned int b)
{
	unsigned int	carrier;

	while (b != 0)
	{
		carrier = a & b;
		a = a ^ b;
		b = carrier << 1;
	}
	return (a);
}

double Power(double x, unsigned long long int n)
{
	if(n  == 0) 
		return 1; 
	double tmp = Power(x, n /2);
	
	if(n %2 == 0)	
		return tmp*tmp; 
	else	
		return tmp*tmp*x; 
		
	
}

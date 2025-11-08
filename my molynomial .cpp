#include<iostream>

using namespace std;

static const int mm=4;

class help{
	friend class polynomial;
	private:
		int exponent;
		float coefficient;
};

class polynomial{
	private:
		int number;
		help hpol[mm];//fellan
		static int index;
	public:
		void print();
		polynomial(int);
		polynomial();
		polynomial operator+(polynomial &);
		polynomial operator-(polynomial &);
		polynomial operator*(polynomial &);
		void set(int &, float &);
		float retriveCoefficient();
		int retriveExponent();
		void giveExponent();
		void giveCoefficient();
		void sort();
		
};
int polynomial::index=0;

int polynomial::retriveExponent(){
	float j;
    cout<<endl<<"enter number of coefficient and retrive exponent: ";
	cin>>j;
	cout<<endl<<"retvive exponent: ";
	for(int i=1;this->hpol[i].exponent !='\0';i++)
		if(this->hpol[i].coefficient == j)
		    return this->hpol[i].exponent;
	return -1;
	
}
float polynomial::retriveCoefficient(){
	int ii;
    cout<<endl<<"enter number exponent and retrive coefficient: ";
	cin>>ii;
	cout<<endl<<"retrive coefficient: ";
	for(int i=1;this->hpol[i].exponent !='\0';i++)
		if(this->hpol[i].exponent == ii)
		    return this->hpol[i].coefficient;
    return -1;
}

polynomial polynomial:: operator+ (polynomial &x){
	polynomial s(mm);//fellan
	int i=1,j=1;
	polynomial::index=0;
	x.sort();
	this->sort();
	while(this->hpol[i].exponent !='\0' && x.hpol[j].exponent !='\0'){
	    if(this->hpol[i].exponent == x.hpol[j].exponent ){
	        float z=(x.hpol[j].coefficient + this->hpol[i].coefficient);
			s.set(x.hpol[j].exponent ,z);
			i++;
			j++;
		}
		else if(this->hpol[i].exponent > x.hpol[j].exponent ) {
			s.set(this->hpol[i].exponent , this->hpol[i].coefficient);
			i++;
		}
		else if(this->hpol[i].exponent < x.hpol[j].exponent ){
			s.set(x.hpol[j].exponent ,x.hpol[j].coefficient);
			j++;
		}	    
	}
	for(;this->hpol[i].exponent !='\0';i++)
	    s.set(this->hpol[i].exponent , this->hpol[i].coefficient);
	for(;x.hpol[j].exponent !='\0';j++)
	    s.set(x.hpol[j].exponent , x.hpol[j].coefficient); 
		   
	return s;
}

polynomial::polynomial(int n){
	number = n >0 ? n : 0;
}
polynomial ::polynomial(){
	number=0;
	hpol[mm].exponent='\0';
	hpol[mm].coefficient='\0';
}
void polynomial::giveExponent(){
	int i;
	for (i=1;i<=number ;i++){ 
		cout<<endl<<"enter exponent of polynomial.exponent should not be equal. ";
        cin>>hpol[i].exponent;
	}
}
void polynomial::giveCoefficient(){
	int i;
	for(i=1;i<=number;i++){
		cout<<endl<<"enter coefficient of polynomial: ";
		cin>>hpol[i].coefficient;
	}
}
void polynomial::sort(){
	int i,j,t;
	float tcc;
	for(i=1;i<number;i++){
		for(j=i;j<=number;j++){
		    if(hpol[i].exponent < hpol[j].exponent){
		    	t= hpol[i].exponent ;
			    hpol[i].exponent = hpol[j].exponent;
			    hpol[j].exponent = t;
	
			    tcc= hpol[i].coefficient ;
			    hpol[i].coefficient= hpol[j].coefficient;
			    hpol[j].coefficient= tcc;
		    }    
	    }
	}
}

polynomial polynomial:: operator- (polynomial &x){
	polynomial s(mm);//fellan
	int i=1,j=1;
	polynomial::index=0;
	x.sort();
	this->sort();
	while(this->hpol[i].exponent !='\0' && x.hpol[j].exponent !='\0'){
	    if(this->hpol[i].exponent == x.hpol[j].exponent ){
	        float z=(this->hpol[i].coefficient - x.hpol[j].coefficient);
			s.set(x.hpol[j].exponent ,z);
			i++;
			j++;
		}
		else if(this->hpol[i].exponent > x.hpol[j].exponent ) {
			s.set(this->hpol[i].exponent , this->hpol[i].coefficient);
			i++;
		}
		else if(this->hpol[i].exponent < x.hpol[j].exponent ){
			s.set(x.hpol[j].exponent ,x.hpol[j].coefficient);
			j++;
		}	    
	}
	for(;this->hpol[i].exponent !='\0';i++)
	    s.set(this->hpol[i].exponent , this->hpol[i].coefficient);
	for(;x.hpol[j].exponent !='\0';j++)
	    s.set(x.hpol[j].exponent , x.hpol[j].coefficient);

	return s;
}

polynomial polynomial:: operator* (polynomial &x){
	polynomial s(2*mm);//fellan
	int i=1,j=1;
	polynomial::index=0;
	for(i=1;this->hpol[i].exponent !='\0';i++)
	    for(j=1;x.hpol[j].exponent !='\0';j++){
	        int z=(this->hpol[i].exponent + x.hpol[j].exponent);
	        float a=(this->hpol[i].coefficient * x.hpol[j].coefficient );
		    s.set(z, a);
        }

	return s;
}

void polynomial::set(int &ex , float &co){
	index++;
	this->hpol[index].exponent = ex;
	this->hpol[index].coefficient = co;
}
void polynomial::print(){
	int i,j;
	cout<<endl<<"Polynomial = ";
	for(i=1; i< number ;i++){
		cout<<hpol[i].coefficient<<"x^ "<<hpol[i].exponent<<" + ";
	}
	if(i== number) 
	    cout<<hpol[i].coefficient <<"x^ "<<hpol[i].exponent;
}


main(){
		

	
	polynomial p1(3);
	p1.giveCoefficient();
	p1.giveExponent();
	p1.print();
	cout<<p1.retriveExponent();
	cout<<p1.retriveCoefficient();
	
	polynomial p2(2);
	p2.giveCoefficient();
	p2.giveExponent();
	p2.print();
	cout<<p2.retriveExponent();
	cout<<p2.retriveCoefficient();

	polynomial p3,p4, p5;
	
	p3 = p1 + p2;
	cout<<endl<<"sum polynomial: ";p3.print();
	
	p4 = p1 - p2;
	cout<<endl<<"subtract polynomial: ";p4.print();
	
	p5=p1 * p2;
	cout<<endl<<"polynomial multiply: ";p5.print();
}


